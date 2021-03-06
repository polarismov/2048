#ifndef EGN_SPRITE_HPP
#define EGN_SPRITE_HPP

#include "Util.hpp"
#include "Texture.hpp"

namespace egn
{

class Sprite
{
public:
    Sprite();
    ~Sprite();

    /* ne dessiner qu'une partie de l'image */
    void setFocus( egn::IntRect focus );

    void setPosition( egn::Vector2f position );

    void setTexture( egn::Texture& texture );

    void setScale( float x, float y );
    void scale( float x, float y );

    sf::Sprite& get();
protected:
private:
    sf::Sprite m_Sprite;
};

} // namespace egn

#endif // EGN_SPRITE_HPP