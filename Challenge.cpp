#include "Challenge.hpp"



Challenge::Challenge()
{
	//default ctor
}

Challenge::Challenge( int id, ChallengeType type, int score, int time )
{
	m_Id = id;
	m_Type = type;
	m_Score = score;
	m_Time = time;
}

Challenge::~Challenge()
{
	//dtor
}

int Challenge::getId() { return m_Id; }
	
int Challenge::getScore() { return m_Score; }
	
int Challenge::getTime() { return m_Time; }
	
ChallengeType Challenge::getType() { return m_Type; }
