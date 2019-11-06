/*
** EPITECH PROJECT, 2019
** RType
** File description:
** Sound
*/

#include "Sfml/Sound.hpp"

Audio::SFML::Sound::Sound(const std::string &file)
{
    setSound(file);
}

void Audio::SFML::Sound::play()
{
    _sound.play();
}

void Audio::SFML::Sound::pause()
{
    _sound.pause();
}

void Audio::SFML::Sound::stop()
{
    _sound.stop();
}

void Audio::SFML::Sound::setLoop(bool loop)
{
    _sound.setLoop(loop);
}

void Audio::SFML::Sound::setVolume(float vol)
{
    _sound.setVolume(vol);
}

void Audio::SFML::Sound::setSound(const std::string &file)
{
    if (!_buffer.loadFromFile(file))
        throw Audio::Exception("[Audio] : " + file + " problem");
    _sound.setBuffer(_buffer);
}

void Audio::SFML::Sound::destroy()
{

}
