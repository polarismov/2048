#include "FontManager.hpp"

void egn::FontManager::add( const std::string& font_name, const std::string& path )
{
    if( m_Fonts.find( font_name ) == m_Fonts.end() )
    {
        m_Fonts[font_name].loadFromFile( path );
    }
}

void egn::FontManager::write( egn::Window& window, const std::string& font_name, const std::string& buffer, egn::Vector2f position, int size, egn::Color color )
{
    sf::Text text;
    text.setFont( m_Fonts[font_name] );
    text.setString( buffer );
    text.setPosition( position.x, position.y );
    text.setCharacterSize( size );
    text.setColor( color );
    window.getRenderWindow().draw( text );
    
}
