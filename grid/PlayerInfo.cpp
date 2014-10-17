#include "PlayerInfo.hpp"

#include <iostream>
#include <sstream>

grid::PlayerInfo::PlayerInfo()
{
	m_Score = 0;
	m_Pseudo = "player";
}

grid::PlayerInfo::~PlayerInfo()
{
	//dtor
}

void grid::PlayerInfo::update()
{
	time(&m_CurrentTime);
}

void grid::PlayerInfo::setScore( int score)
{
	m_Score = score;
}

int grid::PlayerInfo::getScore()
{
	return m_Score;
}

void grid::PlayerInfo::setPseudo( std::string pseudo)
{
	m_Pseudo = pseudo;
}

std::string grid::PlayerInfo::getPseudo()
{
	return m_Pseudo;
}

void grid::PlayerInfo::initTime()
{
	time(&m_StartTime);
}

float grid::PlayerInfo::getTime()
{
	return (float)difftime( m_CurrentTime, m_StartTime);
}
