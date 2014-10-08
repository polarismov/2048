#include "Animation.hpp"



egn::Animation::Animation()
{
    m_Speed = sf::seconds(1);
    m_CurrentFrame = 0;
    m_CurrentTime = sf::Time::Zero;
}

egn::Animation::~Animation()
{
    //dtor
}

void egn::Animation::add( egn::IntRect rect )
{
    m_Frames.push_back( rect );
}

void egn::Animation::setSpeed( float speed )
{
    m_Speed = sf::seconds( speed );
}

egn::IntRect egn::Animation::getCurrentFrame()
{
    return m_Frames[m_CurrentFrame];
}

void egn::Animation::setCurrentFrame( int index )
{
    m_CurrentFrame = index;
}

void egn::Animation::update( float delta )
{
    m_CurrentTime += sf::seconds( delta );
    if( m_CurrentTime > m_Speed )
    {
        m_CurrentFrame++;
        m_CurrentTime = sf::Time::Zero;
        if( m_CurrentFrame > static_cast<int>(m_Frames.size() - 1) )
        {
            m_CurrentFrame = 0;
        }
    }

}

int egn::Animation::getCurrentFrameIndex()
{
    return m_CurrentFrame;
}

