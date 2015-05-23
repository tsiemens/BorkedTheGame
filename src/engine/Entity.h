#include "Sprite.h"
#include <SFML/Graphics.hpp>

namespace Egn {

class Entity {
public:
    Entity( const Sprite * sprite );

    const sf::Vector2f & getPosition() const { return this->_position; }

    const Sprite * getSprite() const { return this->_sprite; }

private:
   const Sprite * _sprite;
   sf::Vector2f _position;
};

}
