#ifndef COMMON_HPP
#define COMMON_HPP


enum class Direction 
{ 
	UP,
	DOWN,
	LEFT,
	RIGHT,
	NONE
};

enum class Gamestate
{
	MENU_START,
	MENU_PLAY,
	MENU_OPTION,
	PLAY,
	SET_4X4_PLAY,
	SET_5X5_PLAY,
	SET_6X6_PLAY,
	SET_PSEUDO,
	MENU_WIN,
	MENU_LOSE,
	MENU_PAUSE,
	MENU_CONTINUE,
	MENU_PSEUDO,
	MENU_CLASSEMENT,
	UPDATE_CLASSEMENT,
	EXIT
};


struct ref
{
	int i;
	int j;
};


#endif
