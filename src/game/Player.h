#ifndef BORK_PLAYER_H_
#define BORK_PLAYER_H_

#include "engine/Entity.h"
#include <SFML/Graphics.hpp>

namespace Bork {

class Player : public Egn::Entity {
public:
    Player( Egn::Sprite::Ptr sprite, sf::Vector2f meshSize );

    bool pressedLeft = false;
    bool pressedRight = false;
    bool pressedUp = false;
    bool pressedDown = false;
private:
};

}

#endif
