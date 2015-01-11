#ifndef GUI_CHALLENGELOSE_HPP
#define GUI_CHALLENGELOSE_HPP


#include "GuiBase.hpp"

#include "../egn/Sprite.hpp"


namespace gui
{
	class ChallengeLose : public gui::GuiBase
	{
	public:
		ChallengeLose();
		~ChallengeLose();

		virtual void update();

		virtual void draw( egn::Window& window );

		virtual void set( const std::string& var, std::string value );
		virtual void set( const std::string& var, int value );
	private:
		void updateCursor( int value );
	private:
		int m_Score;
		int m_BestScore;
		float m_Time;

		int m_Cursor;

		egn::Sprite m_Button[2];
	};
}





#endif