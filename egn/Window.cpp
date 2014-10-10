#include "Window.hpp"



egn::Window::Window()
{
    //ctor
}

egn::Window::~Window()
{
    //dtor
}

void egn::Window::create( int width, int height, const std::string& title )
{
    m_RenderWindow.create( sf::VideoMode( width, height ), title );
    m_RenderWindow.setKeyRepeatEnabled( false );
    m_RenderWindow.setVerticalSyncEnabled( false );
}

void egn::Window::setFramerate( int frame )
{
    m_RenderWindow.setFramerateLimit( frame );
}

void egn::Window::clear( egn::Color color )
{
    m_RenderWindow.clear( color );
}

bool egn::Window::pollEvent( egn::Event& event )
{
    return m_RenderWindow.pollEvent( event );
}

bool egn::Window::isOpen()
{
    return m_RenderWindow.isOpen();
}

void egn::Window::close()
{
    m_RenderWindow.close();
}

void egn::Window::display()
{
    m_RenderWindow.display();
}

void egn::Window::setTitle( const std::string& title )
{
    m_RenderWindow.setTitle( title );
}

void egn::Window::draw( egn::Sprite& sprite )
{
    m_RenderWindow.draw( sprite.get() );
}

void egn::Window::drawRect( egn::FloatRect rect, egn::Color color )
{
    sf::RectangleShape sh = sf::RectangleShape( egn::Vector2f( rect.width, rect.height ) );
    sh.setPosition( rect.left, rect.top );
    sh.setFillColor( color );
    m_RenderWindow.draw( sh );
}

void egn::Window::setCamera( egn::Camera& camera )
{
    m_Camera.copy( camera );
    m_Camera.setRenderWindowPtr( &m_RenderWindow );
    m_Camera.actualize();
}

egn::Camera& egn::Window::getCamera()
{
    return m_Camera;
}

sf::RenderWindow& egn::Window::getRenderWindow()
{
    return m_RenderWindow;
}
