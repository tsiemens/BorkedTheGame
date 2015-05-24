#include "Entity.h"

namespace Egn {

Entity::Entity( const Sprite * sprite ) {
    sprite_ = sprite;
}

sf::RenderStates
Entity::getRenderStates() const {
    sf::RenderStates rs = sprite_->getRenderStates();
    return rs.transform.translate( position_ );
}

void
Entity::move( const sf::Vector2f moveVec ) {
    position_ += moveVec;
}

}
