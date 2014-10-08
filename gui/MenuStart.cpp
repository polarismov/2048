#include "MenuStart.hpp"

#include "../egn/FontManager.hpp"
#include "../egn/Keyboard.hpp"


gui::MenuStart::MenuStart()
{
    m_Cursor = 0;
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
}

void gui::MenuStart::draw( egn::Window& window )
{
    egn::FontManager::get()->write( window, "shoes", "2048", egn::Vector2f( 800/2-60, 50 ), 50, egn::Color::Red );

    if( m_Cursor == 0 )
        egn::FontManager::get()->write( window, "shoes", "Jouer", egn::Vector2f( 50, 150 ), 30, egn::Color::Yellow );
    else
        egn::FontManager::get()->write( window, "shoes", "Jouer", egn::Vector2f( 50, 150 ), 30, egn::Color::White );

    if( m_Cursor == 1 )
        egn::FontManager::get()->write( window, "shoes", "Challenge", egn::Vector2f( 50, 190 ), 30, egn::Color::Yellow );
    else
        egn::FontManager::get()->write( window, "shoes", "Challenge", egn::Vector2f( 50, 190 ), 30, egn::Color::White );

    if( m_Cursor == 2 )
        egn::FontManager::get()->write( window, "shoes", "Contre la montre", egn::Vector2f( 50, 230 ), 30, egn::Color::Yellow );
    else
        egn::FontManager::get()->write( window, "shoes", "Contre la montre", egn::Vector2f( 50, 230 ), 30, egn::Color::White );

    if( m_Cursor == 3 )
        egn::FontManager::get()->write( window, "shoes", "Classement", egn::Vector2f( 50, 270 ), 30, egn::Color::Yellow );
    else
        egn::FontManager::get()->write( window, "shoes", "Classement", egn::Vector2f( 50, 270 ), 30, egn::Color::White );

    if( m_Cursor == 4 )
        egn::FontManager::get()->write( window, "shoes", "Options", egn::Vector2f( 50, 310 ), 30, egn::Color::Yellow );
    else
        egn::FontManager::get()->write( window, "shoes", "Options", egn::Vector2f( 50, 310 ), 30, egn::Color::White );

    if( m_Cursor == 5 )
        egn::FontManager::get()->write( window, "shoes", "Quitter", egn::Vector2f( 50, 350 ), 30, egn::Color::Yellow );
    else
        egn::FontManager::get()->write( window, "shoes", "Quitter", egn::Vector2f( 50, 350 ), 30, egn::Color::White );
}

void gui::MenuStart::updateCursor( int value )
{
    m_Cursor += value;
    if( m_Cursor < 0 ) m_Cursor = 5;
    if( m_Cursor > 5 ) m_Cursor = 0;
}


