#ifndef GUI_MENUCHALLENGE_HPP
#define GUI_MENUCHALLENGE_HPP

#include "../DataManager.hpp"

#include "../egn/Window.hpp"

#include "GuiBase.hpp"

namespace gui
{
	
	class MenuChallenge : public gui::GuiBase
	{
		public:
		MenuChallenge();
		~MenuChallenge();
		
		virtual void update();
		
		virtual void draw( egn::Window& window );

		virtual void set( const std::string& var, int value );
        virtual void set( const std::string& var, std::string value );
        
		virtual int get_int( const std::string& var );

		private:
		void updateCursor( int value );
		void updateCursorHorizontal( int value);
	    
	    private:
		egn::Sprite m_Button[2];

		int m_Cursor;
		int m_CursorH;
	};
	
}




#endif
