#include "MobileEntity.h"
#include "Engine.h"

namespace Egn {

const float MobileEntity::DEFAULT_SPEED = 25.f;

MobileEntity::MobileEntity( Sprite::Ptr sprite )
    : Entity( sprite ) {
}

void
MobileEntity::move( float secs ) {
    Engine * e = getEngine();
    if ( e ) {
        e->physics()->moveEntity( this, secs );
    }
}

}
