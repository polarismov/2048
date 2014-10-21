#ifndef DATAMANAGER_HPP
#define DATAMANAGER_HPP

#include "egn/Singleton.hpp"

#include <iostream>
#include <vector>
#include <fstream>

struct player 
{
	std::string pseudo;
	int time;
	int score;

	player( std::string p, int s, int t )
	{
		pseudo = p;
		time = t;
		score = s;
	}
};

class DataManager : public Singleton<DataManager>
{
public:
	DataManager();
	~DataManager();

	/* insertion non binaire */
	void basic_insert_result( std::string pseudo, int score, int time );
	void basic_load_result();
	std::vector<player> get_result();

	/* insertion configuration non binaire */
	void basic_insert_conf( std::string conf, int value );
	void basic_load_conf();
	int basic_get_conf( std::string conf );
private:
	std::vector<player> m_Result;
};





#endif
