#ifndef EGN_LOGMANAGER_HPP
#define EGN_LOGMANAGER_HPP

#include "Singleton.hpp"

#include <iostream>
#include <fstream>

namespace egn {

class LogManager : public Singleton<LogManager>
{
    public:
        void set( const std::string& file );
        void log( const std::string& message );
        void error( const std::string& message );
        void warning( const std::string& message );

        virtual ~LogManager();
    protected:
    private:
        std::ofstream m_LogFile;
};

} // namespace egn

#endif // EGN_LOGMANAGER_HPP
