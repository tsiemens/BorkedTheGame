#include "Vector.h"
#include <cmath>
#include <iostream>

namespace Egn {

sf::Vector2f rotate( const sf::Vector2f & v, float radians ) {
    float sin = std::sin( radians );
    float cos = std::cos( radians );

    float tx = v.x;
    float ty = v.y;

    return sf::Vector2f ( ( cos * tx ) - ( sin * ty ),  ( sin * tx ) + ( cos * ty ) );
}

std::ostream& operator<<(std::ostream& os, const sf::Vector2f & v) {
    return os << "<" << v.x << ", " << v.y << ">";
}

}
