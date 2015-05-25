#ifndef BORK_PLAYER_H_
#define BORK_PLAYER_H_

#include "engine/MobileEntity.h"
#include <SFML/Graphics.hpp>

namespace Bork {

class Player : public Egn::MobileEntity {
public:
    Player( Egn::Sprite::Ptr sprite, sf::Vector2f meshSize )
        : Egn::MobileEntity( sprite, meshSize ) {}

private:
};

}

#endif
