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
        std::list< ShapePtr > shapes = (*enti)->getSprite()->shapes();
        for ( auto shi = shapes.begin(); shi != shapes.end(); shi++ ) {
            window_->draw( **shi, renderStates );
        }
    }
}

}
