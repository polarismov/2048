#include "DataManager.hpp"


DataManager::DataManager()
{
	//ctor
}

DataManager::~DataManager()
{
	//dtor
}

void DataManager::basic_insert_result( std::string pseudo, int score, int time )
{
	m_Result.push_back( player( pseudo, score, time ) ); 
	std::ofstream file( "data/save/save.dat", std::ios_base::app );

	file << pseudo << " " << score << " " << time << std::endl;
	file.close();
}

void DataManager::basic_load_result()
{
	std::ifstream file( "data/save/save.dat" );

	/* compter le nombre de lignes */
	int count = 0;
	while( true )
	{
		std::string buffer;
		getline(file , buffer);
		if( file.eof() ) break;
		++count;
	}

	file.close();


	file.open( "data/save/save.dat" );
	/* charger les données */
	for( int i = 0; i < count; i++ )
	{
		std::string pseudo;
		int score;
		int time;

		file >> pseudo;
		file >> score;
		file >> time;


		if( pseudo != "" )
			m_Result.push_back( player( pseudo, score, time ) );
	}

	file.close();
}

void DataManager::basic_load_challenge_list()
{
	std::ifstream file( "data/challenge/list.dat" );

	/* compter le nombre de lignes */
	int count = 0;
	while( true )
	{
		std::string buffer;
		getline(file , buffer);
		if( file.eof() ) break;
		++count;
	}

	file.close();
	
	file.open( "data/challenge/list.dat" );
	
	for( int i = 0; i < count; i++ )
	{
		int id;
		int type;
		int score;
		int ncoup;
		int time;
		std::string grid;
		std::vector<std::vector<int> > numbers;
		
		file >> id;
		file >> type;
		file >> score;
		file >> time;
		file >> ncoup;
		file >> grid;
		
		if( grid != "none" )
		{
			
				std::ifstream file_grid( grid.c_str() );

				int width;
				int height;
				
				file_grid >> width;
				file_grid >> height;
				
				for( int i = 0; i < height; i++ )
				{
					std::vector<int> tmp;
					for( int j = 0; j < width; j++ )
					{
						int val;
						file_grid >> val;
						tmp.push_back( val );
					}
					
					numbers.push_back( tmp );
				}
				
				
				file_grid.close();
				
				
				
		}
		
		
		if( static_cast<ChallengeType>(type) == ChallengeType::SCORE_TIME )
		{
			Challenge challenge( id, static_cast<ChallengeType>(type), score, time );
			m_Challenges.push_back( challenge );
		}
	}
	
	file.close();
}

std::vector<Challenge> DataManager::basic_get_challenge_list()
{
	return m_Challenges;
}

Challenge DataManager::get_challenge( int index )
{
	return m_Challenges[index];
}

std::vector<player> DataManager::get_result()
{
	return m_Result;
}

void DataManager::basic_insert_conf( std::string conf, int value )
{
	m_Conf[conf] = value;

	std::ofstream file( "data/save/conf.dat" );

	std::map<std::string, int>::iterator it;
	for( it = m_Conf.begin(); it != m_Conf.end(); ++it )
	{
		file << (*it).first << " " << (*it).second << std::endl;
	}

	file.close();
}

void DataManager::basic_load_conf()
{
	std::ifstream file( "data/save/conf.dat" );

	/* compter le nombre de lignes */
	int count = 0;
	while( true )
	{
		std::string buffer;
		getline(file , buffer);
		if( file.eof() ) break;
		++count;
	}

	file.close();

	file.open( "data/save/conf.dat" );

	for( int i = 0; i < count; i++ )
	{
		std::string conf;
		int value;

		file >> conf;
		file >> value;

		m_Conf[conf] = value;
	}

	file.close();
}

int DataManager::get_conf( std::string conf )
{
	return m_Conf[conf];
}
