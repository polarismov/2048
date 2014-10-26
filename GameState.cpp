#include "GameState.hpp"

GS GameState::s_State;
GS GameState::s_PreviousState;

void GameState::set( GS state )
{
	if( s_State != GS_PLAY && s_State != GS_MENU_PAUSE && s_State != GS_SET_PSEUDO && s_State != GS_MENU_PSEUDO )
		s_PreviousState = s_State;
	s_State = state;
}

GS GameState::get()
{
	return s_State;
}

GS GameState::previous()
{
	return s_PreviousState;
}