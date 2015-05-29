#include "PhysicsEngine.h"
#include <iostream>

namespace Egn {

const float PhysicsEngine::DEFAULT_GRAVITY = 900.f;

PhysicsEngine::PhysicsEngine( EntityRegistry * registry )
    : entityRegistry_( registry ) {}

void
PhysicsEngine::moveEntity( MobileEntity * entity, float secs ) {
    if (entityRegistry_->isRegistered( entity )) {
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
            entity->setSpeed( adjustedSpeed );
        } else if ( canMoveY ) {
            entity->setPosition( newYOnlyPos );
            entity->setSpeed( adjustedSpeed );
        }
    }
}

bool
PhysicsEngine::checkTouchingBottom( MobileEntity * entity ) {
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
PhysicsEngine::accelerate( MobileEntity * entity, float secs, const sf::Vector2f & accelV ) {
    entity->setSpeed( entity->getSpeed() + sf::Vector2f( accelV * secs ) );
}

void
PhysicsEngine::applyForce( MobileEntity * entity, float secs, const sf::Vector2f & forceV ) {
    // Acceleration = Force / mass
    accelerate( entity, secs, forceV / entity->getMass() );
}

void
PhysicsEngine::moveAllMobileEntities( float secs ) {
    doOnAllMobileEntities( [ this, secs ] ( MobileEntity * entity ) {
        this->moveEntity( entity, secs );
    } );
}


void
PhysicsEngine::doOnAllMobileEntities( std::function< void ( MobileEntity * entity ) > func ) {
    const std::list< Entity * > & entities = entityRegistry_->getEntities();
    for ( auto i = entities.begin(); i != entities.end(); i++ ) {
        Entity * e = *i;
        if ( dynamic_cast< MobileEntity * >( e ) ) {
            func( dynamic_cast< MobileEntity * >( e ) );
        }
    }
}


void
PhysicsEngine::applyFramePhysics( float secs ) {
    sf::Vector2f gravityAccel( 0.f, world_.gravityAccel );
    doOnAllMobileEntities( [ this, secs, gravityAccel ] ( MobileEntity * entity ) {
        this->accelerate( entity, secs, gravityAccel );
        this->moveEntity( entity, secs );
    } );
}

}
