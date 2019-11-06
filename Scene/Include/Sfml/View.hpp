/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** IScene
*/

#ifndef ISCENE_HPP_
#define ISCENE_HPP_

#include <memory>
#include <string>

#include "IView.hpp"
#include "IWindow.hpp"

#include "Sfml/Sound.hpp"
#include "Sfml/Sprite.hpp"
#include "Sfml/Text.hpp"


namespace Scene
{
    namespace SFML
    {

        class View : public IView {
            public:
                View() : _err(false) {}
                View(const Info &info) { set(info); _err = info.err; }

                ~View() = default;

                void set(const Info &info);

                void update(const Info &info, Visual::IWindow &win, bool offset);

                void display(Visual::IWindow &win);

                void setError(bool error) { _err = error; }

                std::string getName() { return _name; }
                std::string getPath() { return _path; }
                bool getError() { return _err; }

            private:
                std::map<std::string, Visual::SFML::Sprite> _sprites;
                std::map<std::string, Visual::SFML::Text> _texts;
                std::vector<std::string> _musics;
                std::string _name;
                std::string _path;

                std::string _currentMusic;

                bool _err;

                std::string SetImg(const Component &img);
                std::string SetText(const Component &text);
                //std::string SetMusic(const Music &inf);
                void PlayEvent(const Scene::Event &ev, Visual::IWindow &win);
                void PlayAction(const Scene::Event &ev, Visual::IWindow &win);
                //void PlayMusic(const Scene::Info &info);

        };

    }
}

#endif /* !ISCENE_HPP_ */
