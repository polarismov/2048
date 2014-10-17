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

    /* ajouter une animation */
    void add( const std::string& name, egn::Animation animation );

    egn::Animation& getAnimation( const std::string& name );
    egn::Animation& getAnimation();

    void update();

    /* animation courante */
    void setAnimation( const std::string& frame );
protected:
private:
    std::map<std::string, egn::Animation> m_Animations;
    std::string m_CurrentFrame;
};

} // namespace egn

#endif // EGN_ANIMATIONMANAGER_HPP
