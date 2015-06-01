#ifndef EGN_PHYSICS_ENGINE_H_
#define EGN_PHYSICS_ENGINE_H_

#include <SFML/Graphics.hpp>
#include "EntityRegistry.h"
#include "Entity.h"

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
    void moveEntity( Entity * entity, float secs );

    sf::Vector2f findFurthestMove( const Entity * entity, const Entity * entity2,
       const sf::Vector2f & maxMove );

    bool checkTouchingBottom( Entity * entity );

    void accelerate( Entity * entity, float secs, const sf::Vector2f & accelV );

    void applyForce( Entity * entity, float secs, const sf::Vector2f & forceV );

    void collide( Entity * e1, Entity * e2 );

    void moveAllMobileEntities( float secs );

    void doOnAllEntities( std::function< void ( Entity * entity ) > func );

    void applyFramePhysics( float secs );

private:
    WorldPhysics world_;
    const EntityRegistry * entityRegistry_;
};

}

#endif
