#include "GameState.hpp"

Gamestate GameState::s_State;
Gamestate GameState::s_PreviousState;

void GameState::set( Gamestate state )
{
	if( s_State != Gamestate::PLAY && s_State != Gamestate::MENU_PAUSE && s_State != Gamestate::SET_PSEUDO && s_State != Gamestate::MENU_PSEUDO && s_State != Gamestate::MENU_CONTINUE )
		s_PreviousState = s_State;
	s_State = state;
}

Gamestate GameState::get()
{
	return s_State;
}

Gamestate GameState::previous()
{
	return s_PreviousState;
}
