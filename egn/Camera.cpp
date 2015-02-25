#include "Camera.hpp"

#include "GameTime.hpp"

#include <iostream>



egn::Camera::Camera(egn::FloatRect position)
{
    m_View.reset( position );
    m_RenderWindowPtr = 0;
    m_Position = position;
    setLimit( position );
}

egn::Camera::Camera()
{
    m_RenderWindowPtr = 0;
}

egn::Camera::~Camera()
{
    //dtor
}

void egn::Camera::setRenderWindowPtr( sf::RenderWindow* rw )
{
    m_RenderWindowPtr = rw;
}

void egn::Camera::copy( egn::Camera& camera )
{
    m_Position = camera.getPosition();
    m_View.reset( m_Position );
}

void egn::Camera::move( float x, float y )
{
    m_Position.left += x * egn::GameTime::getElapsedTime();
    m_Position.top += y * egn::GameTime::getElapsedTime();
    m_View.setCenter( m_Position.left + m_Position.width / 2, m_Position.top + m_Position.height / 2 );
    m_RenderWindowPtr->setView( m_View );
}

void egn::Camera::adjust()
{

    if( m_Position.left < m_Limit.left ) m_Position.left = m_Limit.left;

    if( m_Position.top < m_Limit.top ) m_Position.top = m_Limit.top;

    if( m_Position.left + m_Position.width > m_Limit.left + m_Limit.width ) m_Position.left = m_Limit.left + m_Limit.width - m_Position.width;

    if( m_Position.top + m_Position.height > m_Limit.top + m_Limit.height ) m_Position.top = m_Limit.top + m_Limit.height - m_Position.height;

    m_View.setCenter( m_Position.left + m_Position.width / 2, m_Position.top + m_Position.height / 2 );
    m_RenderWindowPtr->setView( m_View );
}

void egn::Camera::setLimit( egn::FloatRect position )
{
    m_Limit = position;
}

egn::FloatRect egn::Camera::getPosition() const
{
    return m_Position;
}

void egn::Camera::actualize()
{
    if( m_RenderWindowPtr != 0 ) m_RenderWindowPtr->setView( m_View );
}

void egn::Camera::setFocus( egn::Vector2f position )
{
    m_Position.left = position.x - m_Position.width / 2;
    m_Position.top = position.y - m_Position.height / 2;

	m_View.setCenter( position );
	m_RenderWindowPtr->setView( m_View );
	adjust();
}


