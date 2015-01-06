#include "GuiBase.hpp"



gui::GuiBase::GuiBase()
{
    //ctor
}

gui::GuiBase::~GuiBase()
{
    //dtor
}

void gui::GuiBase::update()
{
    //update
}

void gui::GuiBase::draw( egn::Window& window )
{
    //draw
}


void gui::GuiBase::set( const std::string& var, int value )
{
	//set
}

void gui::GuiBase::set( const std::string& var, std::string value )
{
	//set
}

void gui::GuiBase::set( const std::string& var, bool value )
{
	//set
}

std::string gui::GuiBase::get_string( const std::string& var )
{
	return "";
}


int gui::GuiBase::get_int( const std::string& var )
{
	return -1;
}



