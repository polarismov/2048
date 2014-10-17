#include "MainGame.hpp"

#include "egn/Keyboard.hpp"
#include "egn/TextureManager.hpp"
#include "egn/GameTime.hpp"
#include "egn/FontManager.hpp"
#include "egn/LogManager.hpp"
#include "egn/AudioManager.hpp"

#include "gui/MenuStart.hpp"
#include "gui/MenuPlay.hpp"
#include "gui/MenuOption.hpp"
#include "gui/MenuHud.hpp"
#include "gui/MenuLose.hpp"
#include "gui/MenuWin.hpp"

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
    egn::AudioManager::init();

    egn::FontManager::get()->add( "shoes", "data/font/Shoes.ttf" );
    egn::FontManager::get()->add( "olympic", "data/font/Olympic.ttf");


    srand(time(NULL));

    GameState::set( GS_MENU_START );

    egn::Camera camera = egn::Camera( egn::FloatRect( 0, 0, 800, 600 ) );
    m_Window.setCamera( camera );
}

MainGame::~MainGame()
{
    //dtor
}

void MainGame::loop()
{
    m_GuiMgr.add( new gui::MenuStart(), "menu_start" );
    m_GuiMgr.add( new gui::MenuPlay(), "menu_play" );
    m_GuiMgr.add( new gui::MenuOption(), "menu_option" );
    m_GuiMgr.add( new gui::MenuHud(), "menu_hud" );
    m_GuiMgr.add( new gui::MenuLose(), "menu_lose" );
    m_GuiMgr.add(new gui::MenuWin(), "menu_win");

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
            m_Window.clear( egn::Color( 250, 250, 250 ) );
            m_GuiMgr.draw( "menu_start", m_Window );
            break;

            case GS_MENU_PLAY:
            m_GuiMgr.update( "menu_play" );
            m_Window.clear( egn::Color( 250, 250, 250 ) );
            m_GuiMgr.draw( "menu_play", m_Window );
            break;

            case GS_SET_EASY_PLAY:
            m_Grid.getPlayerInfo().setScore( 0 );
            m_Grid.setSize( 6 );
            m_Grid.popNumber( 2 );
            GameState::set( GS_PLAY );
            m_Grid.getPlayerInfo().initTime();
            break;

            case GS_SET_MEDIUM_PLAY:
            m_Grid.getPlayerInfo().setScore( 0 );
            m_Grid.setSize( 4 );
            m_Grid.popNumber( 2 );
            GameState::set( GS_PLAY );
            m_Grid.getPlayerInfo().initTime();
            break;

            case GS_SET_HARD_PLAY:
            m_Grid.getPlayerInfo().setScore( 0 );
            m_Grid.setSize( 3 );
            m_Grid.popNumber( 2 );
            GameState::set( GS_PLAY );
            m_Grid.getPlayerInfo().initTime();
            break;

            case GS_PLAY:
            m_Grid.update();
            m_GuiMgr.set( "menu_hud", "score", m_Grid.getPlayerInfo().getScore() );
            m_GuiMgr.set( "menu_hud", "time", m_Grid.getPlayerInfo().getTime() );
            m_GuiMgr.update("menu_hud");
            m_Window.clear( egn::Color( 250, 250, 250 ) );
            m_Grid.draw( m_Window );
            m_GuiMgr.draw( "menu_hud", m_Window );
            break;

            case GS_MENU_OPTION:
            m_GuiMgr.update( "menu_option" );
            m_Window.clear( egn::Color( 250, 250, 250 ) );
            m_GuiMgr.draw ( "menu_option", m_Window );
            break;

            case GS_MENU_WIN:
            m_GuiMgr.set( "menu_win", "score", m_Grid.getPlayerInfo().getScore() );
            m_GuiMgr.set( "menu_win", "time", m_Grid.getPlayerInfo().getTime() );
            m_GuiMgr.update( "menu_win" );
            m_Window.clear( egn::Color( 250, 250, 250 ) );
            m_GuiMgr.draw( "menu_win", m_Window );
            break;

            case GS_MENU_LOSE:
            m_GuiMgr.set( "menu_lose", "score", m_Grid.getPlayerInfo().getScore() );
            m_GuiMgr.update( "menu_lose" );
            m_Window.clear( egn::Color( 250, 250, 250 ) );
            m_GuiMgr.draw( "menu_lose", m_Window );
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
    egn::AudioManager::kill();
}
