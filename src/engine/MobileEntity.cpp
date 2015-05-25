#include "MobileEntity.h"
#include "Engine.h"
#include <iostream>

namespace Egn {

const float MobileEntity::DEFAULT_SPEED = 100.f;

void
MobileEntity::move( float secs ) {
    Engine * e = getEngine();
    if ( e ) {
        e->physics()->moveEntity( this, secs );
    }
}

}
