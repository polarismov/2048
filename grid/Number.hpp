#ifndef GRID_NUMBER_HPP
#define GRID_NUMBER_HPP

#include "../egn/Window.hpp"

namespace grid
{
	class Number
	{
	public:
		Number( int val, egn::FloatRect rect );
		~Number();

		void set( int value );
		int get();

		void update();

		void draw( egn::Window& window );

		egn::FloatRect getPosition();
		egn::FloatRect getStartPosition();
	private:
		int m_Value;

		egn::FloatRect m_Position;
		egn::FloatRect m_StartPosition;
	};
}




#endif