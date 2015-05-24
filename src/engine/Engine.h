#ifndef EGN_ENGINE_H_
#define EGN_ENGINE_H_

#include <functional>
#include <SFML/Graphics.hpp>
#include "Entity.h"
#include "PhysicsEngine.h"
#include "Renderer.h"
#include "SpriteManager.h"
#include "EntityRegistry.h"

namespace Egn {
class Engine {
public:
    Engine( int windowH, int windowW, const sf::String & title );

    ~Engine();

    // No copying
    Engine( const Engine &) = delete;
    Engine & operator=( const Engine & ) = delete;

    void setFramerateLimit( unsigned int limit );

    void setEventHandler( std::function< void ( sf::Event ) > handler ) {
        eventHandler_ = handler; };

    void setOnDrawCallback( std::function< void ( float ) > cb ) {
        drawCallback_ = cb; };

    void loop();

    void registerEntity( Entity * entity );

    PhysicsEngine * physics() { return physEng_; };

    SpriteManager * spriteManager() { return &spriteManager_; }

private:
    EntityRegistry entityRegistry_;
    SpriteManager spriteManager_;

    sf::RenderWindow window_;
    std::function< void ( sf::Event ) > eventHandler_;
    std::function< void ( float ) > drawCallback_;

    PhysicsEngine * physEng_;
    Renderer * renderer_;
};

}

#endif
