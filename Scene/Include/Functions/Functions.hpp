/*
** EPITECH PROJECT, 2019
** RType
** File description:
** Functions
*/

#ifndef FUNCTIONS_HPP_
#define FUNCTIONS_HPP_

#include <map>
#include <functional>

#include "IWindow.hpp"
#include "IManager.hpp"

namespace Scene
{

    class Functions {
        public:
            static void Initialize(Scene::IManager *);

            static std::map<std::string, std::function<void(Visual::IWindow &, const std::string &value)>> Func;

        private:

            Functions() { man = nullptr; };

            static Scene::IManager *man;

            static void quit(Visual::IWindow &, const std::string &value = "");
            static void swap(Visual::IWindow &, const std::string &value = "");
            static void test(Visual::IWindow &, const std::string &value = "");
            static void soundSFML(Visual::IWindow &, const std::string &value = "");

    };

}

#endif /* !FUNCTIONS_HPP_ */
