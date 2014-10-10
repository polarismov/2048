#include "Sprite.hpp"



egn::Sprite::Sprite()
{
    //ctor
}

egn::Sprite::~Sprite()
{
    //dtor
}

void egn::Sprite::setFocus( egn::IntRect rect )
{
    m_Sprite.setTextureRect( rect );
}

void egn::Sprite::setTexture( egn::Texture& texture )
{
    m_Sprite.setTexture( texture.get() );
}

void egn::Sprite::setPosition( egn::Vector2f position )
{
    m_Sprite.setPosition( position.x, position.y );
}

void egn::Sprite::setScale( float x, float y )
{
	m_Sprite.setScale( x, y );
}

void egn::Sprite::scale( float x, float y )
{
	m_Sprite.scale( x, y );
}

sf::Sprite& egn::Sprite::get()
{
    return m_Sprite;
}


