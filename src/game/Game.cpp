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
    entityFactory_ = new EntityFactory( & engine_, spriteFactory_ );
}

void
Game::start() {
    sf::Vector2f squareSize( 100.f, 100.f );

    Egn::Sprite::Ptr playerSprite = spriteFactory_
        ->makeRectSprite( "player_sprite", squareSize, sf::Color::Green );
    this->player_ = new Player( playerSprite, squareSize );
    this->player_->setPosition( sf::Vector2f( 100, 0 ) );
    engine_.registerEntity( this->player_ );

    entityFactory_->makeWorld();

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

            this->player_->pressedUp =  sf::Keyboard::isKeyPressed( sf::Keyboard::Key::W );
            this->player_->pressedDown =  sf::Keyboard::isKeyPressed( sf::Keyboard::Key::S );
            this->player_->pressedLeft =  sf::Keyboard::isKeyPressed( sf::Keyboard::Key::A );
            this->player_->pressedRight =  sf::Keyboard::isKeyPressed( sf::Keyboard::Key::D );
        }
    }
}

void
Game::onFrame( float secondsSinceLastFrame ) {
    this->debugText_->setString( "fps: " + std::to_string( 1.f / secondsSinceLastFrame ) );

    float xForce = ( this->player_->pressedRight ? 1.f : 0.f ) +
                   ( this->player_->pressedLeft ? -1.f : 0.f );
    this->engine_.physics()->applyForce( this->player_, secondsSinceLastFrame,
            sf::Vector2f( xForce * 1000, 0 ) );

    // Jump
    if ( this->player_->pressedUp &&
         this->engine_.physics()->checkTouchingBottom( this->player_ ) ) {

        this->player_->setYSpeed( -500 );
    }
}

}
