#include "MainGame.hpp"

#include "egn/Keyboard.hpp"
#include "egn/TextureManager.hpp"
#include "egn/GameTime.hpp"
#include "egn/FontManager.hpp"
#include "egn/LogManager.hpp"
#include "egn/AudioManager.hpp"

#include "gui/MenuStart.hpp"
#include "gui/MenuPlay.hpp"
#include "gui/MenuChallenge.hpp"
#include "gui/MenuOption.hpp"
#include "gui/MenuHud.hpp"
#include "gui/MenuLose.hpp"
#include "gui/MenuWin.hpp"
#include "gui/MenuPause.hpp"
#include "gui/MenuClassement.hpp"
#include "gui/MenuPseudo.hpp"
#include "gui/MenuContinue.hpp"

#include "GameState.hpp"
#include "DataManager.hpp"

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
    DataManager::init();

    egn::FontManager::get()->add( "shoes", "data/font/Shoes.ttf" );
    egn::FontManager::get()->add( "olympic", "data/font/Olympic.ttf");


    srand(time(NULL));

    GameState::set( Gamestate::MENU_START );

    egn::Camera camera = egn::Camera( egn::FloatRect( 0, 0, 800, 600 ) );
    m_Window.setCamera( camera );

    /* CHARGEMENT */
    DataManager::get()->basic_load_conf();
    DataManager::get()->basic_load_result();
    DataManager::get()->basic_load_challenge_list();

    egn::AudioManager::get()->setVolumeMusic( DataManager::get()->get_conf( "volume_music" ) );
    egn::AudioManager::get()->setVolumeSound( DataManager::get()->get_conf( "volume_sound" ) ); 

}

MainGame::~MainGame()
{
    //dtor
}

