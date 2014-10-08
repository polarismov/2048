#include "MainGame.hpp"

#include "egn/Keyboard.hpp"
#include "egn/TextureManager.hpp"
#include "egn/GameTime.hpp"
#include "egn/FontManager.hpp"
#include "egn/LogManager.hpp"

#include "gui/MenuStart.hpp"

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
}

MainGame::~MainGame()
{
    //dtor
}

void MainGame::loop()
{
    m_GuiMgr.add( new gui::MenuStart, "menu_start" );
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
            m_Window.close();
        }

        m_GuiMgr.update( "menu_start" );


        m_Window.clear( egn::Color::Black );
        m_GuiMgr.draw( "menu_start", m_Window );
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
