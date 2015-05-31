#include "Player.h"
#include <iostream>

namespace Bork {

Player::Player( Egn::Sprite::Ptr sprite, sf::Vector2f meshSize )
    : Egn::Entity( sprite, meshSize ) {

    setCanMove( true );
    setCollisionDamping( 0.5f );
}

}
