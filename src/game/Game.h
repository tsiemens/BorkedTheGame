#ifndef BORK_GAME_H_
#define BORK_GAME_H_

#include "engine/Engine.h"
#include "Player.h"

namespace Bork {

class Game {
public:
    Game();

    void start();

    void handleEvent( sf::Event event );
    void onFrame( float secondsSinceLastFrame );

private:
    Egn::Engine engine_;

    Player * player_;
};

}

#endif
