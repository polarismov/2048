#ifndef EGN_ANIMATION_HPP
#define EGN_ANIMATION_HPP

#include "Util.hpp"

#include <iostream>
#include <map>

namespace egn
{

class Animation
{
public:
    Animation();
    ~Animation();

    void add( egn::IntRect frame );

    void update( float delta );

    egn::IntRect getCurrentFrame();

    void setSpeed( float speed );

    void setCurrentFrame( int index );

    int getCurrentFrameIndex();
protected:
private:
    std::vector<egn::IntRect> m_Frames;
    int m_CurrentFrame;
    sf::Time m_Speed;
    sf::Time m_CurrentTime;

};

} // namespace egn

#endif // EGN_ANIMATION_HPP
