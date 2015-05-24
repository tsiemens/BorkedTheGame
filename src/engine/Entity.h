#include "Sprite.h"
#include <SFML/Graphics.hpp>

namespace Egn {

class Entity {
public:
    Entity( const Sprite * sprite );

    const sf::Vector2f & getPosition() const { return this->position_; }

    void setPosition( const sf::Vector2f & pos ) { this->position_ = pos; }

    const Sprite * getSprite() const { return this->sprite_; }

    sf::RenderStates getRenderStates() const;

    void move( const sf::Vector2f moveVec );

private:
   const Sprite * sprite_;
   sf::Vector2f position_;
};

}
