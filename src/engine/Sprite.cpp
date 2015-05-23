#include "Sprite.h"

namespace Egn {

Sprite::Sprite( const sf::Vector2f & offset ) {
    sf::Transform t( sf::Transform::Identity );
    t = t.translate( offset );
    _renderStates.transform = t;
}

void
Sprite::addShape( sf::Shape * shape ) {
    _shapes.push_back( shape );
}

const sf::RenderStates &
Sprite::getRenderStates() const {
    return _renderStates;
}

std::list< sf::Shape * >
Sprite::shapes() const {
    return _shapes;
}

}
