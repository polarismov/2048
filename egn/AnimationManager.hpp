#ifndef EGN_ANIMATIONMANAGER_HPP
#define EGN_ANIMATIONMANAGER_HPP

#include "Animation.hpp"

namespace egn
{

class AnimationManager
{
public:
    AnimationManager();
    ~AnimationManager();

    void add( const std::string& name, egn::Animation animation );

    egn::Animation& getAnimation( const std::string& name );
    egn::Animation& getAnimation();

    void update();

    void setAnimation( const std::string& frame );
protected:
private:
    std::map<std::string, egn::Animation> m_Animations;
    std::string m_CurrentFrame;
};

} // namespace egn

#endif // EGN_ANIMATIONMANAGER_HPP
