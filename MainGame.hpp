#ifndef MAINGAME_HPP
#define MAINGAME_HPP


#include "egn/Window.hpp"

#include "gui/GuiManager.hpp"

class MainGame
{
public:
    MainGame();
    ~MainGame();

    void loop();
protected:
private:
    egn::Window m_Window;
    gui::GuiManager m_GuiMgr;

};

#endif // MAINGAME_HPP
