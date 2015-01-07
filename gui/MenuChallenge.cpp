#include "MenuChallenge.hpp"

#include <sstream>

#include "../egn/TextureManager.hpp"
#include "../egn/FontManager.hpp"
#include "../egn/Keyboard.hpp"

#include "../GameState.hpp"
#include "../DataManager.hpp"
#include "../Challenge.hpp"

gui::MenuChallenge::MenuChallenge()
{
	m_Cursor = 0;
	m_Button[0].setTexture( egn::TextureManager::get()->getTexture( "data/image/button1.png", egn::Color::White ) );
	m_Button[1].setTexture( egn::TextureManager::get()->getTexture( "data/image/button2.png", egn::Color::White ) );

}

gui::MenuChallenge::~MenuChallenge()
{
	//dtor
}

void gui::MenuChallenge::update()
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

	if ( egn::keyboard::isActive( "left") )
	{
		updateCursorHorizontale( -1 );
		egn::keyboard::setActive( "left", false );
	}
	else if ( egn::keyboard::isActive( "right") )
	{
		updateCursorHorizontale( 1 );
		egn::keyboard::setActive( "right", false );
	}

}
Challenge challenge = DataManager::get()->basic_get_challenge_list().at(m_CursorH);

void gui::MenuChallenge::draw( egn::Window& window )
{
	int score = 0;

	Challenge challenge = DataManager::get()->basic_get_challenge_list().at(m_CursorH);

	window.drawRect( egn::FloatRect( 0, 0, 800, 600 ), egn::Color( 0, 0, 0, 180 ) );
	egn::FontManager::get()->write( window, "shoes", "Challenge", egn::Vector2f( 255, 60 ), 50, egn::Color::Black );

	if ( egn::Keyboard::isActive("return"))
	{
			switch( challenge.getType() )
		{	
			case ChallengeType::SCORE_TIME:
			score = challenge.getScore()
			break;

			case 0:
            GameState::set( Gamestate::MENU_START );
            break;

		}
		egn::Keyboard::setActive( "return", false );
	}

	m_Button[0].setPosition( egn::Vector2f( 250, 430 ) );
    m_Button[1].setPosition( egn::Vector2f( 250, 430 ) );
    if( m_Cursor == 0 )
    {
        window.draw( m_Button[1] );
    }
    else 
    {
        window.draw( m_Button[0] );
    }
    egn::FontManager::get()->write( window, "shoes", "Retour", egn::Vector2f( 340, 432 ), 30, egn::Color::Black );

}

void gui::MenuChallenge::updateCursor( int value )
{
	m_Cursor += value;
	if( m_Cursor < 0 ) m_Cursor = 1;
	if( m_Cursor > 1 ) m_Cursor = 0;
}

void gui::MenuChallenge::updateCursorHorizontal( int value )
{
	m_CursorH += value;
	if( m_CursorH < 0 ) m_CursorH = DataManager::get()->basic_get_challenge_list().size() - 1;
	if( m_CursorH > DataManager::get()->basic_get_challenge_list().size() - 1 ) m_CursorH = 0;
}
