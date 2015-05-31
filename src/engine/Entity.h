#ifndef EGN_ENTITY_H_
#define EGN_ENTITY_H_

#include "Sprite.h"
#include <SFML/Graphics.hpp>
#include "PhysicsMesh.h"

namespace Egn {
// Avoid cycles
class Engine;

class Entity {
    friend class Engine;

public:
    Entity();
    Entity( Sprite::Ptr sprite );
    Entity( Sprite::Ptr sprite, sf::Vector2f meshSize );

    // Ploymorphic type
    virtual ~Entity() {}

    const sf::Vector2f & getPosition() const { return this->position_; }

    void setPosition( const sf::Vector2f & pos ) { this->position_ = pos; }

    const Sprite::Ptr getSprite() const { return this->sprite_; }

    void setSprite( Sprite::Ptr sprite ) { this->sprite_ = sprite; }

    PhysicsMesh & getPhysicsMesh() {  return this->physMesh_; }

    Engine * getEngine() const { return this->engine_; }

    sf::RenderStates getRenderStates() const;

    bool intersectsMesh( const PhysicsMesh & mesh, const sf::Vector2f meshPos );

    float collisionAngleWithEntity( const Entity * entity );

    void setCanMove( bool canMove ) { canMove_ = canMove; }
    bool canMove() { return canMove_; }

    float getXSpeed() const { return speed_.x; }
    float getYSpeed() const { return speed_.y; }

    const sf::Vector2f & getSpeed() const { return speed_; }

    void setXSpeed( float m ) { if ( canMove_ ) speed_.x = m; }
    void setYSpeed( float m ) { if ( canMove_ ) speed_.y = m; }

    void setSpeed( const sf::Vector2f & speed ) { if ( canMove_ ) speed_ = speed; }

    float getMass() const { return mass_; }
    void setMass( float mass ) { mass_ = mass; }

    float getCollisionDamping() const { return collisionDamping_; }
    void setCollisionDamping( float damping ) { collisionDamping_ = damping; }

    void move( float secs );
private:
    Sprite::Ptr sprite_;
    sf::Vector2f position_;
    PhysicsMesh physMesh_;

    bool canMove_;
    sf::Vector2f speed_;
    float mass_ = 1.f;
    float collisionDamping_ = 0.f;

    Engine * engine_;
};

}

#endif
