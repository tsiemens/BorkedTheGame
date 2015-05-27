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

    float getXSpeed() const { return speed_.x; }
    float getYSpeed() const { return speed_.y; }

    const sf::Vector2f & getSpeed() const { return speed_; }

    void setXSpeed( float m ) { speed_.x = m; }
    void setYSpeed( float m ) { speed_.y = m; }

    void setSpeed( const sf::Vector2f & speed ) { speed_ = speed; }

    float getMass() const { return mass_; }

    void move( float secs );
private:
    sf::Vector2f speed_;

    float mass_ = 1.f;
};

}

#endif
