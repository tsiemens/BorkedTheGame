#ifndef BORK_ENTITY_FACTORY_H_
#define BORK_ENTITY_FACTORY_H_

#include <string>
#include "engine/Engine.h"
#include "SpriteFactory.h"

namespace Bork {

class EntityFactory {
public:
    EntityFactory( Egn::Engine * engine, SpriteFactory * spriteFactory )
        : engine_( engine ), spriteFactory_( spriteFactory ) {}

    void makeWorld();
private:
    Egn::Engine * engine_;
    SpriteFactory * spriteFactory_;

};

}

#endif
