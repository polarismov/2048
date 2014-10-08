#include "MainGame.hpp"

#include "egn/Keyboard.hpp"
#include "egn/TextureManager.hpp"
#include "egn/GameTime.hpp"
#include "egn/FontManager.hpp"
#include "egn/LogManager.hpp"

#include "gui/MenuStart.hpp"
#include "gui/MenuPlay.hpp"

#include "GameState.hpp"

#include <iostream>
#include <sstream>
#include <ctime>

MainGame::MainGame()
{
    egn::LogManager::get()->set( "data/log/log.dat" );
    m_Window.create( 800, 600, "2048" );
    m_Window.setFramerate( 60 );

    egn::Keyboard::init();
    egn::TextureManager::init();
    egn::FontManager::init();

    egn::FontManager::get()->add( "shoes", "data/font/Shoes.ttf" );

    srand(time(NULL));

    GameState::set( GS_MENU_START );
}

MainGame::~MainGame()
{
    //dtor
}

void MainGame::loop()
{
    m_GuiMgr.add( new gui::MenuStart(), "menu_start" );
    m_GuiMgr.add( new gui::MenuPlay(), "menu_play");
    while( m_Window.isOpen() )
    {
        egn::GameTime::refresh();
        egn::Event event;
        while( m_Window.pollEvent( event ) )
        {
            egn::Keyboard::listenEvent( event );
        }

        if( egn::Keyboard::isActive( "quit") || egn::Keyboard::isActive( "escape") )
        {
            GameState::set( GS_EXIT );
        }

        switch( GameState::get() )
        {
            case GS_MENU_START:
            m_GuiMgr.update( "menu_start" );
            m_Window.clear( egn::Color::Black );
            m_GuiMgr.draw( "menu_start", m_Window );
            break;

            case GS_MENU_PLAY:
            m_GuiMgr.update( "menu_play" );
            m_Window.clear( egn::Color::Black );
            m_GuiMgr.draw( "menu_play", m_Window );
            break;

            case GS_MENU_OPTION:
            m_Window.clear( egn::Color::Black );
            break;

            case GS_EXIT:
            m_Window.close();
            break;
        }
        m_Window.display();

        std::ostringstream oss;
        int fps = (1.0 / egn::GameTime::getElapsedTime());
        oss << fps;
        std::string str = "2048 | " + oss.str() + " fps";
        m_Window.setTitle( str );
    }

    egn::TextureManager::kill();
    egn::FontManager::kill();
    egn::LogManager::kill();
}
