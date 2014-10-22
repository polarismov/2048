#include "MenuPseudo.hpp"

#include "../egn/Keyboard.hpp"
#include "../egn/TextureManager.hpp"
#include "../egn/FontManager.hpp"

#include "../GameState.hpp"

#include <iostream>
#include <sstream>

gui::MenuPseudo::MenuPseudo()
{

}

gui::MenuPseudo::~MenuPseudo()
{

}

void gui::MenuPseudo::update()
{
	std::string buffer = "";

	if ( egn::Keyboard::isActive("A") && m_Pseudo.size() < 20 )
    {
        buffer = "A"; 
        egn::Keyboard::setActive("A", false);
    }
    else if ( egn::Keyboard::isActive("B") && m_Pseudo.size() < 20  )
    {
        buffer = "B";
        egn::Keyboard::setActive("B", false);
    }
    else if ( egn::Keyboard::isActive("C") && m_Pseudo.size() < 20 )
    {
        buffer = "C"; 
        egn::Keyboard::setActive("C", false);
    }
    else if ( egn::Keyboard::isActive("D") && m_Pseudo.size() < 20 )
    {
        buffer = "D"; 
        egn::Keyboard::setActive("D", false);
    }
    else if ( egn::Keyboard::isActive("E")  && m_Pseudo.size() < 20)
    {
        buffer = "E"; 
        egn::Keyboard::setActive("E", false);
    }
    else if ( egn::Keyboard::isActive("F")  && m_Pseudo.size() < 20)
    {
        buffer = "F"; 
        egn::Keyboard::setActive("F", false);
    }
    else if ( egn::Keyboard::isActive("G") && m_Pseudo.size() < 20 )
    {
        buffer = "G"; 
        egn::Keyboard::setActive("G", false);
    }
    else if ( egn::Keyboard::isActive("H")  && m_Pseudo.size() < 20)
    {
        buffer = "H"; 
        egn::Keyboard::setActive("H", false);
    }
    else if ( egn::Keyboard::isActive("I")  && m_Pseudo.size() < 20)
    {
        buffer = "I"; 
        egn::Keyboard::setActive("I", false);
    }
    else if ( egn::Keyboard::isActive("J")  && m_Pseudo.size() < 20)
    {
        buffer = "J"; 
        egn::Keyboard::setActive("J", false);
    }
    else if ( egn::Keyboard::isActive("K")  && m_Pseudo.size() < 20)
    {
        buffer = "K"; 
        egn::Keyboard::setActive("K", false);
    }
    else if ( egn::Keyboard::isActive("L")  && m_Pseudo.size() < 20)
    {
        buffer = "L"; 
        egn::Keyboard::setActive("L", false);
    }
    else if ( egn::Keyboard::isActive("M") && m_Pseudo.size() < 20 )
    {
        buffer = "M"; 
        egn::Keyboard::setActive("M", false);
    }
    else if ( egn::Keyboard::isActive("N")  && m_Pseudo.size() < 20)
    {
        buffer = "N"; 
        egn::Keyboard::setActive("N", false);
    }
    else if ( egn::Keyboard::isActive("O") && m_Pseudo.size() < 20 )
    {
        buffer = "O"; 
        egn::Keyboard::setActive("O", false);
    }
    else if ( egn::Keyboard::isActive("P")  && m_Pseudo.size() < 20)
    {
        buffer = "P"; 
        egn::Keyboard::setActive("P", false);
    }
    else if ( egn::Keyboard::isActive("Q") && m_Pseudo.size() < 20 )
    {
        buffer = "Q"; 
        egn::Keyboard::setActive("Q", false);
    }
    else if ( egn::Keyboard::isActive("R") && m_Pseudo.size() < 20 )
    {
        buffer = "R"; 
        egn::Keyboard::setActive("R", false);
    }
    else if ( egn::Keyboard::isActive("S") && m_Pseudo.size() < 20 )
    {
        buffer = "S"; 
        egn::Keyboard::setActive("S", false);
    }
    else if ( egn::Keyboard::isActive("T") && m_Pseudo.size() < 20 )
    {
        buffer = "T"; 
        egn::Keyboard::setActive("T", false);
    }
    else if ( egn::Keyboard::isActive("U") && m_Pseudo.size() < 20 )
    {
        buffer = "U"; 
        egn::Keyboard::setActive("U", false);
    }
    else if ( egn::Keyboard::isActive("V") && m_Pseudo.size() < 20 )
    {
        buffer = "V"; 
        egn::Keyboard::setActive("V", false);
    }
    else if ( egn::Keyboard::isActive("W")  && m_Pseudo.size() < 20 )
    {
        buffer = "W"; 
        egn::Keyboard::setActive("W", false);
    }
    else if ( egn::Keyboard::isActive("X") && m_Pseudo.size() < 20 )
    {
        buffer = "X"; 
        egn::Keyboard::setActive("X", false);
    }
    else if ( egn::Keyboard::isActive("Y") && m_Pseudo.size() < 20 )
    {
        buffer = "Y"; 
        egn::Keyboard::setActive("Y", false);
    }
    else if ( egn::Keyboard::isActive("Z") && m_Pseudo.size() < 20)
    {
        buffer = "Z"; 
        egn::Keyboard::setActive("Z", false);
    }
    else if ( egn::Keyboard::isActive("0") && m_Pseudo.size() < 20 )
    {
        buffer = "0"; 
        egn::Keyboard::setActive("0", false);
    }
    else if ( egn::Keyboard::isActive("1") && m_Pseudo.size() < 20 )
    {
        buffer = "1"; 
        egn::Keyboard::setActive("1", false);
    }
    else if ( egn::Keyboard::isActive("2") && m_Pseudo.size() < 20 )
    {
        buffer = "2"; 
        egn::Keyboard::setActive("2", false);
    }
    else if ( egn::Keyboard::isActive("3") && m_Pseudo.size() < 20 )
    {
        buffer = "3"; 
        egn::Keyboard::setActive("3", false);
    }
    else if ( egn::Keyboard::isActive("4") && m_Pseudo.size() < 20 )
    {
        buffer = "4"; 
        egn::Keyboard::setActive("4", false);
    }
    else if ( egn::Keyboard::isActive("5") && m_Pseudo.size() < 20 )
    {
        buffer = "5"; 
        egn::Keyboard::setActive("5", false);
    }
    else if ( egn::Keyboard::isActive("6") && m_Pseudo.size() < 20 )
    {
        buffer = "6"; 
        egn::Keyboard::setActive("6", false);
    }
    else if ( egn::Keyboard::isActive("7") && m_Pseudo.size() < 20 )
    {
        buffer = "7"; 
        egn::Keyboard::setActive("7", false);
    }
    else if ( egn::Keyboard::isActive("8") && m_Pseudo.size() < 20 )
    {
        buffer = "8"; 
        egn::Keyboard::setActive("8", false);
    }
    else if ( egn::Keyboard::isActive("9") && m_Pseudo.size() < 20 )
    {
        buffer = "9"; 
        egn::Keyboard::setActive("9", false);
    }
   
   if( buffer != "" ) m_Pseudo += buffer;

   if( egn::Keyboard::isActive("return") )
	{
		GameState::set(GS_PLAY);
		egn::Keyboard::setActive( "return", false );
	}
}
void gui::MenuPseudo::draw( egn::Window& window )
{
	window.drawRect(egn::FloatRect (300, 158, 250, 30), egn::Color(0xF5, 0xF6, 0xCE));
	egn::FontManager::get()->write(window, "shoes", "Entree votre pseudo", egn::Vector2f(10,158), 20, egn::Color::Black);
	egn::FontManager::get()->write(window, "shoes", m_Pseudo, egn::Vector2f(305,158), 20, egn::Color::Black);
}

void gui::MenuPseudo::set(  const std::string& var, std::string value )
{

}

std::string gui::MenuPseudo::getPseudo()
{
	return m_Pseudo;
}

