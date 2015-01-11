#include "Grid.hpp"

#include "../egn/GameTime.hpp"
#include "../egn/Keyboard.hpp"
#include "../egn/FontManager.hpp"

#include "../GameState.hpp"

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
	m_Continue = false;
	
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


bool grid::Grid::isFull()
{
	bool full = true;
	for( int i = 0; i < m_Grid.size(); i++ )
	{
		for( int j = 0; j < m_Grid[0].size(); j++ )
		{
			if( m_Grid[i][j].get() == 0 ) 
			{
				full = false;
				break;
			}
		}
	}

	return full;
}

bool grid::Grid::moveIsPossible()
{
	bool possible = false;
	for( int i = 0; i < m_Grid.size(); i++ )
	{
		for( int j = 0; j < m_Grid[0].size(); j++ )
		{
			if( j > 0 )
			{
				if( m_Grid[i][j].get() == m_Grid[i][j-1].get() )
				{
					possible = true;
				}
			}

			if( j < m_Grid[0].size() - 1 )
			{
				if( m_Grid[i][j].get() == m_Grid[i][j+1].get() )
				{
					possible = true;
				}
			}

			if( i > 0 )
			{
				if( m_Grid[i][j].get() == m_Grid[i-1][j].get() )
				{
					possible = true;
				}
			}

			if( i < m_Grid.size() - 1 )
			{
				if( m_Grid[i][j].get() == m_Grid[i+1][j].get() )
				{
					possible = true;
				}
			}
		}
	}
	return possible;
}

bool grid::Grid::moveIsPossible( Direction direction )
{
	bool possible = false;
	
	switch( direction )
	{
		case Direction::UP:
		for( int i = 0; i < m_Grid.size(); i++ )
		{
			for( int j = 0; j < m_Grid[0].size(); j++ )
			{
				if( m_Grid[i][j].get() == 0 ) continue;
				
				for( int k = i-1; k >= 0; k-- )
				{
						if( m_Grid[i][j].get() == m_Grid[k][j].get() ) possible = true;
						else break;
						
				}
			}
			
			if( possible ) break;
		}
		break;
		
		case Direction::DOWN:
		for( int i = m_Grid.size() - 1; i >= 0; i-- )
		{
			for( int j = m_Grid[0].size() - 1; j >= 0; j-- )
			{
				if( m_Grid[i][j].get() == 0 ) continue;
				
				for( int k = i+1; k < m_Grid.size(); k++ )
				{
					if( m_Grid[i][j].get() == m_Grid[k][j].get() ) possible = true;
					else break;
				}
				
			}
			
			if( possible ) break;
			
		}
		break;
		
		case Direction::LEFT:
		for( int i = 0; i < m_Grid.size(); i++ )
		{
			for( int j = 0; j < m_Grid[0].size(); j++ )
			{
				if( m_Grid[i][j].get() == 0 ) continue;
				

				for( int k = j-1; k >= 0; k--)
				{
					if( m_Grid[i][j].get() == m_Grid[i][k].get() ) possible = true;
					else break;
				}
				
			}
			
			if( possible ) break;
			
		}
		break;
		
		case Direction::RIGHT:
		for( int i = 0; i < m_Grid.size(); i++ )
		{
			for( int j = m_Grid[0].size() - 1; j >= 0; j-- )
			{
				if( m_Grid[i][j].get() == 0 ) continue;
				
				for( int k = j+1; k < m_Grid[0].size(); k++ )
				{
					if( m_Grid[i][j].get() == m_Grid[i][k].get() ) possible = true;
					else break;
				}
				
			}
			
			if( possible ) break;
			
		}
		break;
	}
	return possible;
}

void grid::Grid::cheat( int value )
{
	bool n = true;
	while( n )
	{
		int x = egn::GameTime::getRandomInt( 0, m_Size );
		int y = egn::GameTime::getRandomInt( 0, m_Size );

		if( m_Grid[y][x].get() == 0 )
		{
			m_Grid[y][x].set( value );
			n = false;
		}
	}
}

