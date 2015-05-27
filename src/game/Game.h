#ifndef BORK_GAME_H_
#define BORK_GAME_H_

#include <string>
#include "engine/Engine.h"
#include "Player.h"
#include "SpriteFactory.h"
#include "EntityFactory.h"

namespace Bork {

class Game {
public:
    Game( const std::string binDir );

    void start();

    void handleEvent( sf::Event event );
    void onFrame( float secondsSinceLastFrame );

private:
    Egn::Engine engine_;

    SpriteFactory * spriteFactory_;
    EntityFactory * entityFactory_;

    Egn::TextPtr debugText_;
    Player * player_;
};

}

#endif
