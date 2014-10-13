#include "Grid.hpp"

#include "../egn/GameTime.hpp"
#include "../egn/Keyboard.hpp"

grid::Grid::Grid()
{
	m_Size = 0;
	m_BasePosition = egn::Vector2f( 200, 100 );
	m_InMove = false;
}

grid::Grid::~Grid()
{
	//dtor
}

void grid::Grid::setSize( int size )
{
	m_Size = size;
	m_Grid.clear();

	m_BasePosition.x = 400 - ((size * 50 + size * 5) / 2);
	m_BasePosition.y = 300 - ((size * 50 + size * 5) / 2);

	for( int i = 0; i < size; i++ )
	{
		std::vector<grid::Number> tmp;
		for( int j = 0; j < size; j++ )
		{
			tmp.push_back( grid::Number( 0, egn::FloatRect( m_BasePosition.x + j * 50 + j*5, m_BasePosition.y + i * 50 + i*5, 50, 50 )  ) );
		}
		m_Grid.push_back( tmp );
	}
	
}

void grid::Grid::popNumber( int n )
{
	while( n )
	{
		int x = egn::GameTime::getRandomInt( 0, m_Size );
		int y = egn::GameTime::getRandomInt( 0, m_Size );

		if( m_Grid[y][x].get() == 0 )
		{
			int percent = egn::GameTime::getRandomInt( 0, 101 );
			if( percent < 95 )
			{
				m_Grid[y][x].set( 2 );
			}
			else 
			{
				m_Grid[y][x].set( 4 );
			}
			n--;
		}
	}
}

void grid::Grid::update()
{
	if( m_InMove == false )
	{
		if( egn::Keyboard::isActive("up") )
		{

			move(DIR_UP);
			egn::Keyboard::setActive("up",false);
		}
		else if( egn::Keyboard::isActive("down") )
		{
			move(DIR_DOWN);
			egn::Keyboard::setActive("down",false);
		}
		else if( egn::Keyboard::isActive("left") )
		{
			move(DIR_LEFT);
			egn::Keyboard::setActive("left",false);
		}
		else if( egn::Keyboard::isActive("right") )
		{
			move(DIR_RIGHT);
			egn::Keyboard::setActive("right",false);
		}
	}

	for( int i = 0; i < m_MoveNumber.size(); i++ )
	{
		m_MoveNumber[i].update();
		if( m_MoveNumber[i].inMove() == false )
		{
			ref ref_tmp = m_MoveNumber[i].getRef();
			m_Grid[ref_tmp.i][ref_tmp.j].setDraw( true );
		}
	}

	for( int i = 0; i < m_MoveNumber.size(); i++ )
	{
		if( m_MoveNumber[i].inMove() == false )
		{
			m_MoveNumber.erase( m_MoveNumber.begin() + i );
		}
	}

	if( m_MoveNumber.size() <= 0 && m_InMove == true )
	{
		m_InMove = false;
		popNumber( 1 );
	}
}

