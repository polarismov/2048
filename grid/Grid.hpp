#ifndef GRID_HPP
#define GRID_HPP


#include "../egn/Window.hpp"

#include "Number.hpp"


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

	private:
		egn::Sprite m_BlankScare;

		std::vector<std::vector<grid::Number> > m_Grid;

		int m_Size;

		egn::Vector2f m_BasePosition;
	};
}






#endif