#include "MenuOption.hpp"

#include <iostream>
#include <sstream>

#include "../egn/Keyboard.hpp"
#include "../egn/FontManager.hpp"
#include "../egn/TextureManager.hpp"
#include "../egn/AudioManager.hpp"

#include "../GameState.hpp"
gui::MenuOption::MenuOption()
{
    m_Cursor=0;
    m_Button[0].setTexture( egn::TextureManager::get()->getTexture("data/image/button1.png", egn::Color::White) );
    m_Button[1].setTexture( egn::TextureManager::get()->getTexture("data/image/button2.png", egn::Color::White) );
}

gui::MenuOption::~MenuOption()
{
    //dtor
}
void gui::MenuOption::update()
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
            GameState::set( GS_MENU_START );
            break;
        }
        egn::Keyboard::setActive( "return", false );
    }
}

void gui::MenuOption::draw(egn::Window& window)
{
    egn::FontManager::get()->write(window, "shoes","Option",egn::Vector2f( 320, 50 ), 50, egn::Color::Black);
    /*sound*/
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
    std::ostringstream oss;
    oss << egn::AudioManager::get()->getVolumeSound();
    std::string valsound = "< "+oss.str()+" >";
    egn::FontManager::get()->write(window, "shoes","Sound ",egn::Vector2f( 345-30, 158 ), 30, egn::Color::Black);
    egn::FontManager::get()->write(window, "olympic", valsound, egn::Vector2f( 440, 158 ), 30, egn::Color::Black);
    /*end sound*/

    /*musique*/
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
    std::ostringstream oss1;
    oss1 << egn::AudioManager::get()->getVolumeMusic();
    std::string valmusic = "< "+oss1.str()+" >";
    egn::FontManager::get()->write(window, "shoes","Music",egn::Vector2f( 345-30, 228 ), 30, egn::Color::Black);
    egn::FontManager::get()->write(window, "olympic", valmusic,egn::Vector2f( 440, 228 ), 30, egn::Color::Black);

    /*end musique*/

    /*retour*/
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
    egn::FontManager::get()->write(window, "shoes","Retour",egn::Vector2f( 340, 298 ), 30, egn::Color::Black);
  /*end retour*/

}

void gui::MenuOption::updateCursor(int value)
{
    m_Cursor += value;
    if ( m_Cursor < 0 ) m_Cursor = 2;
    if ( m_Cursor > 2 ) m_Cursor = 0;
}
