#include "MenuPlay.hpp"
#include "../egn/Keyboard.hpp"
#include "../egn/FontManager.hpp"
#include "../GameState.hpp"
#include "../egn/TextureManager.hpp"
gui::MenuPlay::MenuPlay()
{
    m_Cursor=0;
    m_Button[0].setTexture( egn::TextureManager::get()->getTexture("data/image/button1.png", egn::Color::White) );
    m_Button[1].setTexture( egn::TextureManager::get()->getTexture("data/image/button2.png", egn::Color::White) );
}

gui::MenuPlay::~MenuPlay()
{
    //dtor
}
void gui::MenuPlay::update()
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
            break;

            case 2:
            break;

            case 3:
            GameState::set( GS_MENU_START );
            break;
        }
        egn::Keyboard::setActive( "return", false );
    }
}
void gui::MenuPlay::draw(egn::Window& window)
{
    
    egn::FontManager::get()->write(window, "shoes","Difficulte",egn::Vector2f(600/2-40, 50 ), 50, egn::Color::Black);
    /*facile*/
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
    egn::FontManager::get()->write(window, "shoes","Facile      6X6",egn::Vector2f(285, 150 ), 30, egn::Color::Black);
    /*end facile*/

    /*normal*/
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
    egn::FontManager::get()->write(window, "shoes","Normal     4X4",egn::Vector2f(285, 220 ), 30, egn::Color::Black);
    /*end normal*/

    /*extreme*/
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
    egn::FontManager::get()->write(window, "shoes","Extreme    3X3",egn::Vector2f(285, 290 ), 30, egn::Color::Black);
    /*end extreme*/
       
    /*retour*/
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
    
    egn::FontManager::get()->write(window, "shoes","Retour",egn::Vector2f(345, 360 ), 30, egn::Color::Black);
    /*end retour*/
}

void gui::MenuPlay::updateCursor(int value)
{
    m_Cursor += value;
    if ( m_Cursor < 0 ) m_Cursor = 3;
    if ( m_Cursor > 3 ) m_Cursor = 0;
}

