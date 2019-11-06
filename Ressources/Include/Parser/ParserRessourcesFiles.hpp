/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** ParserRessourcesFiles
*/

#ifndef PARSERRESSOURCESFILES_HPP_
#define PARSERRESSOURCESFILES_HPP_

#include <exception>
#include <vector>
#include <string>

namespace Ressources
{
    class ParserException : public std::exception {
        public:
            ParserException(const std::string &msg) : _msg(msg) {}
            virtual ~ParserException() throw (){}

            virtual const char *what() const throw() { return _msg.c_str(); }

        private:
            std::string _msg;
    };

    struct Data
    {
        Data() : name(""), path("") {}
        Data(const std::string &n, const std::string &p) : name(n), path(p) {}

        void Set(const std::string &n, const std::string &p) { name = n; path = p; }

        std::string name;
        std::string path;
    };

    /**
     * @brief Parser de fichier '.res'
     *
     */
    class Parser {
        public:
            Parser();

            std::vector<Data> getList(const std::string &file);
        private:
    };

}

#endif /* !PARSERRESSOURCESFILES_HPP_ */
