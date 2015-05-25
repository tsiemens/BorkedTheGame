#include "PhysicsMesh.h"

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

sf::Rect< float >
PhysicsMesh::createRect( const sf::Vector2f & pos ) const {
    return sf::Rect< float >( pos, rectSize_ );
}

}
