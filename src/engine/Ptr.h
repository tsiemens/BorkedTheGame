#ifndef EGN_PTR_H_
#define EGN_PTR_H_

#include <memory>
#include <SFML/Graphics.hpp>

namespace Egn {

typedef std::shared_ptr< sf::Drawable > DrawablePtr;
typedef std::shared_ptr< sf::Shape > ShapePtr;
typedef std::shared_ptr< sf::Text > TextPtr;

}

#endif
