#include "game/Game.h"
#include <string>

std::string getBinDir( char * arg ) {
    std::string::size_type pos = std::string( arg ).find_last_of( "/" );
    return std::string( arg ).substr( 0, pos + 1 );
}

int main( int argc, char * argv[] ) {
    Bork::Game game( getBinDir( argv[ 0 ] ) );
    game.start();

    return 0;
}
