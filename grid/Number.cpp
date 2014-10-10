#include "Number.hpp"

#include "../egn/FontManager.hpp"

#include <iostream>
#include <sstream>


grid::Number::Number( int value, egn::FloatRect position ) : m_Position( position ), m_StartPosition( position )
{
	m_Value = value;
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

egn::FloatRect grid::Number::getPosition() 
{
	return m_Position;
}

egn::FloatRect grid::Number::getStartPosition()
{
	return m_StartPosition;
}