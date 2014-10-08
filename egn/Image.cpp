#include "Image.hpp"


egn::Image::Image()
{
    //ctor
}

egn::Image::~Image()
{
    //dtor
}

bool egn::Image::loadFromFile( const std::string& file )
{
    return m_Image.loadFromFile( file );
}

void egn::Image::setMask( egn::Color color )
{
    m_Image.createMaskFromColor( color );
}

sf::Image& egn::Image::get()
{
    return m_Image;
}


