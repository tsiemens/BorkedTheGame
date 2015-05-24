#include <iostream>
#include <ctime>
#include "Engine.h"

namespace Egn {

Engine::Engine( int windowH, int windowW, const sf::String & title )
    : entities_()
    , window_( sf::VideoMode( windowH, windowW ), title,
               sf::Style::Titlebar | sf::Style::Close ) {

}

void
Engine::setFramerateLimit( unsigned int limit ) {
    window_.setFramerateLimit( limit );
}

void
Engine::addEntity( Entity * entity ) {
    entities_.push_back( entity );
}

void
Engine::drawEntities() {
    for ( auto enti = entities_.begin(); enti != entities_.end(); enti++ ) {

        sf::RenderStates renderStates = (*enti)->getRenderStates();
        std::list< sf::Shape * > shapes = (*enti)->getSprite()->shapes();
        for ( auto shi = shapes.begin(); shi != shapes.end(); shi++ ) {
            window_.draw( **shi, renderStates );
        }
    }
}

void
Engine::loop() {
    std::clock_t beginTime = std::clock();
    while ( window_.isOpen() ) {
        sf::Event event;
        std::clock_t beginTime = std::clock();
        while ( window_.pollEvent( event ) ) {
            if ( event.type == sf::Event::Closed ) {
                window_.close();
            } else {
                eventHandler_( event );
            }
        }

        window_.clear();
        drawEntities();
        window_.display();

        float duration = float( clock() - beginTime ) /  CLOCKS_PER_SEC;
        beginTime = std::clock();
        drawCallback_( duration );
    }
}

}
