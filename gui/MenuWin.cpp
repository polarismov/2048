#include "MenuWin.hpp"

#include <sstream>

#include "../egn/TextureManager.hpp"
#include "../egn/FontManager.hpp"
#include "../egn/Keyboard.hpp"

#include "../GameState.hpp"

gui::MenuWin::MenuWin()
{
	m_Cursor = 0;
    m_Button[0].setTexture( egn::TextureManager::get()->getTexture("data/image/button1.png", egn::Color::White) );
    m_Button[1].setTexture( egn::TextureManager::get()->getTexture("data/image/button2.png", egn::Color::White) );
    m_Score = 0;
    m_BestScore = 0;
    m_Time = 0;
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

            break;

            case 1:
            GameState::set( GS_MENU_START );
            break;

            case 2:
            GameState::set( GS_EXIT );
            break;
        }
        egn::Keyboard::setActive( "return", false );
    }
}

void gui::MenuWin::draw( egn::Window& window )
{
	egn::FontManager::get()->write(window, "shoes", "YOU WIN",egn::Vector2f( 260, 100 ), 50, egn::Color::Black);

	std::ostringstream oss;
    oss << m_Score;
    std::string valscore = "Score: "+oss.str();
	egn::FontManager::get()->write(window, "shoes", valscore,egn::Vector2f( 300, 200 ), 20, egn::Color::Black);

	std::ostringstream oss1;
    oss1 << m_Time;
    std::string valtime = "Temps: "+oss1.str();
    egn::FontManager::get()->write(window, "shoes", valtime,egn::Vector2f( 300, 300 ), 20, egn::Color::Black);
    
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
    egn::FontManager::get()->write(window, "shoes", "Recommencer",egn::Vector2f( 290, 300 ), 20, egn::Color::Black);
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
    egn::FontManager::get()->write(window, "shoes", "Retour Au Menu",egn::Vector2f( 290, 370 ), 20, egn::Color::Black);
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
    egn::FontManager::get()->write(window, "shoes", "Quitter",egn::Vector2f( 290, 440 ), 20, egn::Color::Black);
    /*fin quittter*/

}

void gui::MenuWin::set( const std::string& var, std::string value )
{

}

void gui::MenuWin::set( const std::string& var, int value )
{
	if ( var == "score" )
	{
		m_Score = value;
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