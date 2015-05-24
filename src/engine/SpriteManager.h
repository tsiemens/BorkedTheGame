#ifndef EGN_SPRITE_MANAGER_H_
#define EGN_SPRITE_MANAGER_H_

#include <unordered_map>
#include <string>
#include "Sprite.h"

namespace Egn {

class SpriteManager {
public:
    SpriteManager();

    Sprite::Ptr getSprite( const std::string & key );

    Sprite::Ptr newSprite( const std::string & key );

private:
    std::unordered_map< std::string, Sprite::Ptr > sprites_;
};

}

#endif
