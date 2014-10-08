#ifndef EGN_IMAGE_HPP
#define EGN_IMAGE_HPP


#include "Color.hpp"

namespace egn
{

class Image
{
public:
    Image();
    ~Image();

    bool loadFromFile( const std::string& file );

    void setMask( egn::Color color );

    sf::Image& get();
protected:
private:
    sf::Image m_Image;
};

} // namespace egn

#endif // EGN_IMAGE_HPP
