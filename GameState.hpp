#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP


enum gamesate
{
	GS_MENU_START,
	GS_MENU_PLAY,
	GS_MENU_OPTION,
	GS_PLAY,
	GS_SET_4X4_PLAY,
	GS_SET_5X5_PLAY,
	GS_SET_6X6_PLAY,
	GS_MENU_WIN,
	GS_MENU_LOSE,
	GS_MENU_PAUSE,
	GS_MENU_CLASSEMENT,
	GS_UPDATE_CLASSEMENT,
	GS_EXIT
} typedef GS;


class GameState
{
public:
	static void set( GS state );
	static GS get();
	static GS previous();
private:
	static GS s_State;
	static GS s_PreviousState;
};





#endif