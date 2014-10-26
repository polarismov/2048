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

        /* attribuer une valeur à une variable */
        virtual void set( const std::string& var, int value );
        virtual void set( const std::string& var, std::string value );


        /* récupérer la valeur d'une variable */
        virtual int get_int( const std::string& var );
        virtual std::string get_string( const std::string& var );
    protected:
    private:
};

} // namespace gui

#endif // GUI_GUIBASE_HPP
