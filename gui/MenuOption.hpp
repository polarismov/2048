#ifndef GUI_MENUOPTION_HPP
#define GUI_MENUOPTION_HPP

#include "../egn/Window.hpp"
#include "GuiBase.hpp"
namespace gui
{
class MenuOption : public gui::GuiBase
{
public:
    MenuOption();
    virtual ~MenuOption();
    virtual void update();
    virtual void draw(egn::Window& window);
protected:
private:
    void updateCursor(int value);
private:
    int m_Cursor;
    egn::Sprite m_Button[2];
};
}
#endif // GUI_MENUOPTION_HPP
