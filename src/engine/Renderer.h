#ifndef EGN_RENDERER_H_
#define EGN_RENDERER_H_

#include <SFML/Graphics.hpp>
#include "EntityRegistry.h"

namespace Egn {

class Renderer {
public:
    Renderer( EntityRegistry * registry, sf::RenderWindow * window );

    void renderEntities();
private:
    EntityRegistry * entityRegistry_;
    sf::RenderWindow * window_;

};

}

#endif
