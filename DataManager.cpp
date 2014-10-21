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

		m_Result.push_back( player( pseudo, score, time ) );
	}

	file.close();

	std::cerr << m_Result.size() << std::endl;
}

std::vector<player> DataManager::get_result()
{
	return m_Result;
}