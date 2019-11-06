/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** ParserSceneFiles
*/

#ifndef PARSERSCENEFILES_HPP_
#define PARSERSCENEFILES_HPP_

#include <exception>

#include <string>
#include <vector>


#include <fstream>

#include "Vector.hpp"

namespace Scene
{
    struct Component {
        Component(  const std::string &t = "",
                    const std::string &n = "",
                    const std::string &te = "",
                    const Utils::Vector2 p = Utils::Vector2(0, 0),
                    float s = 1,
                    const std::string &tex = "") :
                    type(t), name(n), texture(te), pos(p), size(s), text(tex) {}
        std::string type;
        std::string name;
        std::string texture;
        std::string text;
        Utils::Vector2 pos;
        float size;
    };

    struct Actions {
        Actions(    const std::string t = "",
                    const std::string k = "",
                    const std::string p = "") :
                    type(t), key(k), param(p) {}
        std::string type;
        std::string key;
        std::string param;
    };

    struct Event {
        Event(      const std::string n = "",
                    const std::string t = "") :
                    name(n), type(t) {}
        std::string name;
        std::string type;
        std::vector<Actions> actions;
    };

    struct Music {
        Music(      const std::string k) :
                    key(k) {}
        std::string key;
    };

    struct Info {
        Info() : name(""), path(""), err(false) {}
        std::string name;
        std::string path;
        std::vector<Component> components;
        std::vector<Event> events;
        std::vector<Music> musics;
        bool err;

    };

    class ParserException : public std::exception {
        public:
            ParserException(const std::string &msg, const std::string &file = "") : _msg(msg), _file(file) { _msg = "[file: " + file + "] " + msg; }
            virtual ~ParserException() throw (){}

            virtual const char *what() const throw() { return _msg.c_str(); }

            std::string _file;

        private:
            std::string _msg;
    };

    class Parser {
        public:
            Parser() : components(false), events(false), musics(false), inAction(false) {}

            Info parse(const std::string &file);

            void erase(const std::string &file);

            void setEmpty(const std::string &file);

            void setName(const std::string &file, const std::string &name);

            void add(const std::string &file, const Component &component);
            void add(const std::string &file, const Event &Event);
            void add(const std::string &file, const Music &Music);
        private:
            std::vector<std::string> toWordArray(std::string line, const std::string &key);

            void InComponents(Info &info, const std::string &line, int i);
            void InEvents(Info &info, const std::string &line, int i);
            void InMusics(Info &info, const std::string &line, int i);

            bool components;
            bool events;
            bool musics;
            bool inAction;

            std::string action_name;
            std::string action_type;
            std::vector<Actions> actions;


    };

}

#endif /* !PARSERSCENEFILES_HPP_ */
