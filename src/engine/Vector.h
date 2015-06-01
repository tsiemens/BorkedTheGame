#ifndef EGN_VECTOR_H_
#define EGN_VECTOR_H_

#include <SFML/Graphics.hpp>

namespace Egn {

float length( const sf::Vector2f & v );

sf::Vector2f rotate( const sf::Vector2f & v, float radians );

bool doIntersect( const sf::Vector2f & l1a, const sf::Vector2f & l1b,
                  const sf::Vector2f & l2a, const sf::Vector2f & l2b,
                  sf::Vector2f & intersectioResult );

std::ostream& operator<<(std::ostream& os, const sf::Vector2f & v);

}

#endif
