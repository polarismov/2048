#ifndef EGN_TEXTURE_HPP
#define EGN_TEXTURE_HPP

#include "Image.hpp"

namespace egn {

class Texture
{
    public:
        Texture();
        ~Texture();

        bool loadFromFile( const std::string& file );

        bool loadFromImage( egn::Image& image );

        sf::Texture& get();
    protected:
    private:
        sf::Texture m_Texture;
};

} // namespace egn

#endif // EGN_TEXTURE_HPP
