#include <iostream>
#include <ctime>
#include <list>
#include "Engine.h"

namespace Egn {

Engine::Engine( int windowH, int windowW, const sf::String & title )
    : window_( sf::VideoMode( windowH, windowW ), title,
               sf::Style::Titlebar | sf::Style::Close ) {

    physEng_ = new PhysicsEngine( & entityRegistry_ );
    renderer_ = new Renderer( & entityRegistry_, & window_ );
}

Engine::~Engine() {
    delete physEng_;
    delete renderer_;
}

void
Engine::setFramerateLimit( unsigned int limit ) {
    window_.setFramerateLimit( limit );
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
        renderer_->renderEntities();
        window_.display();

        float duration = float( clock() - beginTime ) /  CLOCKS_PER_SEC;
        beginTime = std::clock();
        drawCallback_( duration );
    }
}

void
Engine::registerEntity( Entity * entity ) {
    entityRegistry_.registerEntity( entity );
    entity->engine_ = this;
}

}
