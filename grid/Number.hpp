#ifndef GRID_NUMBER_HPP
#define GRID_NUMBER_HPP

#include "../egn/Window.hpp"

#include "../Common.hpp"

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
		void setDraw( bool value );

		void setPosition( egn::FloatRect rect );
		void setNextPosition( egn::FloatRect rect );

		void move( DIR direction, ref next_vector_index );
		bool inMove();

		egn::FloatRect getPosition();
		egn::FloatRect getStartPosition();

		ref getRef();
	private:
		int m_Value;

		egn::FloatRect m_Position;
		egn::FloatRect m_NextPosition;

		bool m_InMove;
		DIR m_Direction;

		ref m_NextVectorIndex;

		bool m_Draw;
	};
}




#endif