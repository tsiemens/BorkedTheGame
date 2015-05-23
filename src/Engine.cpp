#include <iostream>
#include "Engine.h"

namespace Egn {

Engine::Engine( int windowH, int windowW, const sf::String & title)
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
Engine::loop() {
    while ( window_.isOpen() ) {
        sf::Event event;
        while ( window_.pollEvent( event ) ) {
            if ( event.type == sf::Event::Closed ) {
                window_.close();
            }

            window_.clear();

            for ( auto enti = entities_.begin(); enti != entities_.end(); enti++ ) {
                sf::RenderStates renderStates = (*enti)->getSprite()->getRenderStates();
                std::list< sf::Shape * > shapes = (*enti)->getSprite()->shapes();
                for ( auto shi = shapes.begin(); shi != shapes.end(); shi++ ) {
                    window_.draw( **shi, renderStates );
                }
            }

            window_.display();
        }
    }
}

}
