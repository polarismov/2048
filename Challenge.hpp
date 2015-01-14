#ifndef CHALLENGE_HPP
#define CHALLENGE_HPP


#include <iostream>
#include <vector>


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
	
	std::vector<std::vector<int> > getNumbers();
	
	private:
	
	int m_Id;
	
	ChallengeType m_Type;
	
	int m_Score;
	
	int m_Time;
	
	std::vector<std::vector<int> > m_Numbers;
	
	
};













#endif
