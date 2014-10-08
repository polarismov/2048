#ifndef GUI_GUIMANAGER_HPP
#define GUI_GUIMANAGER_HPP

#include <iostream>
#include <map>
#include "GuiBase.hpp"
#include "../egn/Window.hpp"

namespace gui {

class GuiManager
{
    public:
        GuiManager();
        ~GuiManager();

        void add( gui::GuiBase* guiBase, const std::string& name );

        void update( const std::string& name );

        void draw( const std::string& name, egn::Window& window );
    protected:
    private:
        std::map<std::string, gui::GuiBase*> m_Gui;
};

} // namespace gui

#endif // GUI_GUIMANAGER_HPP
