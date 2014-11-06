#include "Keyboard.hpp"

std::map<std::string, bool> egn::Keyboard::s_Keys;

void egn::Keyboard::init()
{
    s_Keys["quit"]      = false;
    s_Keys["escape"]    = false;
    s_Keys["up"]        = false;
    s_Keys["down"]      = false;
    s_Keys["left"]      = false;
    s_Keys["right"]     = false;
    s_Keys["space"]     = false;
    s_Keys["return"]    = false;
    s_Keys["backSpace"] = false;
    s_Keys["A"]         = false;
    s_Keys["B"]         = false;
    s_Keys["C"]         = false;
    s_Keys["D"]         = false;
    s_Keys["E"]         = false;
    s_Keys["F"]         = false;
    s_Keys["G"]         = false;
    s_Keys["H"]         = false;
    s_Keys["I"]         = false;
    s_Keys["J"]         = false;
    s_Keys["K"]         = false;
    s_Keys["L"]         = false;
    s_Keys["M"]         = false;
    s_Keys["N"]         = false;
    s_Keys["O"]         = false;
    s_Keys["P"]         = false;
    s_Keys["Q"]         = false;
    s_Keys["R"]         = false;
    s_Keys["S"]         = false;
    s_Keys["T"]         = false;
    s_Keys["U"]         = false;
    s_Keys["V"]         = false;
    s_Keys["W"]         = false;
    s_Keys["X"]         = false;
    s_Keys["Y"]         = false;
    s_Keys["Z"]         = false;
    s_Keys["0"]         = false;
    s_Keys["1"]         = false;
    s_Keys["2"]         = false;
    s_Keys["3"]         = false;
    s_Keys["4"]         = false;
    s_Keys["5"]         = false;
    s_Keys["6"]         = false;
    s_Keys["7"]         = false;
    s_Keys["8"]         = false;
    s_Keys["9"]         = false;


}


bool egn::Keyboard::isActive( const std::string& key_str )
{
    if( s_Keys.find( key_str ) != s_Keys.end() )
    {
        return s_Keys[key_str];
    }
    std::cerr << key_str << " n'existe pas!!" << std::endl;
    return false;
}

void egn::Keyboard::setActive( const std::string& key_str, bool value )
{
    if( s_Keys.find( key_str ) != s_Keys.end() )
    {
        s_Keys[key_str] = value;
    }
}

void egn::Keyboard::listenEvent( egn::Event& event )
{
    if( event.type == sf::Event::Closed )
    {
        s_Keys["quit"] = true;
    }

    if( event.type == sf::Event::KeyPressed )
    {
        if( s_Keys.find(keyToStr(event.key.code)) != s_Keys.end() )
        {
            s_Keys[keyToStr(event.key.code)] = true;
        }
    }

    if( event.type == sf::Event::KeyReleased )
    {
        if( s_Keys.find(keyToStr(event.key.code)) != s_Keys.end() )
        {
            s_Keys[keyToStr(event.key.code)] = false;
        }
    }
}

std::string egn::Keyboard::keyToStr( sf::Keyboard::Key key )
{
    std::string key_str = "";

    switch( key )
    {
        case sf::Keyboard::Escape:
        key_str = "escape";
        break;

        case sf::Keyboard::Up:
        key_str = "up";
        break;

        case sf::Keyboard::Down:
        key_str = "down";
        break;

        case sf::Keyboard::Left:
        key_str = "left";
        break;

        case sf::Keyboard::Right:
        key_str = "right";
        break;

        case sf::Keyboard::Space:
        key_str = "space";
        break;

        case sf::Keyboard::Return:
        key_str = "return";
        break;

        case sf::Keyboard::BackSpace:
        key_str = "backSpace";
        break;
        
        case sf::Keyboard::A:
        key_str = "A";
        break;

        case sf::Keyboard::B:
        key_str = "B";
        break;

        case sf::Keyboard::C:
        key_str = "C";
        break;

        case sf::Keyboard::D:
        key_str = "D";
        break;

        case sf::Keyboard::E:
        key_str = "E";
        break;

        case sf::Keyboard::F:
        key_str = "F";
        break;

        case sf::Keyboard::G:
        key_str = "G";
        break;

        case sf::Keyboard::H:
        key_str = "H";
        break;

        case sf::Keyboard::I:
        key_str = "I";
        break;

        case sf::Keyboard::J:
        key_str = "J";
        break;

        case sf::Keyboard::K:
        key_str = "K";
        break;

        case sf::Keyboard::L:
        key_str = "L";
        break;

        case sf::Keyboard::M:
        key_str = "M";
        break;

        case sf::Keyboard::N:
        key_str = "N";
        break;

        case sf::Keyboard::O:
        key_str = "O";
        break;

        case sf::Keyboard::P:
        key_str = "P";
        break;

        case sf::Keyboard::Q:
        key_str = "Q";
        break;

        case sf::Keyboard::R:
        key_str = "R";
        break;

        case sf::Keyboard::S:
        key_str = "S";
        break;

        case sf::Keyboard::T:
        key_str = "T";
        break;

        case sf::Keyboard::U:
        key_str = "U";
        break;

        case sf::Keyboard::V:
        key_str = "V";
        break;

        case sf::Keyboard::W:
        key_str = "W";
        break;

        case sf::Keyboard::X:
        key_str = "X";
        break;

        case sf::Keyboard::Y:
        key_str = "Y";
        break;

        case sf::Keyboard::Z:
        key_str = "Z";
        break;

        case sf::Keyboard::Numpad0:
        key_str = "0";
        break;

        case sf::Keyboard::Numpad1:
        key_str = "1";
        break;

        case sf::Keyboard::Numpad2:
        key_str = "2";
        break;

        case sf::Keyboard::Numpad3:
        key_str = "3";
        break;

        case sf::Keyboard::Numpad4:
        key_str = "4";
        break;

        case sf::Keyboard::Numpad5:
        key_str = "5";
        break;

        case sf::Keyboard::Numpad6:
        key_str = "6";
        break;

        case sf::Keyboard::Numpad7:
        key_str = "7";
        break;

        case sf::Keyboard::Numpad8:
        key_str = "8";
        break;

        case sf::Keyboard::Numpad9:
        key_str = "9";
        break;

        default:
        key_str = "dummy";
        break;
    }

    return key_str;
}


