#include <list>
#include <iterator>
#include <SFML/Graphics.hpp>

namespace Egn {

class Sprite {
public:
    Sprite( const sf::Vector2f & offset );

    void addShape( sf::Shape * shape );

    const sf::RenderStates & getRenderStates() const;

    std::list< sf::Shape * > shapes() const;
private:
    std::list< sf::Shape * > _shapes;
    sf::RenderStates _renderStates;
};

}
