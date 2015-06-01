#include "Vector.h"
#include <cmath>
#include <iostream>

namespace Egn {

float length( const sf::Vector2f & v ) {
    return std::sqrt( std::pow( v.x, 2 ) + std::pow( v.y, 2 ) );
}

sf::Vector2f rotate( const sf::Vector2f & v, float radians ) {
    float sin = std::sin( radians );
    float cos = std::cos( radians );

    float tx = v.x;
    float ty = v.y;

    return sf::Vector2f ( ( cos * tx ) - ( sin * ty ),  ( sin * tx ) + ( cos * ty ) );
}

// Checks if the lines formed by the 4 points intersetct.
// If so, intersectionResult is loaded with the intersection point
bool doIntersect( const sf::Vector2f & l1a, const sf::Vector2f & l1b,
                  const sf::Vector2f & l2a, const sf::Vector2f & l2b,
                  sf::Vector2f & intersectionResult ) {

    float d = (l1a.x - l1b.x) * (l2a.y - l2b.y) - (l1a.y - l1b.y) * (l2a.x - l2b.x);
    // If d is zero, there is no intersection
    if (d == 0) return false;

    // Get the x and y
    float pre = l1a.x * l1b.y - l1a.y * l1b.x;
    float post = l2a.x * l2b.y - l2a.y * l2b.x;
    float x = ( pre * (l2a.x - l2b.x) - (l1a.x - l1b.x) * post ) / d;
    float y = ( pre * (l2a.y - l2b.y) - (l1a.y - l1b.y) * post ) / d;

    // Check if the x and y coordinates are within both lines
    if ( x < std::min(l1a.x, l1b.x) || x > std::max(l1a.x, l1b.x) ||
            x < std::min(l2a.x, l2b.x) || x > std::max(l2a.x, l2b.x) )
        return false;
    if ( y < std::min(l1a.y, l1b.y) || y > std::max(l1a.y, l1b.y) ||
            y < std::min(l2a.y, l2b.y) || y > std::max(l2a.y, l2b.y) )
        return false;

    intersectionResult.x = x;
    intersectionResult.y = y;
    return true;
}

std::ostream& operator<<(std::ostream& os, const sf::Vector2f & v) {
    return os << "<" << v.x << ", " << v.y << ">";
}

}
