#ifndef EGN_SPRITE_H_
#define EGN_SPRITE_H_

#include <list>
#include <memory>
#include <SFML/Graphics.hpp>

namespace Egn {

typedef std::shared_ptr< sf::Shape > ShapePtr;

class Sprite {
public:
    typedef std::shared_ptr< Sprite > Ptr;

    Sprite( const sf::Vector2f & offset );

    void addShape( ShapePtr shape );

    const sf::RenderStates & getRenderStates() const { return renderStates_; }

    const std::list< ShapePtr > & shapes() const { return shapes_; };
private:
    std::list< ShapePtr > shapes_;
    sf::RenderStates renderStates_;
};

}

#endif
