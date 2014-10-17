#ifndef GUI_MENUWIN_HPP
#define GUI_MENUWIN_HPP 

#include "GuiBase.hpp"
#include "../egn/Sprite.hpp"

namespace gui
{
	class MenuWin : public gui::GuiBase
	{
	public:
		MenuWin();
		~MenuWin();

		 virtual void update();

        virtual void draw( egn::Window& window );

        virtual void set( const std::string& var, int value );
        virtual void set( const std::string& var, std::string value );
	private:
		int m_Score;
		float m_Time;
		int m_BestScore;
		int m_Cursor;
		egn::Sprite m_Button[2];
	private:
        void updateCursor(int value);
        
	};
}
#endif