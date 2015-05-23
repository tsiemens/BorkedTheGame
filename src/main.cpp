#include <SFML/Graphics.hpp>
#include "Engine.h"

int main() {
    Egn::Engine engine( 800, 500, "My Game" );
    engine.setFramerateLimit( 60 );

    sf::CircleShape shape( 100.f );
    shape.setFillColor( sf::Color::Green );

    Egn::Sprite circleSprite( sf::Vector2f( 50.f, -90.f ) );
    circleSprite.addShape( & shape );
    Egn::Entity circleEntity( & circleSprite );

    engine.addEntity( & circleEntity );

    engine.loop();

    return 0;
}
