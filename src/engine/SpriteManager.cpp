#include "SpriteManager.h"
#include <memory>

namespace Egn {

SpriteManager::SpriteManager() : sprites_() {}

Sprite::Ptr
SpriteManager::getSprite( const std::string & key ) {
    return sprites_[ key ];
}

Sprite::Ptr
SpriteManager::newSprite( const std::string & key ) {
    Sprite::Ptr sprite = std::make_shared< Sprite >( sf::Vector2f( 0.f, 0.f ) );
    sprites_[ key ] = sprite;
    return sprite;
}

}
