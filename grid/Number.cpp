#include "Number.hpp"

#include "../egn/FontManager.hpp"
#include "../egn/GameTime.hpp"

#include <iostream>
#include <sstream>


grid::Number::Number( int value, egn::FloatRect position ) : m_Position( position ), m_NextPosition( position )
{
	m_Value = value;
	m_InMove = false;
	m_Draw = true;
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
	if( m_Draw )
	{
		egn::Color color;
		if( m_Value == 2 ) color = egn::Color(0xF5, 0xF6, 0xCE);
		else if ( m_Value == 4 ) color = egn::Color(0xF2, 0xF5, 0xA9);
		else if ( m_Value == 8 ) color = egn::Color(0xF3, 0xF7, 0x81);
		else if ( m_Value == 16 ) color = egn::Color(0xF4, 0xFA, 0x58);
		else if ( m_Value == 32 ) color = egn::Color(0xF7, 0xFE, 0x2E);
		else if ( m_Value == 64 ) color = egn::Color(0xFF, 0xFF, 0x00);
		else if ( m_Value == 128 ) color = egn::Color(0xFF, 0xBF, 0x00);
		else if ( m_Value == 256 ) color = egn::Color(0xFF, 0x80, 0x00);
		else if ( m_Value == 512 ) color = egn::Color(0xFF, 0x40, 0x00);
		else if ( m_Value == 1024 ) color = egn::Color(0xFF, 0x00, 0x00);
		else if ( m_Value == 2048 ) color = egn::Color(0xB4, 0x04, 0x04);
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
}

void grid::Number::setDraw( bool value )
{
	m_Draw = value;
}

void grid::Number::update()
{
	if( m_InMove )
	{
		egn::Vector2f velocity = egn::Vector2f( 0, 0 );
		switch( m_Direction )
		{
			case Direction::UP:
			velocity.y -= 1000 * egn::GameTime::getElapsedTime();
			m_Position.top += velocity.y;
			if( m_Position.top < m_NextPosition.top )
			{
				m_Position.top = m_NextPosition.top;
				m_InMove = false;
			}
			break;

			case Direction::DOWN:
			velocity.y += 1000 * egn::GameTime::getElapsedTime();
			m_Position.top += velocity.y;
			if( m_Position.top > m_NextPosition.top )
			{
				m_Position.top = m_NextPosition.top;
				m_InMove = false;
			}
			break;

			case Direction::LEFT:
			velocity.x -= 1000 * egn::GameTime::getElapsedTime();
			m_Position.left += velocity.x;
			if( m_Position.left < m_NextPosition.left )
			{
				m_Position.left = m_NextPosition.left;
				m_InMove = false;
			}
			break;

			case Direction::RIGHT:
			velocity.x += 1000 * egn::GameTime::getElapsedTime();
			m_Position.left += velocity.x;
			if( m_Position.left > m_NextPosition.left )
			{
				m_Position.left = m_NextPosition.left;
				m_InMove = false;
			}
			break;
		}
	}
}

ref grid::Number::getRef()
{
	return m_NextVectorIndex;
}

void grid::Number::move( Direction direction, ref next_vector_index )
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
