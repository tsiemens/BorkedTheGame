#include "PhysicsMesh.h"
#include <cmath>
#include <iostream>

namespace Egn {

bool
PhysicsMesh::contains( const sf::Vector2f & meshPos, const sf::Vector2f & point ) {
    return createRect( meshPos ).contains( point );
}

bool
PhysicsMesh::intersects( const sf::Vector2f & meshPos, const PhysicsMesh & otherMesh,
                         const sf::Vector2f & otherPos ) {
    return createRect( meshPos ).intersects( otherMesh.createRect( otherPos ) );
}


float
PhysicsMesh::collisionAngle( const sf::Vector2f & meshPos, const PhysicsMesh & otherMesh,
                          const sf::Vector2f & otherPos ) {

    // find collision surfaces
    if ( meshPos.y + rectSize_.y <= otherPos.y ) {
        // bottom collision
        return M_PI / 2;
    } if ( meshPos.x + rectSize_.x >= otherPos.x ) {
        // right side collision
        return 0;
    } else if ( meshPos.x <= otherPos.x + otherMesh.rectSize_.x ) {
        // left side collision
        return M_PI;
    } else if ( meshPos.y >= otherPos.y + otherMesh.rectSize_.y ) {
        // top collision
        return M_PI / -2;
    }

    // The meshes somehow overlapped. Bounce out from centre
    return collisionAngleFromCentre( meshPos, otherMesh, otherPos );
}

float
PhysicsMesh::collisionAngleFromCentre( const sf::Vector2f & meshPos, const PhysicsMesh & otherMesh,
                          const sf::Vector2f & otherPos ) {

    sf::Vector2f centre1( meshPos.x + ( rectSize_.x / 2 ), meshPos.y + ( rectSize_.y / 2 ) );
    sf::Vector2f centre2( otherPos.x + ( otherMesh.rectSize_.x / 2 ),
                          otherPos.y + ( otherMesh.rectSize_.y / 2 ) );
    float diffX = centre1.x - centre2.x;
    float diffY = centre1.y - centre2.y;

    std::cout << "Performing collision angle from centre" << std::endl;
    if ( std::abs( diffX ) > std::abs( diffY ) ) {
        // Left/right collision
        if ( diffX < 0 ) {
            // Right collision
            return 0;
        } else {
            return M_PI;
        }
    } else {
        // Up/down collision
        if ( diffY < 0 ) {
            // bottom collision
            return M_PI / 2;
        } else {
            return M_PI + M_PI / 2;
        }
    }
}

sf::Rect< float >
PhysicsMesh::createRect( const sf::Vector2f & pos ) const {
    return sf::Rect< float >( pos, rectSize_ );
}

}
