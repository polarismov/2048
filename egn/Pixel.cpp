#include "Pixel.hpp"


void egn::Pixel::draw( egn::Window& window, egn::Vector2f position, egn::Color color )
{
    sf::RectangleShape rshape( sf::Vector2f( 1, 1 ) );
    rshape.setPosition( position.x, position.y );
    rshape.setFillColor( color );
    window.getRenderWindow().draw( rshape );
}

