#ifndef BORK_SPRITE_FACTORY_H_
#define BORK_SPRITE_FACTORY_H_

#include <string>
#include <SFML/Graphics.hpp>
#include "engine/Engine.h"
#include "engine/Sprite.h"

namespace Bork {

class SpriteFactory {
public:
    SpriteFactory( Egn::Engine * engine, std::string binDir );

    Egn::Sprite::Ptr makeRectSprite( const std::string & key, const sf::Vector2f & size,
        const sf::Color & color );

    Egn::Sprite::Ptr makeSprite( const std::string & key, Egn::DrawablePtr drawable );

    Egn::TextPtr makeText( const sf::String & text, unsigned int size );

    Egn::Sprite::Ptr makeTextSprite( const std::string & key, const sf::String & text,
            unsigned int size=30 );
private:
    sf::Font * font_;

    Egn::Engine * engine_;

};

}

#endif
