#include "MenuChallenge.hpp"

#include <sstream>

#include "../egn/TextureManager.hpp"
#include "../egn/FontManager.hpp"
#include "../egn/Keyboard.hpp"

#include "../GameState.hpp"
#include "../DataManager.hpp"

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
	if ( egn::Keyboard::isActive("return"))
    {
        switch (m_Cursor)
        {
            case 0:
            GameState::set( Gamestate::MENU_START );
            break;
        }
        egn::Keyboard::setActive( "return", false );
    }
}

void gui::MenuChallenge::draw( egn::Window& window )
{
	window.drawRect( egn::FloatRect( 0, 0, 800, 600 ), egn::Color( 0, 0, 0, 180 ) );
	egn::FontManager::get()->write( window, "shoes", "Challenge", egn::Vector2f( 255, 60 ), 50, egn::Color::Black );

	if( m_Cursor == 0 )
	{
		egn::FontManager::get()->write(window, "shoes","Retour",egn::Vector2f(330, 550 ), 25, egn::Color::Yellow);
	}
	else 
	{
		egn::FontManager::get()->write(window, "shoes","Retour",egn::Vector2f(330, 550 ), 25, egn::Color::Black);	
	}
}

void gui::MenuChallenge::updateCursor( int value )
{
	m_Cursor += value;
	if( m_Cursor < 0 ) m_Cursor = 1;
	if( m_Cursor > 1 ) m_Cursor = 0;
}