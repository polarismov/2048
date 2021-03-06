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

        /* ajouter un pointeur sur menu qui a hérité de GuiBase */
        void add( gui::GuiBase* guiBase, const std::string& name );

        void update( const std::string& name );

        void draw( const std::string& name, egn::Window& window );

        void set( const std::string& menu, const std::string& var, int value );
        void set( const std::string& menu, const std::string& var, std::string value );

        std::string get_string( const std::string& menu, const std::string& var );
        int get_int( const std::string& menu, const std::string& var );

        gui::GuiBase* getMenu( const std::string& name );
    protected:
    private:
        std::map<std::string, gui::GuiBase*> m_Gui;
};

} // namespace gui

#endif // GUI_GUIMANAGER_HPP
