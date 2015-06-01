#include "Entity.h"
#include "Engine.h"
#include "Vector.h"
#include <iostream>

namespace Egn {

Entity::Entity() : Entity( Sprite::Ptr() ) {}

Entity::Entity( Sprite::Ptr sprite )
    : Entity( sprite, sf::Vector2f(0.f, 0.f) ) {}

Entity::Entity( Sprite::Ptr sprite, sf::Vector2f meshSize )
    :  physMesh_( meshSize ), canMove_( false ) {
    sprite_ = sprite;
    speed_ = sf::Vector2f( 0, 0 );
}

sf::RenderStates
Entity::getRenderStates() const {
    sf::RenderStates rs = sprite_->getRenderStates();
    return rs.transform.translate( position_ );
}

bool
Entity::intersectsMesh( const PhysicsMesh & mesh, const sf::Vector2f meshPos ) const {
    return physMesh_.intersects( position_, mesh, meshPos );
}

float
Entity::collisionAngleWithEntity( const Entity * entity ) const {
    return physMesh_.collisionAngle( position_, entity->physMesh_, entity->position_ );
}

void
Entity::move( float secs ) {
    if ( canMove_ ) {
        Engine * e = getEngine();
        if ( e ) {
            e->physics()->moveEntity( this, secs );
        }
    }
}

}