void grid::Grid::popNumber( int n )
{
	std::vector<ref> tmp_ref_list;
	for( int i = 0; i < m_Grid.size(); i++ )
	{
		for( int j = 0; j < m_Grid[0].size(); j++ )
		{
			if( m_Grid[i][j].get() == 0 )
			{
				ref tmp;
				tmp.i = i;
				tmp.j = j;
				tmp_ref_list.push_back( tmp );
			}
		}
	}
	while( n )
	{
		int gen = egn::GameTime::getRandomInt( 0, tmp_ref_list.size() );

		int percent = egn::GameTime::getRandomInt( 0, 101 );
		if( percent < 95 )
		{
			m_Grid[tmp_ref_list[gen].i][tmp_ref_list[gen].j].set( 2 );
		}
		else 
		{
			m_Grid[tmp_ref_list[gen].i][tmp_ref_list[gen].j].set( 4 );
		}
		tmp_ref_list.erase( tmp_ref_list.begin() + gen );
		n--;

	}
}

void grid::Grid::update()
{

	if( egn::Keyboard::isActive( "return" ) )
	{
		GameState::set( Gamestate::MENU_PAUSE );
		egn::Keyboard::setActive("return",false);
	}

	if( egn::Keyboard::isActive( "space" ) )
	{
		cheat( 1024 );
		egn::Keyboard::setActive( "space", false );
	}


	if( m_InMove == false )
	{
		if( egn::Keyboard::isActive("up") )
		{
			move(Direction::UP);
			egn::Keyboard::setActive("up",false);
		}
		else if( egn::Keyboard::isActive("down") )
		{
			move(Direction::DOWN);
			egn::Keyboard::setActive("down",false);
		}
		else if( egn::Keyboard::isActive("left") )
		{
			move(Direction::LEFT);
			egn::Keyboard::setActive("left",false);
		}
		else if( egn::Keyboard::isActive("right") )
		{
			move(Direction::RIGHT);
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
			if( m_Grid[ref_tmp.i][ref_tmp.j].get() == 2048 && m_Continue == false && !m_Challenge )
			{
				m_Continue = true;
				GameState::set(Gamestate::MENU_CONTINUE);
				m_InMove = false;
			}
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
		if( !moveIsPossible( m_Direction ) )
		{
			m_InMove = false;
			if( !isFull() ) 
			{
				popNumber( 1 );
			}	
		}
		else 
		{
			move( m_Direction );
		}
	}

	m_PlayerInfo.update();
}

void grid::Grid::move( Direction direction )
{
	m_InMove = true;
	m_Direction = direction;
	switch( direction )
	{
		case Direction::UP:
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
							m_PlayerInfo.setScore(m_PlayerInfo.getScore() + m_Grid[i][j].get()*2);
						}
						m_Grid[i][j].set( 0 );
						number.move( Direction::UP, ref_tmp );
						m_MoveNumber.push_back( number );
					}
				}
			}
		}
		break;

		case Direction::DOWN:
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
							m_PlayerInfo.setScore(m_PlayerInfo.getScore() + m_Grid[i][j].get()*2);
						}
						m_Grid[i][j].set( 0 );
						number.move( Direction::DOWN, ref_tmp );
						m_MoveNumber.push_back( number );
					}
				}
			}
		}
		break;

		case Direction::LEFT:
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
							m_PlayerInfo.setScore(m_PlayerInfo.getScore() + m_Grid[i][j].get()*2);
						}
						m_Grid[i][j].set( 0 );
						number.move( Direction::LEFT, ref_tmp );
						m_MoveNumber.push_back( number );
					}
				}
			}
		}
		break;

		case Direction::RIGHT:
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
							m_PlayerInfo.setScore(m_PlayerInfo.getScore() + m_Grid[i][j].get()*2);
						}
						m_Grid[i][j].set( 0 );
						number.move( Direction::RIGHT, ref_tmp );
						m_MoveNumber.push_back( number );
					}
				}
			}
		}
		break;
	}

	if( isFull() && !moveIsPossible() )
	{
		if( m_Continue && !m_Challenge )
		{
			GameState::set( Gamestate::MENU_WIN );
		}
		else 
		{
			if( !m_Challenge ) GameState::set( Gamestate::MENU_LOSE );
		}
		
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

bool grid::Grid::getContinue()
{
	return m_Continue;
}

grid::PlayerInfo& grid::Grid::getPlayerInfo()
{
	return m_PlayerInfo;
}

bool grid::Grid::getChallenge()
{
	return m_Challenge;
}

void grid::Grid::setChallenge( bool challenge )
{
	m_Challenge = challenge;
}
