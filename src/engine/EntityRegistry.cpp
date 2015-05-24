#include "EntityRegistry.h"

namespace Egn {

EntityRegistry::EntityRegistry() : entities_() {

}

void
EntityRegistry::registerEntity( Entity * entity ) {
    entities_.push_back( entity );
}

}
