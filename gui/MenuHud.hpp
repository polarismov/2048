#ifndef GUI_MENUHUD_HPP
#define GUI_MENUHUD_HPP

#include <iostream>
#include "GuiBase.hpp"

namespace gui
{
	class MenuHud : public gui::GuiBase
	{
	public:
		MenuHud();
		~MenuHud();

        virtual void update();

        virtual void draw( egn::Window& window );

        virtual void set( const std::string& var, int value );
        virtual void set( const std::string& var, std::string value );
	private:
		int m_Score;
		float m_Time;
		int m_BestScore;
		
	};
}

#endif