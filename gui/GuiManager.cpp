#include "GuiManager.hpp"


gui::GuiManager::GuiManager()
{
    //ctor
}

gui::GuiManager::~GuiManager()
{

    std::map<std::string, gui::GuiBase*>::iterator it;
    for( it = m_Gui.begin(); it != m_Gui.end(); ++it )
    {
        delete (*it).second;
    }

}

void gui::GuiManager::add( gui::GuiBase* gui, const std::string& name )
{
    if( m_Gui.find( name ) == m_Gui.end() )
    {
        m_Gui[name] = gui;
    }
}

void gui::GuiManager::update( const std::string& name )
{
    if( m_Gui.find( name ) != m_Gui.end() )
    {
        m_Gui[name]->update();
    }
}

void gui::GuiManager::draw( const std::string& name, egn::Window& window )
{
    if( m_Gui.find( name ) != m_Gui.end() )
    {
        m_Gui[name]->draw( window );
    }
}

gui::GuiBase* gui::GuiManager::getMenu( const std::string& name )
{
    return m_Gui[name];
}


