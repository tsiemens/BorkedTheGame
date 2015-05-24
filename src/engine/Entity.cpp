#include "Entity.h"

namespace Egn {

Entity::Entity() {
}

Entity::Entity( Sprite::Ptr sprite ) {
    sprite_ = sprite;
}

sf::RenderStates
Entity::getRenderStates() const {
    sf::RenderStates rs = sprite_->getRenderStates();
    return rs.transform.translate( position_ );
}

}
