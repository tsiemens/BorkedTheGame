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

    const sf::Vector2f & getPosition() const { return this->position_; }

    void setPosition( const sf::Vector2f & pos ) { this->position_ = pos; }

    const Sprite::Ptr getSprite() const { return this->sprite_; }

    void setSprite( Sprite::Ptr sprite ) { this->sprite_ = sprite; }

    PhysicsMesh & getPhysicsMesh() {  return this->physMesh_; }

    Engine * getEngine() const { return this->engine_; }

    sf::RenderStates getRenderStates() const;

    bool intersectsMesh( const PhysicsMesh & mesh, const sf::Vector2f meshPos );

private:
   Sprite::Ptr sprite_;
   sf::Vector2f position_;
   PhysicsMesh physMesh_;

   Engine * engine_;
};

}

#endif
