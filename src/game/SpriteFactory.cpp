#include "SpriteFactory.h"
#include <memory>

namespace Bork {

SpriteFactory::SpriteFactory( Egn::Engine * engine, std::string binDir ) : engine_( engine ) {
    font_ = new sf::Font();
    font_->loadFromFile( binDir + "../fonts/DroidSans.ttf" );
}

Egn::Sprite::Ptr
SpriteFactory::makeRectSprite( const std::string & key, const sf::Vector2f & size,
        const sf::Color & color ) {

    sf::RectangleShape * shape = new sf::RectangleShape( size );
    shape->setFillColor( color );

    Egn::Sprite::Ptr sprite = engine_->spriteManager()->newSprite( key );
    sprite->addDrawable( Egn::DrawablePtr( shape ) );
    return sprite;
}


Egn::Sprite::Ptr
SpriteFactory::makeSprite( const std::string & key, Egn::DrawablePtr drawable ) {
    Egn::Sprite::Ptr sprite = engine_->spriteManager()->newSprite( key );
    sprite->addDrawable( drawable );
    return sprite;
}

Egn::TextPtr
SpriteFactory::makeText( const sf::String & text, unsigned int size ) {
    sf::Text * textDraw = new sf::Text( text, *font_, size );
    return Egn::TextPtr( textDraw );
}

Egn::Sprite::Ptr
SpriteFactory::makeTextSprite( const std::string & key, const sf::String & text,
        unsigned int size ) {
    sf::Text * textDraw = new sf::Text( text, *font_, size );

    Egn::Sprite::Ptr sprite = engine_->spriteManager()->newSprite( key );
    sprite->addDrawable( Egn::DrawablePtr( textDraw ) );
    return sprite;
}

}
