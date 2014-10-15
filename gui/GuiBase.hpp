#ifndef GUI_GUIBASE_HPP
#define GUI_GUIBASE_HPP

#include "../egn/Window.hpp"

namespace gui {

class GuiBase
{
    public:
        GuiBase();
        virtual ~GuiBase();

        virtual void update();

        virtual void draw( egn::Window& window );

        virtual void set( const std::string& var, int value );
        virtual void set( const std::string& var, std::string value );
    protected:
    private:
};

} // namespace gui

#endif // GUI_GUIBASE_HPP
