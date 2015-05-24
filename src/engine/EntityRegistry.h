#ifndef EGN_ENTITY_REGISTRY_H_
#define EGN_ENTITY_REGISTRY_H_

#include <list>
#include "Entity.h"

namespace Egn {

class EntityRegistry {
public:
    EntityRegistry();

    void registerEntity( Entity * entity );

    const std::list< Entity * > & getEntities() const { return entities_; }

    bool isRegistered( Entity * entity ) const { return true; /* TODO */ };
private:
    std::list< Entity * > entities_;

};

}

#endif
