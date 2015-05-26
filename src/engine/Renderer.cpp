#include "Renderer.h"

namespace Egn {

Renderer::Renderer( EntityRegistry * registry, sf::RenderWindow * window )
    : entityRegistry_( registry ), window_( window ) {

}

void
Renderer::renderEntities() {
    const std::list< Entity * > & entities = entityRegistry_->getEntities();
    for ( auto enti = entities.begin(); enti != entities.end(); enti++ ) {

        sf::RenderStates renderStates = (*enti)->getRenderStates();
        std::list< DrawablePtr > drawables = (*enti)->getSprite()->getDrawables();
        for ( auto drawi = drawables.begin(); drawi != drawables.end(); drawi++ ) {
            window_->draw( **drawi, renderStates );
        }
    }
}

}
