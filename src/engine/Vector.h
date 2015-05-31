#ifndef EGN_VECTOR_H_
#define EGN_VECTOR_H_

#include <SFML/Graphics.hpp>

namespace Egn {

sf::Vector2f rotate( const sf::Vector2f & v, float radians );

std::ostream& operator<<(std::ostream& os, const sf::Vector2f & v);

}

#endif
