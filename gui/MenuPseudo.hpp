#ifndef GUI_MENUPSEUDO_HPP
#define GUI_MENUPSEUDO_HPP

#include "../egn/Window.hpp"
#include "GuiBase.hpp"

namespace gui {

class MenuPseudo : public GuiBase
{
    public:
        MenuPseudo();
        ~MenuPseudo();

        virtual void update();

        virtual void draw( egn::Window& window );
		
        virtual std::string get_string( const std::string& var );
    protected:
    private:
    	std::string m_Pseudo;
};

} 

#endif 