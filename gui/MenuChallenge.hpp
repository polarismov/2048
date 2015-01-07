#ifndef GUI_MENUCHALLENGE_HPP
#define GUI_MENUCHALLENGE_HPP

#include "../egn/Window.hpp"

#include "GuiBase.hpp"

namespace gui
{
	
	class MenuChallenge : public GuiBase
	{
		public:
		MenuChallenge();
		~MenuChallenge();
		
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
