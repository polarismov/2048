#include "MenuClassement.hpp"

#include "../egn/FontManager.hpp"
#include "../egn/Keyboard.hpp"

#include "../GameState.hpp"

#include <iostream>
#include <sstream>

gui::MenuClassement::MenuClassement()
{
	m_TypeClassement = 1;
	m_Cursor = 0;
}

gui::MenuClassement::~MenuClassement()
{
	//dtor
}

void gui::MenuClassement::update()
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
            m_TypeClassement = 1;
            break;

            case 1:
            m_TypeClassement = 2;
            break;

            case 2:
            GameState::set( Gamestate::MENU_START );
            break;
        }
        egn::Keyboard::setActive( "return", false );
    }
}

void gui::MenuClassement::draw( egn::Window& window )
{
	egn::FontManager::get()->write(window, "shoes","Classement",egn::Vector2f(600/2-70, 30 ), 50, egn::Color::Black);

	egn::FontManager::get()->write(window, "shoes","pseudo",egn::Vector2f(140, 100  ), 30, egn::Color::Black);
	if( m_TypeClassement == 1 )
		egn::FontManager::get()->write(window, "shoes","score",egn::Vector2f(350, 100  ), 30, egn::Color::Red);
	else
		egn::FontManager::get()->write(window, "shoes","score",egn::Vector2f(350, 100  ), 30, egn::Color::Black);

	if( m_TypeClassement == 2 )
		egn::FontManager::get()->write(window, "shoes","temps",egn::Vector2f(520, 100 ), 30, egn::Color::Red);
	else 
		egn::FontManager::get()->write(window, "shoes","temps",egn::Vector2f(520, 100 ), 30, egn::Color::Black);


	/* classement score == 1 && classement time == 2 */
	if( m_TypeClassement == 1 )
	{
		int size = m_ResultByScore.size();

		/* limiter le nombre d'affichages à 20 */
		if( size > 10 ) size = 10;

		for( int i = 0; i < size; i++ )
		{
			std::ostringstream oss_classement;
			std::ostringstream oss_score;
			std::ostringstream oss_time;

			oss_classement << i+1;

			egn::FontManager::get()->write(window, "shoes",oss_classement.str(),egn::Vector2f(100, 150 + i * 30 ), 25, egn::Color::Black);
			egn::FontManager::get()->write(window, "shoes", m_ResultByScore[i].pseudo ,egn::Vector2f(150, 150 + i * 30 ), 25, egn::Color::Black);

			oss_score << m_ResultByScore[i].score;
			egn::FontManager::get()->write(window, "shoes", oss_score.str(),egn::Vector2f(350, 150 + i * 30 ), 25, egn::Color::Red);

			oss_time << m_ResultByScore[i].time;
			egn::FontManager::get()->write(window, "shoes", oss_time.str(),egn::Vector2f(520, 150 + i * 30 ), 25, egn::Color::Black);
		}
	}
	else if( m_TypeClassement == 2 )
	{
		int size = m_ResultByTime.size();

		/* limiter le nombre d'affichages à 20 */
		if( size > 10 ) size = 10;

		for( int i = 0; i < size; i++ )
		{
			std::ostringstream oss_classement;
			std::ostringstream oss_score;
			std::ostringstream oss_time;

			oss_classement << i+1;

			egn::FontManager::get()->write(window, "shoes",oss_classement.str(),egn::Vector2f(100, 150 + i * 30 ), 25, egn::Color::Black);
			egn::FontManager::get()->write(window, "shoes", m_ResultByTime[i].pseudo ,egn::Vector2f(150, 150 + i * 30 ), 25, egn::Color::Black);

			oss_score << m_ResultByTime[i].score;
			egn::FontManager::get()->write(window, "shoes", oss_score.str(),egn::Vector2f(350, 150 + i * 30 ), 25, egn::Color::Black);

			oss_time << m_ResultByTime[i].time;
			egn::FontManager::get()->write(window, "shoes", oss_time.str(),egn::Vector2f(520, 150 + i * 30 ), 25, egn::Color::Red);
		}
	}

	if( m_Cursor == 0 )
	{
		egn::FontManager::get()->write(window, "shoes","Trier par score",egn::Vector2f(280, 470 ), 25, egn::Color::Yellow);
	}
	else 
	{
		egn::FontManager::get()->write(window, "shoes","Trier par score",egn::Vector2f(280, 470 ), 25, egn::Color::Black);	
	}

	if( m_Cursor == 1 )
	{
		egn::FontManager::get()->write(window, "shoes","Trier par temps",egn::Vector2f(280, 510 ), 25, egn::Color::Yellow);
	}
	else 
	{
		egn::FontManager::get()->write(window, "shoes","Trier par temps",egn::Vector2f(280, 510 ), 25, egn::Color::Black);	
	}

	if( m_Cursor == 2 )
	{
		egn::FontManager::get()->write(window, "shoes","Retour",egn::Vector2f(330, 550 ), 25, egn::Color::Yellow);
	}
	else 
	{
		egn::FontManager::get()->write(window, "shoes","Retour",egn::Vector2f(330, 550 ), 25, egn::Color::Black);	
	}


}

void gui::MenuClassement::set( const std::string& var, int value)
{
	//set
}

void gui::MenuClassement::set( const std::string& var, std::string value)
{
	if( var == "sort" )
	{
		m_ResultByScore = DataManager::get()->get_result();
		std::sort( m_ResultByScore.begin(), m_ResultByScore.end(), sort_by_score );

		m_ResultByTime = DataManager::get()->get_result();
		std::sort( m_ResultByTime.begin(), m_ResultByTime.end(), sort_by_time );
	}
}

bool gui::MenuClassement::sort_by_score( player p1, player p2 )
{
	return ( p1.score > p2.score );
}

bool gui::MenuClassement::sort_by_time( player p1, player p2 )
{
	return ( p1.time < p2.time );
}

void gui::MenuClassement::updateCursor( int value )
{
	m_Cursor += value;
	if( m_Cursor < 0 ) m_Cursor = 2;
	if( m_Cursor > 2 ) m_Cursor = 0;
}
