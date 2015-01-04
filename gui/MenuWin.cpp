#include "MenuWin.hpp"

#include <sstream>

#include "../egn/TextureManager.hpp"
#include "../egn/FontManager.hpp"
#include "../egn/Keyboard.hpp"

#include "../GameState.hpp"
#include "../DataManager.hpp"

gui::MenuWin::MenuWin()
{
	m_Cursor = 0;
    m_Button[0].setTexture( egn::TextureManager::get()->getTexture("data/image/button1.png", egn::Color::White) );
    m_Button[1].setTexture( egn::TextureManager::get()->getTexture("data/image/button2.png", egn::Color::White) );
    m_Score = 0;
    m_BestScore = 0;
    m_Time = 0;
    m_Pseudo = "";
}

gui::MenuWin::~MenuWin()
{

}

void gui::MenuWin::update()
{
	if ( egn::Keyboard::isActive("up") )
    {
        updateCursor(-1);
        egn::Keyboard::setActive("up", false);
    }
    else if ( egn::Keyboard::isActive("down") )
    {
        updateCursor (1);
        egn::Keyboard::setActive("down", false);
    }

    if ( egn::Keyboard::isActive("return"))
    {
        switch (m_Cursor)
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

        DataManager::get()->basic_insert_result( m_Pseudo, m_Score, m_Time );
    }
}

void gui::MenuWin::draw( egn::Window& window )
{
	egn::FontManager::get()->write(window, "shoes", "You Win",egn::Vector2f( 280, 100 ), 50, egn::Color::Black);

	std::ostringstream oss;
    oss << m_Score;
    std::string valscore = "Score: "+oss.str();
	egn::FontManager::get()->write(window, "shoes", valscore,egn::Vector2f( 300, 200 ), 20, egn::Color::Black);

	std::ostringstream oss1;
    oss1 << m_Time;
    std::string valtime = "Temps: "+oss1.str();
    egn::FontManager::get()->write(window, "shoes", valtime,egn::Vector2f( 300, 250 ), 20, egn::Color::Black);
    
    /*debut recommencer*/
    m_Button[0].setPosition( egn::Vector2f( 250, 300 ) );
    m_Button[1].setPosition( egn::Vector2f( 250, 300 ) );

    if ( m_Cursor == 0)
    {
    	window.draw( m_Button[1]);
    }
    else 
    {
    	window.draw( m_Button[0]);
    }
    egn::FontManager::get()->write(window, "shoes", "Recommencer",egn::Vector2f( 290, 308 ), 30, egn::Color::Black);
    /*fin recommencer*/

    /*debut retour*/
    m_Button[0].setPosition( egn::Vector2f (250, 370) );
    m_Button[1].setPosition( egn::Vector2f (250, 370) );
    if ( m_Cursor == 1)
    {
    	window.draw( m_Button[1]);
    }
    else 
    {
    	window.draw( m_Button[0]);
    }
    egn::FontManager::get()->write(window, "shoes", "Menu Principal",egn::Vector2f( 270, 378 ), 30, egn::Color::Black);
    /*fin retour*/

    /*debut Quitter*/
    m_Button[0].setPosition( egn::Vector2f (250, 440) );
    m_Button[1].setPosition( egn::Vector2f (250, 440) );
    if ( m_Cursor == 2)
    {
    	window.draw( m_Button[1]);
    }
    else 
    {
    	window.draw( m_Button[0]);
    }
    egn::FontManager::get()->write(window, "shoes", "Quitter",egn::Vector2f( 330, 448 ), 30, egn::Color::Black);
    /*fin quittter*/

}

void gui::MenuWin::set( const std::string& var, std::string value )
{
    if( var == "pseudo" )
    {
        m_Pseudo = value;
    }
}

void gui::MenuWin::set( const std::string& var, int value )
{
	if ( var == "score" )
	{
		m_Score = value;
        switch( GameState::previous() )
        {
            case Gamestate::SET_4X4_PLAY:
            m_Score *= 2;
            break;

            case Gamestate::SET_5X5_PLAY:
            float tmp = (float)m_Score;
            tmp *= 1.5;
            m_Score = (int)tmp;
            break;
        }
	}
	else if ( var == "bestscore")
	{
		m_BestScore = value;
	}
	else if ( var == "time")
	{
		m_Time = value;
	}
}


void gui::MenuWin::updateCursor( int value )
{
    m_Cursor += value;
    if( m_Cursor < 0 ) m_Cursor = 2;
    if( m_Cursor > 2 ) m_Cursor = 0;
}
