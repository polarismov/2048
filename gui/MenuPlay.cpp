#include "MenuPlay.hpp"
#include "../egn/Keyboard.hpp"
#include "../egn/FontManager.hpp"
#include "../GameState.hpp"

gui::MenuPlay::MenuPlay()
{
    m_Cursor=0;
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
    egn::FontManager::get()->write(window, "shoes","Difficulte",egn::Vector2f(600/2-40, 50 ), 50, egn::Color::Red);
    if( m_Cursor == 0 )
        egn::FontManager::get()->write(window, "shoes","Facile      6X6",egn::Vector2f(50, 120 ), 30, egn::Color::Yellow);
    else
        egn::FontManager::get()->write(window, "shoes","Facile      6X6",egn::Vector2f(50, 120 ), 30, egn::Color::White);

    if ( m_Cursor == 1 )
        egn::FontManager::get()->write(window, "shoes","Normal      4X4",egn::Vector2f(50, 160 ), 30, egn::Color::Yellow);
    else
        egn::FontManager::get()->write(window, "shoes","Normal      4X4",egn::Vector2f(50, 160 ), 30, egn::Color::White);

    if ( m_Cursor == 2 )
        egn::FontManager::get()->write(window, "shoes","Diabolique  3X3",egn::Vector2f(50, 200 ), 30, egn::Color::Yellow);
    else
        egn::FontManager::get()->write(window, "shoes","Diabolique  3X3",egn::Vector2f(50, 200 ), 30, egn::Color::White);
    if ( m_Cursor == 3 )
        egn::FontManager::get()->write(window, "shoes","Retour",egn::Vector2f(50, 240 ), 30, egn::Color::Yellow);
    else
        egn::FontManager::get()->write(window, "shoes","Retour",egn::Vector2f(50, 240 ), 30, egn::Color::White);
}

void gui::MenuPlay::updateCursor(int value)
{
    m_Cursor += value;
    if ( m_Cursor < 0 ) m_Cursor = 3;
    if ( m_Cursor > 3 ) m_Cursor = 0;
}

