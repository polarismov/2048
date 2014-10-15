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
	egn::FontManager::get()->write(window, "shoes", valscore,egn::Vector2f(600/2-40, 50 ), 50, egn::Color::Black)
}

void gui::MenuHud::set( const std::string var, int value)
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
		m_Time = var;
	}
}

void gui::MenuHud::set( const std::string var, std::string value)
{

}

