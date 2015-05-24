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
        entity->setPosition(
                entity->getPosition() + ( move ) );
    }
}

}
