#include "PhysicsEngine.h"
#include "engine/Vector.h"
#include <cmath>
#include <iostream>

namespace Egn {

const float PhysicsEngine::DEFAULT_GRAVITY = 900.f;

PhysicsEngine::PhysicsEngine( EntityRegistry * registry )
    : entityRegistry_( registry ) {}

void
PhysicsEngine::moveEntity( Entity * entity, float secs ) {
    if ( ! entity->canMove() || ! entityRegistry_->isRegistered( entity ) ) return;

    // Ths first bit is cheating a bit at trig
    sf::Vector2f move( entity->getXSpeed(), entity->getYSpeed() );
    move *= secs * world_.speedFactor;

    sf::Vector2f newPos( entity->getPosition() + move );
    sf::Vector2f newXOnlyPos( entity->getPosition() + sf::Vector2f( move.x, 0 ) );
    sf::Vector2f newYOnlyPos( entity->getPosition() + sf::Vector2f( 0, move.y ) );

    // TODO for now, just bail if there are collisions
    bool canMoveX = true;
    bool canMoveY = true;
    sf::Vector2f adjustedSpeed = entity->getSpeed();

    const std::list< Entity * > & entities = entityRegistry_->getEntities();
    for ( auto i = entities.begin(); i != entities.end(); i++ ) {
        if ( * i != entity && ( * i )->intersectsMesh( entity->getPhysicsMesh(), newPos ) ) {

            collide( entity, * i );
            // Can we slide at least?
            if ( canMoveX &&
                    ( * i )->intersectsMesh( entity->getPhysicsMesh(), newXOnlyPos ) ) {
                canMoveX = false;
                adjustedSpeed.x = 0;
            } else if ( canMoveY &&
                    ( * i )->intersectsMesh( entity->getPhysicsMesh(), newYOnlyPos ) ) {
                canMoveY = false;
                adjustedSpeed.y = 0;
            } else {
                entity->setSpeed( sf::Vector2f( 0, 0 ) );
                return;
            }
        }
    }

    if ( canMoveX && canMoveY ) {
        entity->setPosition( newPos );
    } else if ( canMoveX ) {
        entity->setPosition( newXOnlyPos );
    } else if ( canMoveY ) {
        entity->setPosition( newYOnlyPos );
    }
}

bool
PhysicsEngine::checkTouchingBottom( Entity * entity ) {
    // If the player is within 3 points of the top of another entity, they are 'touching'
    sf::Vector2f lowerPos = entity->getPosition() + sf::Vector2f( 0, 3.f );

    const std::list< Entity * > & entities = entityRegistry_->getEntities();
    for ( auto i = entities.begin(); i != entities.end(); i++ ) {
        if ( * i != entity && ( * i )->intersectsMesh( entity->getPhysicsMesh(), lowerPos ) ) {
            return true;
        }
    }
    return false;
}

void
PhysicsEngine::accelerate( Entity * entity, float secs, const sf::Vector2f & accelV ) {
    entity->setSpeed( entity->getSpeed() + sf::Vector2f( accelV * secs ) );
}

void
PhysicsEngine::applyForce( Entity * entity, float secs, const sf::Vector2f & forceV ) {
    // Acceleration = Force / mass
    accelerate( entity, secs, forceV / entity->getMass() );
}

// FOR COLLISIONS:
// Preserve momentum p. p = m * v
// http://www.hoomanr.com/Demos/Elastic2/
// also multiply final velocities with (product?) of elastic coeficiants

void
PhysicsEngine::collide( Entity * e1, Entity * e2 ) {
    sf::Vector2f pos1 = e1->getPosition();
    sf::Vector2f pos2 = e2->getPosition();
    // Collision angle
    float A = e1->collisionAngleWithEntity( e2 );

    // Re-aligned velocities
    sf::Vector2f v1 = rotate( e1->getSpeed(), A );
    sf::Vector2f v2 = rotate( e2->getSpeed(), A );

    float m1 = e1->getMass();
    float m2 = e2->getMass();

    float fv1x;
    float fv2x;
    if ( ! e1->canMove() ) {
        fv1x = 0;
        fv2x = -v2.x;
    } else if ( ! e2->canMove() ) {
        fv1x = -v1.x;
        fv2x = 0;
    } else {
        fv1x = ( ( m1 - m2 ) * v1.x + ( 2 * m2 * v2.x ) ) / ( m1 + m2 );
        fv2x = ( ( 2 * m1 * v1.x ) - ( ( m1 - m2 ) * v2.x ) ) / ( m1 + m2 );
    }

    float damping = ( 1.f - e1->getCollisionDamping() ) * ( 1.f - e2->getCollisionDamping() );
    sf::Vector2f realV1 = rotate( sf::Vector2f( fv1x * damping, v1.y ), -A );
    sf::Vector2f realV2 = rotate( sf::Vector2f( fv2x * damping, v2.y ), -A );

    e1->setSpeed( realV1 );
    e2->setSpeed( realV2 );
}

void
PhysicsEngine::moveAllMobileEntities( float secs ) {
    doOnAllEntities( [ this, secs ] ( Entity * entity ) {
        this->moveEntity( entity, secs );
    } );
}


void
PhysicsEngine::doOnAllEntities( std::function< void ( Entity * entity ) > func ) {
    const std::list< Entity * > & entities = entityRegistry_->getEntities();
    for ( auto i = entities.begin(); i != entities.end(); i++ ) {
        Entity * e = *i;
        func( e );
    }
}


void
PhysicsEngine::applyFramePhysics( float secs ) {
    sf::Vector2f gravityAccel( 0.f, world_.gravityAccel );
    doOnAllEntities( [ this, secs, gravityAccel ] ( Entity * entity ) {
        this->accelerate( entity, secs, gravityAccel );
        this->moveEntity( entity, secs );
    } );
}

}
