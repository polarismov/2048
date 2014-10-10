#ifndef GUI_MENUSTART_HPP
#define GUI_MENUSTART_HPP

#include "../egn/Window.hpp"

#include "GuiBase.hpp"

namespace gui {

class MenuStart : public GuiBase
{
    public:
        MenuStart();
        ~MenuStart();

        virtual void update();

        virtual void draw( egn::Window& window );
    protected:
    private:
        void updateCursor( int value );
    private:
        int m_Cursor;
        egn::Sprite m_Button[2];
};

} // namespace gui

#endif // GUI_MENUSTART_HPP
