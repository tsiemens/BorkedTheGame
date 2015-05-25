#include "PhysicsEngine.h"
#include <iostream>

namespace Egn {

PhysicsEngine::PhysicsEngine( EntityRegistry * registry )
    : entityRegistry_( registry ) {}

void
PhysicsEngine::moveEntity( MobileEntity * entity, float secs ) {
    if (entityRegistry_->isRegistered( entity )) {
        // Ths first bit is cheating a bit at trig
        sf::Vector2f move( entity->getXMovement(), entity->getYMovement() );
        move *= secs * MobileEntity::DEFAULT_SPEED;

        sf::Vector2f newPos( entity->getPosition() + ( move ) );

        // TODO for now, just bail if there are collisions
        const std::list< Entity * > & entities = entityRegistry_->getEntities();
        for ( auto i = entities.begin(); i != entities.end(); i++ ) {
            if ( *i != entity && (*i)->intersectsMesh( entity->getPhysicsMesh(), newPos ) ) {
                return;
            }
        }

        entity->setPosition(
                entity->getPosition() + ( move ) );
    }
}

}
