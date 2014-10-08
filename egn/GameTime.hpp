#ifndef EGN_GAMETIME_HPP
#define EGN_GAMETIME_HPP

#include <SFML/Graphics.hpp>

namespace egn
{

class GameTime
{
public:
    static void refresh();
    static float getElapsedTime();
    static int getRandomInt( int a, int b );
protected:
private:
    static sf::Clock s_Clock;
    static sf::Time s_Time;
};

} // namespace egn

#endif // EGN_GAMETIME_HPP
