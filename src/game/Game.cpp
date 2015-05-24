#include "Game.h"
#include <iostream>

namespace Bork {

Game::Game() : engine_( 800, 500, "Borked: The Game" ) {
    engine_.setFramerateLimit( 60 );
    engine_.setEventHandler( [ this ] ( sf::Event event ) {
            this->handleEvent( event );
        } );
    engine_.setOnDrawCallback( [ this ] ( float secs ) {
            this->onFrame( secs );
        } );
}

void
Game::start() {
    sf::CircleShape shape( 100.f );
    shape.setFillColor( sf::Color::Green );

    Egn::Sprite circleSprite( sf::Vector2f( 50.f, -90.f ) );
    circleSprite.addShape( & shape );
    Egn::Entity circleEntity( & circleSprite );
    this->circle_ = &circleEntity;

    engine_.addEntity( & circleEntity );

    engine_.loop();
}

void
Game::handleEvent( sf::Event event ) {
    this->circle_->move( sf::Vector2f( -1.f, 0.f ) );
}

void
Game::onFrame( float secondsSinceLastFrame ) {
    this->circle_->move( sf::Vector2f( 1.f, 0.f ) );
}

}
