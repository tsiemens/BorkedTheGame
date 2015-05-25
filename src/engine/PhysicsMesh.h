#ifndef EGN_PHYSICS_MESH_H_
#define EGN_PHYSICS_MESH_H_

#include <memory>
#include <SFML/Graphics.hpp>

namespace Egn {

// A physics collition utility. Will eventually be extended to
// represent shapes other than rectangles
class PhysicsMesh {
public:
    PhysicsMesh( const sf::Vector2f size )
        : rectSize_( size ) {};

    bool contains( const sf::Vector2f & meshPos, const sf::Vector2f & point );

    bool intersects( const sf::Vector2f & meshPos, const PhysicsMesh & otherMesh,
                     const sf::Vector2f & otherPos );

private:
    sf::Rect< float > createRect( const sf::Vector2f & pos ) const;

    sf::Vector2f rectSize_;

};

}

#endif
