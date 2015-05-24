#include "Sprite.h"

namespace Egn {

Sprite::Sprite( const sf::Vector2f & offset ) {
    sf::Transform t( sf::Transform::Identity );
    t = t.translate( offset );
    renderStates_.transform = t;
}

void
Sprite::addShape( ShapePtr shape ) {
    shapes_.push_back( shape );
}

}
