#ifndef CHALLENGE_HPP
#define CHALLENGE_HPP


#include "Common.hpp"


class Challenge 
{
	public:
	Challenge();
	Challenge( int id, ChallengeType type, int score, int time );
	
	~Challenge();
	
	int getId();
	
	int getScore();
	
	int getTime();
	
	ChallengeType getType();
	
	private:
	
	int m_Id;
	
	ChallengeType m_Type;
	
	int m_Score;
	
	int m_Time;
	
	
};













#endif
