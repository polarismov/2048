#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP


enum gamesate
{
	GS_MENU_START,
	GS_MENU_PLAY,
	GS_MENU_OPTION,
	GS_PLAY,
	GS_SET_EASY_PLAY,
	GS_SET_MEDIUM_PLAY,
	GS_SET_HARD_PLAY,
	GS_EXIT
} typedef GS;


class GameState
{
public:
	static void set( GS state );
	static GS get();
private:
	static GS s_State;
};





#endif