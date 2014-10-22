#ifndef GUI_MENUCLASSEMENT_HPP
#define GUI_MENUCLASSEMENT_HPP

#include "GuiBase.hpp"

#include "../DataManager.hpp"

namespace gui
{
	class MenuClassement : public gui::GuiBase
	{
	public:
		MenuClassement();
		~MenuClassement();

		virtual void update();

		virtual void draw( egn::Window& window );

		virtual void set( const std::string& var, int value );
        virtual void set( const std::string& var, std::string value );
    private:
        static bool sort_by_score( player p1, player p2 );
        static bool sort_by_time( player p1, player p2 );

        void updateCursor( int value );
	private:
		std::vector<player> m_ResultByScore;
		std::vector<player> m_ResultByTime;

		int m_TypeClassement;

		int m_Cursor;
	};
}



#endif