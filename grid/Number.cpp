#include "Number.hpp"

#include "../egn/FontManager.hpp"
#include "../egn/GameTime.hpp"

#include <iostream>
#include <sstream>


grid::Number::Number( int value, egn::FloatRect position ) : m_Position( position ), m_NextPosition( position )
{
	m_Value = value;
	m_InMove = false;
}

grid::Number::~Number()
{
	//dtor
}

void grid::Number::set( int value )
{
	m_Value = value;
}

int grid::Number::get()
{
	return m_Value;
}

void grid::Number::draw( egn::Window& window )
{
	egn::Color color;
	if( m_Value > 0 ) color = egn::Color::Yellow;
	window.drawRect( m_Position, color );


	std::ostringstream oss;
	oss << m_Value;

	if( m_Value < 10 )
	{
		egn::FontManager::get()->write( window, "shoes", oss.str(), egn::Vector2f( m_Position.left + 15, m_Position.top + 15 ), 30, egn::Color::Black );
	} 
	else if( m_Value < 100 )
	{
		egn::FontManager::get()->write( window, "shoes", oss.str(), egn::Vector2f( m_Position.left + 7, m_Position.top + 15 ), 30, egn::Color::Black );
	}
	else if( m_Value < 1000 )
	{
		egn::FontManager::get()->write( window, "shoes", oss.str(), egn::Vector2f( m_Position.left + 2, m_Position.top + 15 ), 25, egn::Color::Black );
	}
	else 
	{
		egn::FontManager::get()->write( window, "shoes", oss.str(), egn::Vector2f( m_Position.left + 0, m_Position.top + 15 ), 20, egn::Color::Black );
	}

	
}

void grid::Number::update()
{
	if( m_InMove )
	{
		egn::Vector2f velocity = egn::Vector2f( 0, 0 );
		switch( m_Direction )
		{
			case DIR_UP:
			velocity.y -= 1000 * egn::GameTime::getElapsedTime();
			m_Position.top += velocity.y;
			if( m_Position.top < m_NextPosition.top )
			{
				m_Position.top = m_NextPosition.top;
				m_InMove = false;
			}
			break;

			case DIR_DOWN:
			break;

			case DIR_LEFT:
			break;

			case DIR_RIGHT:
			break;
		}
	}
}

ref grid::Number::getRef()
{
	return m_NextVectorIndex;
}

void grid::Number::move( DIR direction, ref next_vector_index )
{
	m_InMove = true;
	m_Direction = direction;
	m_NextVectorIndex = next_vector_index;
}

bool grid::Number::inMove()
{
	return m_InMove;
}

egn::FloatRect grid::Number::getPosition() 
{
	return m_Position;
}

egn::FloatRect grid::Number::getStartPosition()
{
	return m_NextPosition;
}

void grid::Number::setPosition( egn::FloatRect rect )
{
	m_Position = rect;
}

void grid::Number::setNextPosition( egn::FloatRect rect )
{
	m_NextPosition = rect;
}