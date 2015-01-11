#include "ChallengeLose.hpp"

#include "../egn/TextureManager.hpp"
#include "../egn/FontManager.hpp"
#include "../egn/Keyboard.hpp"

#include "../GameState.hpp"

#include <sstream>

gui::ChallengeLose::ChallengeLose()
{
	m_Button[0].setTexture( egn::TextureManager::get()->getTexture( "data/image/button1.png", egn::Color::White ) );
	m_Button[1].setTexture( egn::TextureManager::get()->getTexture( "data/image/button2.png", egn::Color::White ) );

	m_Cursor = 0;
}

gui::ChallengeLose::~ChallengeLose()
{
	//dtor
}

void gui::ChallengeLose::update()
{
	if( egn::Keyboard::isActive("up") )
	{
		updateCursor( -1 );
		egn::Keyboard::setActive( "up", false );
	}
	else if( egn::Keyboard::isActive("down") )
	{
		updateCursor( 1 );
		egn::Keyboard::setActive( "down", false );
	}

	if( egn::Keyboard::isActive("return") )
	{
		switch( m_Cursor )
		{
			case 0:
			GameState::set( GameState::previous() );
			break;

			case 1:
			GameState::set( Gamestate::MENU_START );
			break;

			case 2:
			GameState::set( Gamestate::EXIT );
			break;
		}

		egn::Keyboard::setActive( "return", false );
	}
}

void gui::ChallengeLose::draw( egn::Window& window )
{
	egn::FontManager::get()->write( window, "shoes", "Game Over!", egn::Vector2f( 260, 100 ), 50, egn::Color::Black );

	/* button recommencer */
	m_Button[0].setPosition( egn::Vector2f( 250, 300 ) );
	m_Button[1].setPosition( egn::Vector2f( 250, 300 ) );
	if( m_Cursor == 0 )
	{
		window.draw( m_Button[1] );
	}
	else 
	{
		window.draw( m_Button[0] );
	}
	egn::FontManager::get()->write( window, "shoes", "Recommencer", egn::Vector2f( 290, 302 ), 30, egn::Color::Black );
	/* fin recommencer */

	/* button retour au menu */
	m_Button[0].setPosition( egn::Vector2f( 250, 370 ) );
	m_Button[1].setPosition( egn::Vector2f( 250, 370 ) );
	if( m_Cursor == 1 )
	{
		window.draw( m_Button[1] );
	}
	else 
	{
		window.draw( m_Button[0] );
	}
	egn::FontManager::get()->write( window, "shoes", "Retour au menu", egn::Vector2f( 270, 372 ), 30, egn::Color::Black );
	/* fin retour au menu */

	/* button quitter */
	m_Button[0].setPosition( egn::Vector2f( 250, 440 ) );
	m_Button[1].setPosition( egn::Vector2f( 250, 440 ) );
	if( m_Cursor == 2 )
	{
		window.draw( m_Button[1] );
	}
	else 
	{
		window.draw( m_Button[0] );
	}
	egn::FontManager::get()->write( window, "shoes", "Quitter", egn::Vector2f( 330, 442 ), 30, egn::Color::Black );
	/* fin quitter */
}

void gui::ChallengeLose::set( const std::string& var, std::string value )
{
	//set
}

void gui::ChallengeLose::set( const std::string& var, int value )
{
	//set
}

void gui::ChallengeLose::updateCursor( int value )
{
	m_Cursor += value;
	if( m_Cursor < 0 ) m_Cursor = 2;
	if( m_Cursor > 2 ) m_Cursor = 0;
}
