#include "engine/Engine.h"

namespace Bork {

class Game {
public:
    Game();

    void start();

    void handleEvent( sf::Event event );
    void onFrame( float secondsSinceLastFrame );

private:
    Egn::Engine engine_;

    Egn::Entity * circle_;
};

}
