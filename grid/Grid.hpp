#ifndef GRID_HPP
#define GRID_HPP


#include <list>

#include "../egn/Window.hpp"

#include "Number.hpp"
#include "PlayerInfo.hpp"

#include "../Common.hpp"


namespace grid 
{
	class Grid
	{
	public:
		Grid();
		~Grid();


		void update();


		void draw( egn::Window& window );


		/* taille de la grille */
		void setSize( int size );


		/* générer n nombres */
		void popNumber( int n );

		/* faire un déplacement sur la grille */
		void move( DIR direction );

		/* fonction de triche */
		void cheat( int value );

		/* retourne true si la grille est remplie */
		bool isFull();

		/* retourne true si deux cases cote à cote ont la même valeur */
		bool moveIsPossible();

		grid::PlayerInfo& getPlayerInfo();

	private:
		egn::Sprite m_BlankScare;

		std::vector<std::vector<grid::Number> > m_Grid;
		std::vector<grid::Number> m_MoveNumber;

		int m_Size;

		egn::Vector2f m_BasePosition;

		bool m_InMove;

		grid::PlayerInfo m_PlayerInfo;
		
	};
}






#endif