#include "EntityFactory.h"
#include <SFML/Graphics.hpp>
#include "engine/Sprite.h"

namespace Bork {

void
EntityFactory::makeWorld() {
    sf::Vector2f floorSize( 800, 50 );
    sf::Vector2f wallSize( 20, 5000 );

    Egn::Sprite::Ptr floorSprite = spriteFactory_
        ->makeRectSprite( "floor", floorSize, sf::Color::Blue );
    Egn::Sprite::Ptr wallSprite = spriteFactory_
        ->makeRectSprite( "wall", wallSize, sf::Color::Blue );

    Egn::Entity * floor = new Egn::Entity( floorSprite, floorSize );
    floor->setPosition( sf::Vector2f( 0.f, 450.f ) );
    floor->setCollisionDamping( 1.f );
    engine_->registerEntity( floor );

    Egn::Entity * wallL = new Egn::Entity( wallSprite, wallSize );
    wallL->setPosition( sf::Vector2f( 0.f, -4000.f ) );
    engine_->registerEntity( wallL );

    Egn::Entity * wallR = new Egn::Entity( wallSprite, wallSize );
    wallR->setPosition( sf::Vector2f( 780.f, -4000.f ) );
    engine_->registerEntity( wallR );
}

}
