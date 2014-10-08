#ifndef EGN_PIXEL_HPP
#define EGN_PIXEL_HPP

#include "Window.hpp"

namespace egn
{

class Pixel
{
public:
    static void draw( egn::Window& window, egn::Vector2f position, egn::Color color );
protected:
private:
};

} // namespace egn

#endif // EGN_PIXEL_HPP
