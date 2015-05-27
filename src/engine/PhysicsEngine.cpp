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

        sf::Vector2f newPos( entity->getPosition() + ( move ) );

        // TODO for now, just bail if there are collisions
        const std::list< Entity * > & entities = entityRegistry_->getEntities();
        for ( auto i = entities.begin(); i != entities.end(); i++ ) {
            if ( * i != entity && ( * i )->intersectsMesh( entity->getPhysicsMesh(), newPos ) ) {
                entity->setSpeed( sf::Vector2f( 0, 0 ) );
                return;
            }
        }

        entity->setPosition(
                entity->getPosition() + ( move ) );
    }
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
