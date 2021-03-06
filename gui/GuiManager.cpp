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

void gui::GuiManager::set( const std::string& menu, const std::string& var, int value )
{
    if( m_Gui.find( menu ) != m_Gui.end() )
    {
        m_Gui[menu]->set( var, value );
    }
    else 
    {
        std::cerr << menu << " n'existe pas" << std::endl;
    }
}

void gui::GuiManager::set( const std::string& menu, const std::string& var, std::string value )
{
    if( m_Gui.find( menu ) != m_Gui.end() )
    {
        m_Gui[menu]->set( var, value );
    }
    else 
    {
        std::cerr << menu << " n'existe pas" << std::endl;
    }
}

std::string gui::GuiManager::get_string( const std::string& menu, const std::string& var )
{
    std::string value = "";
    if( m_Gui.find( menu ) != m_Gui.end() )
    {
        value = m_Gui[menu]->get_string( var );
    }
    else 
    {
        std::cerr << menu << " n'existe pas" << std::endl;
    }
    return value;

}
int gui::GuiManager::get_int( const std::string& menu, const std::string& var )
{
    int value = -1;
    if( m_Gui.find( menu ) != m_Gui.end() )
    {
        value = m_Gui[menu]->get_int( var );
    }
    else 
    {
        std::cerr << menu << " n'existe pas" << std::endl;
    }
    return value;
}

gui::GuiBase* gui::GuiManager::getMenu( const std::string& name )
{
    return m_Gui[name];
}


