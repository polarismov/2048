#ifndef GRID_HPP
#define GRID_HPP


#include "../egn/Window.hpp"


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


		void popNumber();


		void generateAllNumber();

	private:
		egn::Sprite m_BlankScare;

		std::vector<std::vector<int> > m_Grid;

		int m_Size;

		egn::Vector2f m_BasePosition;
	};
}






#endif