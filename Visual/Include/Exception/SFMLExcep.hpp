/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** SFMLExcep
*/

#ifndef SFMLEXCEP_HPP_
#define SFMLEXCEP_HPP_

#include <exception>

/**
 * @namespace Visual
 *
 */
namespace Visual
{
    /**
     * @brief Exception de la SFML
     *
     */
    class SFMLExcepCritical : public std::exception {
        public:
            SFMLExcepCritical(const std::string &msg) : _msg(msg) {}
            virtual ~SFMLExcepCritical() throw (){}

            virtual const char *what() const throw() { return _msg.c_str(); }

        private:
            std::string _msg;
    };

}

#endif /* !SFMLEXCEP_HPP_ */
