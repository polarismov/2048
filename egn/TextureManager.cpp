#include "TextureManager.hpp"

#include "LogManager.hpp"


egn::Texture& egn::TextureManager::getTexture( const std::string& file )
{
    if( s_Textures.find( file ) == s_Textures.end() )
    {
        if( !s_Textures[file].loadFromFile( file ) )
        {
            std::string error = "Impossible de charge la texture "+file;
            egn::LogManager::get()->error( error );
        }
    }
    return s_Textures[file];
}

egn::Texture& egn::TextureManager::getTexture( const std::string& file, egn::Color color )
{
    if( s_Textures.find( file ) == s_Textures.end() )
    {
        egn::Image image;
        if( !image.loadFromFile( file ) )
        {
            std::cerr << "Impossible de charger l'image " << file << std::endl;
        }
        else
        {
            image.setMask( color );
            if( !s_Textures[file].loadFromImage( image ) )
            {
                std::cerr << "Impossible de charger la texture (mask) " << file << std::endl;
            }
        }

    }

    return s_Textures[file];
}

