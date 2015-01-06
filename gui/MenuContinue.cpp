#include "MenuContinue.hpp"

#include <sstream>

#include "../egn/TextureManager.hpp"
#include "../egn/FontManager.hpp"
#include "../egn/Keyboard.hpp"

#include "../GameState.hpp"
#include "../DataManager.hpp"


gui::MenuContinue::MenuContinue()
{
	m_Cursor = 0;
	m_Button[0].setTexture( egn::TextureManager::get()->getTexture( "data/image/button1.png", egn::Color::White ) );
	m_Button[1].setTexture( egn::TextureManager::get()->getTexture( "data/image/button2.png", egn::Color::White ) ); 
}

gui::MenuContinue::~MenuContinue()
{
	//dtor
}

void gui::MenuContinue::update()
{
	if( egn::Keyboard::isActive( "up" ) )
	{
		updateCursor( -1 );
		egn::Keyboard::setActive( "up", false );
	}
	else if( egn::Keyboard::isActive( "down" ) )
	{
		updateCursor( 1 );
		egn::Keyboard::setActive( "down", false );
	}

	if( egn::Keyboard::isActive( "return" ) )
	{
		switch( m_Cursor )
		{
			case 0:
			GameState::set( Gamestate::PLAY );
			break;

			case 1:
			GameState::set( Gamestate::MENU_WIN );
			break;
			
		}
		
		egn::Keyboard::setActive( "return", false );
	}
}
void gui::MenuContinue::draw( egn::Window& window )
{
	window.drawRect( egn::FloatRect( 0, 0, 800, 600 ), egn::Color( 0, 0, 0, 180 ) );
	egn::FontManager::get()->write( window, "shoes", "Continue", egn::Vector2f( 230, 60 ), 50, egn::Color::Black );

	/* oui menu play*/
	m_Button[0].setPosition( egn::Vector2f( 250, 210 ) );
	m_Button[1].setPosition( egn::Vector2f( 250, 210 ) );
	if( m_Cursor == 0 )
	{
		window.draw( m_Button[1] );
	}
	else 
	{
		window.draw( m_Button[0] );
	}
	egn::FontManager::get()->write( window, "shoes", "oui", egn::Vector2f( 310, 218 ), 30, egn::Color::Black );
	/* fin oui */

	/* non menu win*/
	m_Button[0].setPosition( egn::Vector2f( 250, 280 ) );
	m_Button[1].setPosition( egn::Vector2f( 250, 280 ) );
	if( m_Cursor == 1 )
	{
		window.draw( m_Button[1] );
	}
	else 
	{
		window.draw( m_Button[0] );
	}
	egn::FontManager::get()->write( window, "shoes", "non", egn::Vector2f( 285, 288 ), 30, egn::Color::Black );
	/* fin non */

}

void gui::MenuContinue::updateCursor( int value )
{
	m_Cursor += value;
	if( m_Cursor < 0 ) m_Cursor = 2;
	if( m_Cursor > 2 ) m_Cursor = 0;
}
