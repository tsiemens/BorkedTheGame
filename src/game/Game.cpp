#include "Game.h"
#include <iostream>
#include <memory>
#include "Player.h"

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
    sf::RectangleShape * shape = new sf::RectangleShape( sf::Vector2f( 100.f, 100.f ) );
    shape->setFillColor( sf::Color::Green );

    Egn::Sprite::Ptr sprite = engine_.spriteManager()->newSprite( "player_sprite" );
    sprite->addShape( Egn::ShapePtr( shape ) );

    this->player_ = new Player( sprite );

    engine_.registerEntity( this->player_ );

    engine_.loop();
}

void
Game::handleEvent( sf::Event event ) {
    if ( event.type == sf::Event::KeyPressed ||
         event.type == sf::Event::KeyReleased ) {
        if ( event.key.code == sf::Keyboard::Key::W ||
             event.key.code == sf::Keyboard::Key::A ||
             event.key.code == sf::Keyboard::Key::S ||
             event.key.code == sf::Keyboard::Key::D ) {

            float y = sf::Keyboard::isKeyPressed( sf::Keyboard::Key::W ) ? -1.f : 0.f +
                     sf::Keyboard::isKeyPressed( sf::Keyboard::Key::S ) ? 1.f : 0.f;
            float x = sf::Keyboard::isKeyPressed( sf::Keyboard::Key::A ) ? -1.f : 0.f +
                     sf::Keyboard::isKeyPressed( sf::Keyboard::Key::D ) ? 1.f : 0.f;

            this->player_->setYMovement( y );
            this->player_->setXMovement( x );
        }
    }
}

void
Game::onFrame( float secondsSinceLastFrame ) {
    this->player_->move( secondsSinceLastFrame );
}

}
