#include "MenuStart.hpp"

#include "../egn/FontManager.hpp"
#include "../egn/Keyboard.hpp"
#include "../egn/TextureManager.hpp"

#include "../GameState.hpp"


gui::MenuStart::MenuStart()
{
    m_Cursor = 0;
    m_Button[0].setTexture( egn::TextureManager::get()->getTexture( "data/image/button1.png", egn::Color::White ) );
    m_Button[1].setTexture( egn::TextureManager::get()->getTexture( "data/image/button2.png", egn::Color::White ) );


}

gui::MenuStart::~MenuStart()
{
    //dtor
}

void gui::MenuStart::update()
{
    if( egn::Keyboard::isActive("up") )
    {
        updateCursor(-1);
        egn::Keyboard::setActive("up", false);
    }
    else if( egn::Keyboard::isActive("down") )
    {
        updateCursor(1);
        egn::Keyboard::setActive("down", false);
    }

    if( egn::Keyboard::isActive( "return" ) )
    {
        switch( m_Cursor )
        {
            case 0:
            GameState::set( Gamestate::MENU_PLAY );
            break;

            case 1:
            break;

            case 2: 
            GameState::set( Gamestate::UPDATE_CLASSEMENT );
            break;

            case 3:
            GameState::set( Gamestate::MENU_OPTION );
            break;

            case 4:
            GameState::set( Gamestate::EXIT );
            break;
        }

        egn::Keyboard::setActive( "return", false );
    } 
}

void gui::MenuStart::draw( egn::Window& window )
{
    egn::FontManager::get()->write( window, "shoes", "2048", egn::Vector2f( 800/2-60, 50 ), 50, egn::Color::Black );
    
    /* jouer */
    m_Button[0].setPosition( egn::Vector2f( 250, 150 ) );
    m_Button[1].setPosition( egn::Vector2f( 250, 150 ) );
    if( m_Cursor == 0 )
    {
        window.draw( m_Button[1] );
    }
    else 
    {
        window.draw( m_Button[0] );
    }
    egn::FontManager::get()->write( window, "shoes", "Jouer", egn::Vector2f( 345, 158 ), 30, egn::Color::Black );
    /* end jouer */

    /* challenge */
    m_Button[0].setPosition( egn::Vector2f( 250, 220 ) );
    m_Button[1].setPosition( egn::Vector2f( 250, 220 ) );
    if( m_Cursor == 1 )
    {
        window.draw( m_Button[1] );
    }
    else 
    {
        window.draw( m_Button[0] );
    }
    egn::FontManager::get()->write( window, "shoes", "Challenge", egn::Vector2f( 320, 228 ), 30, egn::Color::Black );
    /* end challenge */


    /* classement */
    m_Button[0].setPosition( egn::Vector2f( 250, 290 ) );
    m_Button[1].setPosition( egn::Vector2f( 250, 290 ) );
    if( m_Cursor == 2 )
    {
        window.draw( m_Button[1] );
    }
    else 
    {
        window.draw( m_Button[0] );
    }
    egn::FontManager::get()->write( window, "shoes", "Classement", egn::Vector2f( 310, 298 ), 30, egn::Color::Black );
    /* end classement */

    /* Option */
    m_Button[0].setPosition( egn::Vector2f( 250, 360 ) );
    m_Button[1].setPosition( egn::Vector2f( 250, 360 ) );
    if( m_Cursor == 3 )
    {
        window.draw( m_Button[1] );
    }
    else 
    {
        window.draw( m_Button[0] );
    }
    egn::FontManager::get()->write( window, "shoes", "Option", egn::Vector2f( 345, 368 ), 30, egn::Color::Black );
    /* end option */

    /* quitter */
    m_Button[0].setPosition( egn::Vector2f( 250, 430 ) );
    m_Button[1].setPosition( egn::Vector2f( 250, 430 ) );
    if( m_Cursor == 4 )
    {
        window.draw( m_Button[1] );
    }
    else 
    {
        window.draw( m_Button[0] );
    }
    egn::FontManager::get()->write( window, "shoes", "Quitter", egn::Vector2f( 340, 438 ), 30, egn::Color::Black );
    /* end quitter */
    
}

void gui::MenuStart::updateCursor( int value )
{
    m_Cursor += value;
    if( m_Cursor < 0 ) m_Cursor = 4;
    if( m_Cursor > 4 ) m_Cursor = 0;
}


