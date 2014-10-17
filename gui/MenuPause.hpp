#ifndef GUI_MENUPAUSE_HPP
#define GUI_MENUPAUSE_HPP


#include "../egn/Window.hpp"

#include "GuiBase.hpp"


namespace gui
{
	class MenuPause : public gui::GuiBase 
	{
	public:
		MenuPause();
		~MenuPause();

		virtual void update();

		virtual void draw( egn::Window& window );

		virtual void set( const std::string& var, std::string value );
		virtual void set( const std::string& var, int value );
	private:
		void updateCursor( int value );
	private:
		egn::Sprite m_Button[2];

		int m_Cursor;
	};
}






#endif