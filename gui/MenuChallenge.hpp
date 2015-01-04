#ifndef GUI_MENUCHALLENGE_HPP
#define GUI_MENUCHALLENGE_HPP


namespace gui
{
	
	class MenuChallenge : public GuiBase
	{
		public:
		MenuChallenge();
		~MenuChallenge();
		
		virtual void update();
		
		virtual void draw( egn::Window& window );
	};
	
}








#endif
