#ifndef EGN_KEYBOARD_HPP
#define EGN_KEYBOARD_HPP

#include <iostream>

#include "Event.hpp"

namespace egn
{

class Keyboard
{
public:
    static void init();

    /* renvoie true si la touche key_str est appuyée */
    static bool isActive( const std::string& key_str );
    static void setActive( const std::string& key_str, bool value );

    static void listenEvent( egn::Event& event );
    static void listenMinimalEvent( egn::Event& event );
protected:
private:
    static std::string keyToStr( sf::Keyboard::Key key );
private:
    static std::map<std::string, bool> s_Keys;
};

} // namespace egn

#endif // EGN_KEYBOARD_HPP
