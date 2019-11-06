/*
** EPITECH PROJECT, 2019
** RType
** File description:
** Sound
*/

#ifndef SOUND_HPP_
#define SOUND_HPP_

#include <SFML/Audio.hpp>
#include "ISound.hpp"

namespace Audio
{
    namespace SFML
    {

        class Sound : public ISound {
            public:
                Sound() = default;
                Sound(const std::string &file);

                virtual ~Sound() = default;

                virtual void play(void) final;
                virtual void pause(void) final;
                virtual void stop(void) final;

                virtual void setLoop(bool) final;
                virtual void setVolume(float) final;

                virtual void setSound(const std::string &file) final;

                virtual void destroy(void) final;

                virtual bool isPlaying(void) final { if (_sound.getStatus() == sf::Sound::Playing) return true; else return false; }

            private:
                sf::SoundBuffer _buffer;
                sf::Sound _sound;
        };
    }
}

#endif /* !SOUND_HPP_ */
