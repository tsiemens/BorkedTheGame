#ifndef EGN_SPRITE_H_
#define EGN_SPRITE_H_

#include <list>
#include <memory>
#include <SFML/Graphics.hpp>
#include "Ptr.h"

namespace Egn {

class Sprite {
public:
    typedef std::shared_ptr< Sprite > Ptr;

    Sprite( const sf::Vector2f & offset );

    void addDrawable( DrawablePtr shape );

    const sf::RenderStates & getRenderStates() const { return renderStates_; }

    const std::list< DrawablePtr > & getDrawables() const { return drawables_; };
private:
    std::list< DrawablePtr > drawables_;
    sf::RenderStates renderStates_;
};

}

#endif
