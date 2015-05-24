#include <list>
#include <SFML/Graphics.hpp>
#include "Entity.h"

namespace Egn {

class Engine {
public:
    Engine( int windowH, int windowW, const sf::String & title );

    void setFramerateLimit( unsigned int limit );
    void addEntity( Entity * entity );
    void loop();

private:
    void drawEntities();

    sf::RenderWindow window_;
    std::list< Entity * > entities_;
};

}
