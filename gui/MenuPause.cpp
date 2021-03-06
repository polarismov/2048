#include "MenuPause.hpp"

#include "../egn/TextureManager.hpp"
#include "../egn/FontManager.hpp"
#include "../egn/Keyboard.hpp"

#include "../GameState.hpp"

gui::MenuPause::MenuPause()
{
	m_Cursor = 0;
	m_Button[0].setTexture( egn::TextureManager::get()->getTexture( "data/image/button1.png", egn::Color::White ) );
	m_Button[1].setTexture( egn::TextureManager::get()->getTexture( "data/image/button2.png", egn::Color::White ) ); 
	
	m_Continue = false;
}

gui::MenuPause::~MenuPause()
{
	//dtor
}

void gui::MenuPause::update()
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
			GameState::set( GameState::previous() );
			break;

			case 2:
			GameState::set( Gamestate::MENU_START );
			break;

			case 3:
			if( m_Continue ) GameState::set( Gamestate::MENU_WIN );
			else GameState::set( Gamestate::EXIT );
			break;
		}

		egn::Keyboard::setActive( "return", false );
	}
}

void gui::MenuPause::draw( egn::Window& window )
{
	window.drawRect( egn::FloatRect( 0, 0, 800, 600 ), egn::Color( 0, 0, 0, 180 ) );
	egn::FontManager::get()->write( window, "shoes", "Jeu en pause", egn::Vector2f( 230, 60 ), 50, egn::Color::Black );

	/* reprendre */
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
	egn::FontManager::get()->write( window, "shoes", "Reprendre", egn::Vector2f( 310, 212 ), 30, egn::Color::Black );
	/* fin reprendre */

	/* recommencer */
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
	egn::FontManager::get()->write( window, "shoes", "Recommencer", egn::Vector2f( 285, 282 ), 30, egn::Color::Black );
	/* fin recommencer */

	/* menu principal */
	m_Button[0].setPosition( egn::Vector2f( 250, 350 ) );
	m_Button[1].setPosition( egn::Vector2f( 250, 350 ) );
	if( m_Cursor == 2 )
	{
		window.draw( m_Button[1] );
	}
	else 
	{
		window.draw( m_Button[0] );
	}
	egn::FontManager::get()->write( window, "shoes", "Menu Principal", egn::Vector2f( 270, 352 ), 30, egn::Color::Black );
	/* fin menu principal */

	/* quitter */
	m_Button[0].setPosition( egn::Vector2f( 250, 420 ) );
	m_Button[1].setPosition( egn::Vector2f( 250, 420 ) );
	if( m_Cursor == 3 )
	{
		window.draw( m_Button[1] );
	}
	else 
	{
		window.draw( m_Button[0] );
	}
	if( m_Continue ) 
	{
		egn::FontManager::get()->write( window, "shoes", "Quit save score", egn::Vector2f( 260, 422 ), 30, egn::Color::Black );
	}
	else 
	{
		egn::FontManager::get()->write( window, "shoes", "Quitter", egn::Vector2f( 330, 422 ), 30, egn::Color::Black );
	}
	
	/* fin quitter */
}

void gui::MenuPause::set( const std::string& var, std::string value )
{
	//
}

void gui::MenuPause::set( const std::string& var, int value )
{
	if( var == "continue" ) 
	{
		m_Continue = value;
	}
}

void gui::MenuPause::set( const std::string& var, bool value )
{
	if( var == "continue" ) 
	{
		m_Continue = value;
	}
}

void gui::MenuPause::updateCursor( int value )
{
	m_Cursor += value;
	if( m_Cursor < 0 ) m_Cursor = 3;
	if( m_Cursor > 3 ) m_Cursor = 0;
}
