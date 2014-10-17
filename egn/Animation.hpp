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

    /* ajouter une frame à jouer */
    void add( egn::IntRect frame );

    /* mettre à jour l'animation, prends le temps courant en paramètre : egn::GameTime::getElapsedTime() */
    void update( float delta );

    egn::IntRect getCurrentFrame();

    void setSpeed( float speed );

    void setCurrentFrame( int index );

    /* retourne l'index de la frame courante */
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
