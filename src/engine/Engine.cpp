#include <iostream>
#include <ctime>
#include <chrono>
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
    std::cout << "Cleaning up Egn::Engine" << std::endl;
    delete physEng_;
    delete renderer_;
}

void
Engine::setFramerateLimit( unsigned int limit ) {
    window_.setFramerateLimit( limit );
}

void
Engine::loop() {
    std::chrono::high_resolution_clock::time_point beginTime =
        std::chrono::high_resolution_clock::now();
    while ( window_.isOpen() ) {
        sf::Event event;
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

        std::chrono::high_resolution_clock::time_point endTime =
            std::chrono::high_resolution_clock::now();
        std::chrono::duration< double > dur =
            std::chrono::duration_cast< std::chrono::duration< double > >( endTime - beginTime );
        beginTime = endTime;

        float seconds = ( float ) dur.count();
        physEng_->applyFramePhysics( seconds );
        drawCallback_( seconds );
    }
}

void
Engine::registerEntity( Entity * entity ) {
    entityRegistry_.registerEntity( entity );
    entity->engine_ = this;
}

}
