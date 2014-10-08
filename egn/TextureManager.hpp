#ifndef EGN_TEXTUREMANAGER_HPP
#define EGN_TEXTUREMANAGER_HPP

#include "Singleton.hpp"
#include "Texture.hpp"


#include <iostream>
#include <map>

namespace egn {

class TextureManager : public Singleton<TextureManager>
{
    public:
        egn::Texture& getTexture( const std::string& file );
        egn::Texture& getTexture( const std::string& file, egn::Color color );
    protected:
    private:
        std::map<std::string, egn::Texture> s_Textures;
};

} // namespace egn

#endif // EGN_TEXTUREMANAGER_HPP
