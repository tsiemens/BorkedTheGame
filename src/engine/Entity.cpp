#include "Entity.h"

namespace Egn {

Entity::Entity() : Entity( Sprite::Ptr() ) {}

Entity::Entity( Sprite::Ptr sprite ) : Entity( sprite, sf::Vector2f(0.f, 0.f) ) {}

Entity::Entity( Sprite::Ptr sprite, sf::Vector2f meshSize )
    :  physMesh_( meshSize ) {
    sprite_ = sprite;
}

sf::RenderStates
Entity::getRenderStates() const {
    sf::RenderStates rs = sprite_->getRenderStates();
    return rs.transform.translate( position_ );
}

bool
Entity::intersectsMesh( const PhysicsMesh & mesh, const sf::Vector2f meshPos ) {
    return physMesh_.intersects( position_, mesh, meshPos );
}

}
