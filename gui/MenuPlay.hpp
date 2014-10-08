#ifndef GUI_MENUPLAY_HPP
#define GUI_MENUPLAY_HPP

#include "../egn/Window.hpp"
#include "GuiBase.hpp"
namespace gui {

class MenuPlay : public GuiBase
{
    public:
        MenuPlay();
        virtual ~MenuPlay();
        virtual void update();
        virtual void draw(egn::Window& window);
    protected:
    private:
        void updateCursor(int value);
    private:
        int m_Cursor;
};

} // namespace gui

#endif // GUI_MENUPLAY_HPP
