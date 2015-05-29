#ifndef EGN_PHYSICS_ENGINE_H_
#define EGN_PHYSICS_ENGINE_H_

#include <SFML/Graphics.hpp>
#include "EntityRegistry.h"
#include "MobileEntity.h"

namespace Egn {

class PhysicsEngine {
public:
    static const float DEFAULT_GRAVITY;

    typedef struct WorldPhysics {
        float speedFactor = 1.f;
        float gravityAccel = DEFAULT_GRAVITY;
    } WorldPhysics;

    PhysicsEngine( EntityRegistry * registry );

    WorldPhysics * getWorld() { return &world_; };

    // Moves the entity in the direction specified by vec.
    // The distance travelled is affected by a multiplication of the duration secs
    // and the magnitude of vec
    void moveEntity( MobileEntity * entity, float secs );

    bool checkTouchingBottom( MobileEntity * entity );

    void accelerate( MobileEntity * entity, float secs, const sf::Vector2f & accelV );

    void applyForce( MobileEntity * entity, float secs, const sf::Vector2f & forceV );

    void moveAllMobileEntities( float secs );

    void doOnAllMobileEntities( std::function< void ( MobileEntity * entity ) > func );

    void applyFramePhysics( float secs );

private:
    WorldPhysics world_;
    const EntityRegistry * entityRegistry_;
};

}

#endif