void MainGame::loop()
{
    m_GuiMgr.add( new gui::MenuStart(), "menu_start" );
    m_GuiMgr.add( new gui::MenuPlay(), "menu_play" );
    m_GuiMgr.add( new gui::MenuChallenge(), "menu_challenge" );
    m_GuiMgr.add( new gui::MenuOption(), "menu_option" );
    m_GuiMgr.add( new gui::MenuHud(), "menu_hud" );
    m_GuiMgr.add( new gui::MenuLose(), "menu_lose" );
    m_GuiMgr.add( new gui::MenuWin(), "menu_win");
    m_GuiMgr.add( new gui::MenuPause(), "menu_pause" );
    m_GuiMgr.add( new gui::MenuClassement(), "menu_classement" );
    m_GuiMgr.add( new gui::MenuPseudo(), "menu_pseudo");
    m_GuiMgr.add( new gui::MenuContinue(), "menu_continue");
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
            GameState::set( Gamestate::EXIT );
        }

        switch( GameState::get() )
        {
            case Gamestate::MENU_START:
            egn::AudioManager::get()->playMusic("data/audio/music1.ogg");
            m_GuiMgr.update( "menu_start" );
            m_Window.clear( egn::Color( 250, 250, 250 ) );
            m_GuiMgr.draw( "menu_start", m_Window );
            break;

            case Gamestate::MENU_PLAY:
            m_GuiMgr.update( "menu_play" );
            m_Window.clear( egn::Color( 250, 250, 250 ) );
            m_GuiMgr.draw( "menu_play", m_Window );
            m_Grid.setChallenge( false );
            break;

            case Gamestate::SET_4X4_PLAY:
            m_Grid.getPlayerInfo().setScore( 0 );
            m_Grid.setSize( 4 );
            m_Grid.popNumber( 2 );
            GameState::set( Gamestate::MENU_PSEUDO );
            break;

            case Gamestate::SET_5X5_PLAY:
            m_Grid.getPlayerInfo().setScore( 0 );
            m_Grid.setSize( 5 );
            m_Grid.popNumber( 2 );
            GameState::set( Gamestate::MENU_PSEUDO  );
            break;

            case Gamestate::SET_6X6_PLAY:
            m_Grid.getPlayerInfo().setScore( 0 );
            m_Grid.setSize( 6 );
            m_Grid.popNumber( 2 );
            GameState::set( Gamestate::MENU_PSEUDO  );
            break;

            case Gamestate::MENU_PSEUDO :
            m_GuiMgr.update("menu_pseudo");
            m_Window.clear( egn::Color( 250, 250, 250 ) );
            m_GuiMgr.draw( "menu_pseudo", m_Window );
            break;

            case Gamestate::SET_PSEUDO:
            m_Grid.getPlayerInfo().setPseudo( m_GuiMgr.get_string( "menu_pseudo", "pseudo" ) );
            if( m_Grid.getChallenge() == false ) GameState::set( Gamestate::PLAY );
            m_Grid.getPlayerInfo().initTime();
            break;

            case Gamestate::PLAY:
            m_Grid.update();
            m_GuiMgr.set( "menu_hud", "score", m_Grid.getPlayerInfo().getScore() );
            m_GuiMgr.set( "menu_hud", "time", m_Grid.getPlayerInfo().getTime() );
            m_GuiMgr.update("menu_hud");
            m_Window.clear( egn::Color( 250, 250, 250 ) );
            m_Grid.draw( m_Window );
            m_GuiMgr.draw( "menu_hud", m_Window );
            break;

            case Gamestate::MENU_PAUSE:
            m_GuiMgr.set( "menu_pause", "continue", m_Grid.getContinue() );
            m_GuiMgr.update( "menu_pause" );
            m_Window.clear( egn::Color( 250, 250, 250 ) );
            m_Grid.draw( m_Window );
            m_GuiMgr.draw( "menu_pause", m_Window );
            break;

            case Gamestate::MENU_CHALLENGE:
            m_GuiMgr.update( "menu_challenge" );
            m_Window.clear( egn::Color( 250, 250, 250 ) );
            m_GuiMgr.draw( "menu_challenge", m_Window );
            break;

            case Gamestate::MENU_OPTION:
            m_GuiMgr.update( "menu_option" );
            m_Window.clear( egn::Color( 250, 250, 250 ) );
            m_GuiMgr.draw ( "menu_option", m_Window );
            break;

            case Gamestate::MENU_WIN:
            m_GuiMgr.set( "menu_win", "score", m_Grid.getPlayerInfo().getScore() );
            m_GuiMgr.set( "menu_win", "time", m_Grid.getPlayerInfo().getTime() );
            m_GuiMgr.set( "menu_win", "pseudo", m_Grid.getPlayerInfo().getPseudo() );
            m_GuiMgr.update( "menu_win" );
            m_Window.clear( egn::Color( 250, 250, 250 ) );
            m_GuiMgr.draw( "menu_win", m_Window );
            break;

            case Gamestate::MENU_LOSE:
            m_GuiMgr.set( "menu_lose", "score", m_Grid.getPlayerInfo().getScore() );
            m_GuiMgr.update( "menu_lose" );
            m_Window.clear( egn::Color( 250, 250, 250 ) );
            m_GuiMgr.draw( "menu_lose", m_Window );
            break;

            case Gamestate::MENU_CLASSEMENT:
            m_GuiMgr.update( "menu_classement" );
            m_Window.clear( egn::Color( 250, 250, 250 ) );
            m_GuiMgr.draw( "menu_classement", m_Window );
            break;

            case Gamestate::UPDATE_CLASSEMENT:
            m_GuiMgr.set( "menu_classement", "sort", "" );
            GameState::set( Gamestate::MENU_CLASSEMENT );
            break;

            case Gamestate::MENU_CONTINUE:
            m_GuiMgr.update( "menu_continue");
            m_Window.clear( egn::Color( 250, 250, 250 ) );
            m_Grid.draw( m_Window );
            m_GuiMgr.draw( "menu_continue", m_Window);
            break;

            case Gamestate::EXIT:
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
    DataManager::kill();
}
