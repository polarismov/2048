#ifndef EGN_WINDOW_HPP
#define EGN_WINDOW_HPP


#include <SFML/Graphics.hpp>

#include "Event.hpp"
#include "Color.hpp"
#include "Camera.hpp"
#include "Sprite.hpp"


namespace egn
{

class Window
{
public:
    Window();
    ~Window();

    void create( int width, int height, const std::string& title );

    bool pollEvent( egn::Event& event );

    void setFramerate( int frame );

    void clear( egn::Color color );

    void display();

    void setTitle( const std::string& title );

    void close();

    bool isOpen();

    void draw( egn::Sprite& sprite );
    void drawRect( egn::FloatRect floatRect, egn::Color color );

    void setCamera( egn::Camera& camera );
    egn::Camera& getCamera();

    sf::RenderWindow& getRenderWindow();
protected:
private:
    sf::RenderWindow m_RenderWindow;

    egn::Camera m_Camera;
};

} // namespace egn

#endif // EGN_WINDOW_HPP
