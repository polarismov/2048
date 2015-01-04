#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP


#include "Common.hpp"


class GameState
{
public:
	static void set( Gamestate state );
	static Gamestate get();
	static Gamestate previous();
private:
	static Gamestate s_State;
	static Gamestate s_PreviousState;
};





#endif
