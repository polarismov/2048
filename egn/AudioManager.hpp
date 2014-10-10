#ifndef EGN_AUDIOMANAGER_HPP
#define EGN_AUDIOMANAGER_HPP

#include <SFML/Audio.hpp>
#include <iostream>
#include <map>

#include "Singleton.hpp"

namespace egn {

class AudioManager : public Singleton<AudioManager>
{
    public:
        /* music */
        void playMusic( const std::string& path );
        void stopMusic();
        void pauseMusic();
        const std::string& getMusic();
        void setVolumeMusic( int volume );
        int getVolumeMusic() const;

        /* sound */
        void playSound( const std::string& path );
        void loadSound( const std::string& path );
        void stopSound( const std::string& id );
        void setVolumeSound( int volume );
        int getVolumeSound() const;
    protected:
    private:
        AudioManager();

        std::string m_CurrentMusic;
        sf::Music m_Music;

        std::map<std::string, sf::SoundBuffer> m_SoundBuffers;
        std::map<std::string, sf::Sound> m_Sounds;

        int m_VolumeMusic;
        int m_VolumeSound;
};

} // namespace egn

#endif // EGN_AUDIOMANAGER_HPP

