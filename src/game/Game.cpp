#include "Game.h"
#include <iostream>
#include <memory>
#include "Player.h"

namespace Bork {

Game::Game( const std::string binDir ) : engine_( 800, 500, "Borked: The Game" ) {
    engine_.setFramerateLimit( 60 );
    engine_.setEventHandler( [ this ] ( sf::Event event ) {
            this->handleEvent( event );
        } );
    engine_.setOnDrawCallback( [ this ] ( float secs ) {
            this->onFrame( secs );
        } );

    spriteFactory_ = new SpriteFactory( & engine_, binDir );
}

void
Game::start() {
    sf::Vector2f squareSize( 100.f, 100.f );

    Egn::Sprite::Ptr playerSprite = spriteFactory_
        ->makeRectSprite( "player_sprite", squareSize, sf::Color::Green );
    this->player_ = new Player( playerSprite, squareSize );
    engine_.registerEntity( this->player_ );


    Egn::Sprite::Ptr oSprite = spriteFactory_
        ->makeRectSprite("obstacle_sprite", squareSize, sf::Color::Blue );

    Egn::Entity * other = new Egn::Entity( oSprite, squareSize );
    other->setPosition( sf::Vector2f( 500.f, 400.f ) );
    engine_.registerEntity( other );


    debugText_ = spriteFactory_->makeText( "Debug", 16 );
    Egn::Sprite::Ptr textSprite = spriteFactory_->makeSprite( "debug",
            std::dynamic_pointer_cast< sf::Drawable >( debugText_ ) );

    Egn::Entity * text = new Egn::Entity( textSprite );
    engine_.registerEntity( text );

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
    this->debugText_->setString( "fps: " + std::to_string( 1.f / secondsSinceLastFrame ) );
}

}
