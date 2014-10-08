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
    protected:
    private:
};

} // namespace gui

#endif // GUI_GUIBASE_HPP
