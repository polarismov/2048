#include "AnimationManager.hpp"

#include "GameTime.hpp"


egn::AnimationManager::AnimationManager()
{
    m_CurrentFrame = "";
}

egn::AnimationManager::~AnimationManager()
{
    //dtor
}


void egn::AnimationManager::add( const std::string& frame, egn::Animation animation )
{
    m_Animations[frame] = animation;
}

void egn::AnimationManager::setAnimation( const std::string& frame )
{
    m_CurrentFrame = frame;
}

egn::Animation& egn::AnimationManager::getAnimation( const std::string& frame )
{
    return m_Animations[frame];
}

egn::Animation& egn::AnimationManager::getAnimation()
{
    return m_Animations[m_CurrentFrame];
}

void egn::AnimationManager::update()
{
    m_Animations[m_CurrentFrame].update( egn::GameTime::getElapsedTime() );
}




