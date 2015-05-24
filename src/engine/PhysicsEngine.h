#ifndef EGN_PHYSICS_ENGINE_H_
#define EGN_PHYSICS_ENGINE_H_

#include <SFML/Graphics.hpp>
#include "EntityRegistry.h"
#include "MobileEntity.h"

namespace Egn {

class PhysicsEngine {
public:
    typedef struct WorldPhysics {
        float speedFactor = 1.f;
    } WorldPhysics;

    PhysicsEngine( EntityRegistry * registry );

    WorldPhysics * getWorld() { return &world_; };

    // Moves the entity in the direction specified by vec.
    // The distance travelled is affected by a multiplication of the duration secs
    // and the magnitude of vec
    void moveEntity( MobileEntity * entity, float secs );

private:
    WorldPhysics world_;
    const EntityRegistry * entityRegistry_;
};

}

#endif
