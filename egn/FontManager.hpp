#ifndef EGN_FONTMANAGER_HPP
#define EGN_FONTMANAGER_HPP

#include "Singleton.hpp"
#include "Window.hpp"

namespace egn {

class FontManager : public Singleton<FontManager>
{
    public:
        void add( const std::string& font_name, const std::string& path );

        void write( egn::Window& window, const std::string& font_name, const std::string& buffer, egn::Vector2f position, int size, egn::Color color );
    protected:
    private:
        std::map<std::string, sf::Font> m_Fonts;
};

} // namespace egn

#endif // EGN_FONTMANAGER_HPP
