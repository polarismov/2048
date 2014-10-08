#include "AudioManager.hpp"

#include "LogManager.hpp"

egn::AudioManager::AudioManager()
{
    m_VolumeMusic = 50;
    m_VolumeSound = 50;
}

void egn::AudioManager::playMusic( const std::string& path )
{
    if( m_Music.getStatus() != sf::Music::Playing && path != m_CurrentMusic )
    {
        m_Music.stop();

        if( !m_Music.openFromFile( path ) )
        {
            std::string error = "Impossible de charger la musique "+path;
            egn::LogManager::get()->error( error );
        }
        else
        {
            std::string msg = "Musique chargée "+path;
            egn::LogManager::get()->log( msg );
        }

        m_Music.setVolume( m_VolumeMusic );
        m_Music.play();
        m_Music.setLoop( true );
        m_CurrentMusic = path;
    }
    else
    {
        m_Music.play();
    }

}

void egn::AudioManager::pauseMusic()
{
    if( m_Music.getStatus() == sf::Music::Playing )
    {
        m_Music.pause();
    }
}

void egn::AudioManager::stopMusic()
{
    if( m_Music.getStatus() == sf::Music::Playing )
    {
        m_Music.stop();
    }
}

void egn::AudioManager::loadSound( const std::string& path )
{
    if( m_SoundBuffers.find( path ) == m_SoundBuffers.end() )
    {
        if( !m_SoundBuffers[path].loadFromFile( path ) )
        {
            std::string error = "Impossible de charger le soundbuffer "+path;
            egn::LogManager::get()->error( error );
        }
        else
        {
            std::string msg = "Soundbuffer chargé "+path;
            egn::LogManager::get()->log( msg );
        }
    }
}

void egn::AudioManager::playSound( const std::string& path )
{
    if( m_Sounds.find( path ) != m_Sounds.end() )
    {
        m_Sounds[path].play();
    }
    else
    {
        loadSound( path );
        m_Sounds[path].setBuffer( m_SoundBuffers[path] );
        m_Sounds[path].setVolume( m_VolumeSound );
        m_Sounds[path].play();
    }
}

void egn::AudioManager::stopSound( const std::string& id )
{
    if( id == "*" )
    {
        std::map<std::string, sf::Sound>::iterator it;
        for( it = m_Sounds.begin(); it != m_Sounds.end(); ++it )
        {
            (*it).second.stop();
        }
    }
    else
    {
        if( m_Sounds.find( id ) != m_Sounds.end() )
        {
            m_Sounds[id].stop();
        }
    }
}


