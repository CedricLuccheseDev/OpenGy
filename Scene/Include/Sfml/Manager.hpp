/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** SceneManager
*/

#ifndef SCENEMANAGER_HPP_
#define SCENEMANAGER_HPP_

#include <string>
#include <map>
#include <memory>

#include <time.h>

#include "IManager.hpp"
#include "Sfml/View.hpp"
#include "Parser/ParserSceneFiles.hpp"

namespace Scene
{
    namespace SFML
    {

        class Manager : public IManager {
            public:
                Manager() : _actualScene("") {}

                void setup(const std::string &filename);

                void add(const std::string &filename);
                void erase(const std::string &scenename);
                void set(const std::string &scene, const std::string &filename);

                void run(Visual::IWindow &win);

                void swap(const std::string &scenename) { if (_scenes.find(scenename) != _scenes.end()) _actualScene = scenename; }

                const std::string &getActualScene() { return _actualScene; }

            private:
                std::map<std::string, std::unique_ptr<View>> _scenes;
                std::string _actualScene;
                Parser _parser;
                unsigned int _offset;
                std::clock_t cl;
        };

    }
}

#endif /* !SCENEMANAGER_HPP_ */
