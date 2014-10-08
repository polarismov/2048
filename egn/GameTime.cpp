#include "GameTime.hpp"


sf::Clock egn::GameTime::s_Clock;
sf::Time egn::GameTime::s_Time;


void egn::GameTime::refresh()
{
    s_Time = s_Clock.restart();
}

float egn::GameTime::getElapsedTime()
{
    return s_Time.asSeconds();
}

int egn::GameTime::getRandomInt( int a, int b )
{
    return rand()%(b-a) +a;
}
