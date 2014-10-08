#include "Texture.hpp"



egn::Texture::Texture()
{
    //ctor
}

egn::Texture::~Texture()
{
    //dtor
}

bool egn::Texture::loadFromFile( const std::string& file )
{
    return m_Texture.loadFromFile( file );
}

bool egn::Texture::loadFromImage( egn::Image& image )
{
    return m_Texture.loadFromImage( image.get() );
}

sf::Texture& egn::Texture::get()
{
    return m_Texture;
}