void grid::Grid::move( DIR direction )
{
	m_InMove = true;
	switch( direction )
	{
		case DIR_UP:
		for( int i = 0; i < m_Grid.size(); i++ )
		{
			for( int j = 0; j < m_Grid[0].size(); j++ )
			{
				if( m_Grid[i][j].get() != 0 )
				{
					bool move;
					move = false;
					egn::FloatRect position;
					ref ref_tmp;

					for( int k = i-1; k >= 0; k-- )
					{
						if( m_Grid[k][j].get() == 0 || m_Grid[i][j].get() == m_Grid[k][j].get() )
						{
							position = m_Grid[k][j].getPosition();
							move = true;
							ref_tmp.i = k;
							ref_tmp.j = j;
						}
						else 
						{
							k = 0;
						}

					}

					if( move == true )
					{
						grid::Number number = grid::Number( m_Grid[i][j].get(), m_Grid[i][j].getPosition() );
						number.setNextPosition( position );
						m_Grid[ref_tmp.i][ref_tmp.j].setDraw( false );
						if( m_Grid[ref_tmp.i][ref_tmp.j].get() == 0 ) 
						{
							m_Grid[ref_tmp.i][ref_tmp.j].set( m_Grid[i][j].get() );
						}
						else if( m_Grid[ref_tmp.i][ref_tmp.j].get() == m_Grid[i][j].get() )
						{
							m_Grid[ref_tmp.i][ref_tmp.j].set( m_Grid[i][j].get() * 2 );
						}
						m_Grid[i][j].set( 0 );
						number.move( DIR_UP, ref_tmp );
						m_MoveNumber.push_back( number );
					}
				}
			}
		}
		break;

		case DIR_DOWN:
		for( int i = m_Grid.size() - 1; i >= 0; i-- )
		{
			for( int j = m_Grid[0].size() - 1; j >= 0; j-- )
			{
				if( m_Grid[i][j].get() != 0 )
				{
					bool move;
					move = false;
					egn::FloatRect position;
					ref ref_tmp;

					for( int k = i+1; k < m_Grid.size(); k++ )
					{
						if( m_Grid[k][j].get() == 0 || m_Grid[i][j].get() == m_Grid[k][j].get() )
						{
							position = m_Grid[k][j].getPosition();
							move = true;
							ref_tmp.i = k;
							ref_tmp.j = j;
						}
						else 
						{
							k = m_Grid.size();
						}
					}

					if( move == true )
					{
						grid::Number number = grid::Number( m_Grid[i][j].get(), m_Grid[i][j].getPosition() );
						number.setNextPosition( position );
						m_Grid[ref_tmp.i][ref_tmp.j].setDraw( false );
						if( m_Grid[ref_tmp.i][ref_tmp.j].get() == 0 ) 
						{
							m_Grid[ref_tmp.i][ref_tmp.j].set( m_Grid[i][j].get() );
						}
						else if( m_Grid[ref_tmp.i][ref_tmp.j].get() == m_Grid[i][j].get() )
						{
							m_Grid[ref_tmp.i][ref_tmp.j].set( m_Grid[i][j].get() * 2 );
						}
						m_Grid[i][j].set( 0 );
						number.move( DIR_DOWN, ref_tmp );
						m_MoveNumber.push_back( number );
					}
				}
			}
		}
		break;

		case DIR_LEFT:
		for( int i = 0; i < m_Grid.size(); i++ )
		{
			for( int j = 0; j < m_Grid[0].size(); j++ )
			{
				if( m_Grid[i][j].get() != 0 )
				{
					bool move;
					move = false;
					egn::FloatRect position;
					ref ref_tmp;

					for( int k = j-1; k >= 0; k--)
					{
						if( m_Grid[i][k].get() == 0 || m_Grid[i][j].get() == m_Grid[i][k].get() )
						{
							position = m_Grid[i][k].getPosition();
							move = true;
							ref_tmp.i = i;
							ref_tmp.j = k;
						}
						else 
						{
							k = 0;
						}
					}

					if( move == true )
					{
						grid::Number number = grid::Number( m_Grid[i][j].get(), m_Grid[i][j].getPosition() );
						number.setNextPosition( position );
						m_Grid[ref_tmp.i][ref_tmp.j].setDraw( false );
						if( m_Grid[ref_tmp.i][ref_tmp.j].get() == 0 ) 
						{
							m_Grid[ref_tmp.i][ref_tmp.j].set( m_Grid[i][j].get() );
						}
						else if( m_Grid[ref_tmp.i][ref_tmp.j].get() == m_Grid[i][j].get() )
						{
							m_Grid[ref_tmp.i][ref_tmp.j].set( m_Grid[i][j].get() * 2 );
						}
						m_Grid[i][j].set( 0 );
						number.move( DIR_LEFT, ref_tmp );
						m_MoveNumber.push_back( number );
					}
				}
			}
		}
		break;

		case DIR_RIGHT:
		for( int i = 0; i < m_Grid.size(); i++ )
		{
			for( int j = m_Grid[0].size() - 1; j >= 0; j-- )
			{
				if( m_Grid[i][j].get() != 0 )
				{
					bool move;
					move = false;
					egn::FloatRect position;
					ref ref_tmp;

					for( int k = j+1; k < m_Grid[0].size(); k++ )
					{
						if( m_Grid[i][k].get() == 0 || m_Grid[i][j].get() == m_Grid[i][k].get() )
						{
							position = m_Grid[i][k].getPosition();
							move = true;
							ref_tmp.i = i;
							ref_tmp.j = k;
						}
						else 
						{
							k = m_Grid[0].size();
						}
					}

					if( move == true )
					{
						grid::Number number = grid::Number( m_Grid[i][j].get(), m_Grid[i][j].getPosition() );
						number.setNextPosition( position );
						m_Grid[ref_tmp.i][ref_tmp.j].setDraw( false );
						if( m_Grid[ref_tmp.i][ref_tmp.j].get() == 0 ) 
						{
							m_Grid[ref_tmp.i][ref_tmp.j].set( m_Grid[i][j].get() );
						}
						else if( m_Grid[ref_tmp.i][ref_tmp.j].get() == m_Grid[i][j].get() )
						{
							m_Grid[ref_tmp.i][ref_tmp.j].set( m_Grid[i][j].get() * 2 );
						}
						m_Grid[i][j].set( 0 );
						number.move( DIR_RIGHT, ref_tmp );
						m_MoveNumber.push_back( number );
					}
				}
			}
		}
		break;
	}
}

void grid::Grid::draw( egn::Window& window )
{
	for( int i = 0; i < m_Grid.size(); i++ )
	{
		for( int j = 0; j < m_Grid[0].size(); j++ )
		{
			egn::FloatRect rect = egn::FloatRect( m_BasePosition.x + j * 50 + j*5, m_BasePosition.y + i * 50 + i*5, 50, 50 );
			window.drawRect( rect, egn::Color( 187, 173, 160 ) );

			if( m_Grid[i][j].get() != 0 )
			{
				m_Grid[i][j].draw( window );
			}
		}
	}

	for( int i = 0; i < m_MoveNumber.size(); i++ )
	{
		m_MoveNumber[i].draw( window );
	}
}