#include <list>
#include <functional>
#include <SFML/Graphics.hpp>
#include "Entity.h"

namespace Egn {

class Engine {
public:
    Engine( int windowH, int windowW, const sf::String & title );

    void setFramerateLimit( unsigned int limit );

    void addEntity( Entity * entity );

    void setEventHandler( std::function< void ( sf::Event ) > handler ) {
        eventHandler_ = handler; };

    void setOnDrawCallback( std::function< void ( float ) > cb ) {
        drawCallback_ = cb; };

    void loop();

private:
    void drawEntities();

    sf::RenderWindow window_;
    std::list< Entity * > entities_;
    std::function< void ( sf::Event ) > eventHandler_;
    std::function< void ( float ) > drawCallback_;
};

}
