/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** IAudio
*/

#ifndef IAUDIO_HPP_
#define IAUDIO_HPP_

#include <iostream>
#include <string>

/**
 * @namespace Audio
 *
 */
namespace Audio
{

    class Exception : public std::exception {
        public:
            Exception(const std::string &msg) : _msg(msg) {}
            virtual ~Exception() throw (){}

            virtual const char *what() const throw() { return _msg.c_str(); }

        private:
            std::string _msg;
    };

    class ISound {
        public:
            virtual ~ISound() = default;

            /**
             * @brief Play Sound
             *
             */
            virtual void play(void) = 0;

            /**
             * @brief Pause sound
             *
             */
            virtual void pause(void) = 0;

            /**
             * @brief stop sound
             *
             */
            virtual void stop(void) = 0;

            /**
             * @brief Set the Loop object
             *
             */
            virtual void setLoop(bool) = 0;

            /**
             * @brief Set the Volume object
             *
             */
            virtual void setVolume(float) = 0;

            /**
             * @brief Set the Sound object
             *
             * @param file
             */
            virtual void setSound(const std::string &file) = 0;

            virtual bool isPlaying(void) = 0;

            virtual void destroy(void) = 0;

    };

}

#endif /* !IAUDIO_HPP_ */
