#ifndef EGN_MOBILE_ENTITY_H_
#define EGN_MOBILE_ENTITY_H_

#include "Entity.h"
#include <SFML/Graphics.hpp>

namespace Egn {

class MobileEntity : public Entity {
public:
    static const float DEFAULT_SPEED;

    MobileEntity( Sprite::Ptr sprite ) : Entity( sprite ) {}
    MobileEntity( Sprite::Ptr sprite, sf::Vector2f meshSize ) : Entity( sprite, meshSize ) {}

    float getXMovement() const { return xMove_; }
    float getYMovement() const { return yMove_; }

    void setXMovement( float m ) { xMove_ = m; }
    void setYMovement( float m ) { yMove_ = m; }
    void move( float secs );
private:
    float xMove_ = 0.f;
    float yMove_ = 0.f;

};

}

#endif
