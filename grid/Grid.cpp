#include "Grid.hpp"


grid::Grid::Grid()
{
	m_Size = 0;
	m_BasePosition = egn::Vector2f( 200, 100 );
}

grid::Grid::~Grid()
{
	//dtor
}

void grid::Grid::setSize( int size )
{
	m_Size = size;
	m_Grid.clear();

	for( int i = 0; i < size; i++ )
	{
		std::vector<int> tmp;
		for( int j = 0; j < size; j++ )
		{
			tmp.push_back( 0 );
		}
		m_Grid.push_back( tmp );
	}

	m_BasePosition.x = 400 - ((size * 50 + size * 5) / 2);
	m_BasePosition.y = 300 - ((size * 50 + size * 5) / 2);
}

void grid::Grid::draw( egn::Window& window )
{
	for( int i = 0; i < m_Grid.size(); i++ )
	{
		for( int j = 0; j < m_Grid[0].size(); j++ )
		{
			egn::FloatRect rect = egn::FloatRect( m_BasePosition.x + j * 50 + j*5, m_BasePosition.y + i * 50 + i*5, 50, 50 );
			window.drawRect( rect, egn::Color( 187, 173, 160 ) );
		}
	}
}