#ifndef MAINGAME_HPP
#define MAINGAME_HPP

#include "gui/GuiManager.hpp"

#include "grid/Grid.hpp"

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
    grid::Grid m_Grid;

};

#endif // MAINGAME_HPP
