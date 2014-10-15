#include "MenuHud.hpp"

#include <sstream>

#include "../egn/FontManager.hpp"

gui::MenuHud::MenuHud()
{
	m_Score = 0;
	m_Time = 0;
	m_BestScore = 0;
}

gui::MenuHud::~MenuHud()
{

}

void gui::MenuHud::update()
{
	
}

void gui::MenuHud::draw( egn::Window& window)
{
	std::ostringstream oss;
    oss << m_Score;
    std::string valscore = "Score: "+oss.str();
	egn::FontManager::get()->write(window, "shoes", valscore,egn::Vector2f( 10, 50 ), 30, egn::Color::Black);

	std::ostringstream oss1;
    oss1 << m_Time;
    std::string valtime = "Temps: "+oss1.str();
    egn::FontManager::get()->write(window, "shoes", valtime,egn::Vector2f( 620, 50 ), 30, egn::Color::Black);

}

void gui::MenuHud::set( const std::string& var, int value)
{
	if ( var == "score" )
	{
		m_Score = value;
	}
	else if ( var == "bestscore")
	{
		m_BestScore = value;
	}
	else if ( var == "time")
	{
		m_Time = value;
	}
}

void gui::MenuHud::set( const std::string& var, std::string value)
{

}

