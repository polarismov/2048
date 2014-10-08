#include "LogManager.hpp"

egn::LogManager::~LogManager()
{
    if( m_LogFile.is_open() )
    {
        m_LogFile.close();
    }
}

void egn::LogManager::set( const std::string& file )
{
    m_LogFile.open( file.c_str(), std::ios::out | std::ios::trunc );
}

void egn::LogManager::log( const std::string& message )
{
    std::cerr << message << std::endl;
    m_LogFile << message << std::endl;
}

void egn::LogManager::error( const std::string& message )
{
    std::cerr << "Error : " << message << std::endl;
    m_LogFile << "Error : " << message << std::endl;
}

void egn::LogManager::warning( const std::string& message )
{
    std::cerr << "Warning : " << message << std::endl;
    m_LogFile << "Warning : " << message << std::endl;
}


