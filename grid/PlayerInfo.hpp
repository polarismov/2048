#ifndef GRID_PLAYERINFO_HPP
#define GRID_PLAYERINFO_HPP

#include <ctime>
#include <iostream>
#include "../Common.hpp"

namespace grid
{
	class PlayerInfo
	{
	public:
		PlayerInfo();
		~PlayerInfo();

		void update();

		void setScore( int score );
		int getScore();

		void setPseudo( std::string pseudo );
		std::string getPseudo();
		
		void initTime();
		float getTime();
	private:
		int m_Score;
		time_t m_StartTime;
		time_t m_CurrentTime;
		std::string m_Pseudo;
	};
}

#endif