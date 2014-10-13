#ifndef GRID_HPP
#define GRID_HPP


#include <list>

#include "../egn/Window.hpp"

#include "Number.hpp"


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


		void setSize( int size );


		void popNumber( int n );


		void generateAllNumber();


		void move( DIR direction );

		/* retourne true si la grille est remplie */
		bool isFull();

		/* retourne true si deux cases cote à cote ont la même valeur */
		bool moveIsPossible();

	private:
		egn::Sprite m_BlankScare;

		std::vector<std::vector<grid::Number> > m_Grid;
		std::vector<grid::Number> m_MoveNumber;

		int m_Size;

		egn::Vector2f m_BasePosition;

		bool m_InMove;
	};
}






#endif