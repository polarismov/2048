#include "GameState.hpp"

GS GameState::s_State;

void GameState::set( GS state )
{
	s_State = state;
}

GS GameState::get()
{
	return s_State;
}