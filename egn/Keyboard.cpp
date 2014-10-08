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

        default:
        key_str = "dummy";
        break;
    }

    return key_str;
}


