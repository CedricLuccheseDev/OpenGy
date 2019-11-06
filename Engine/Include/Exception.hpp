/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** Esception
*/

#ifndef ENGINEEXCEP_HPP_
#define ENGINEEXCEP_HPP_

#include <exception>

namespace Engine
{
    class Exception : public std::exception {
        public:
            Exception(const std::string &msg) : _msg(msg) {}
            virtual ~Exception() throw (){}

            virtual const char *what() const throw() { return _msg.c_str(); }

        private:
            std::string _msg;
    };

}

#endif /* !SFMLEXCEP_HPP_ */
