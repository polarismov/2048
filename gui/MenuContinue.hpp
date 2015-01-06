#ifndef GUI_MENUCONTINUE_HPP
#define GUI_MENUCONTINUE_HPP

#include "../egn/Window.hpp"

#include "GuiBase.hpp"

namespace gui
{
	
	class MenuContinue : public GuiBase
	{
	public:
		MenuContinue();
		~MenuContinue();
		
		virtual void update();
		
		virtual void draw( egn::Window& window );

	private:
		void updateCursor( int value );
	private:
		egn::Sprite m_Button[2];

		int m_Cursor;
	};
	
}








#endif