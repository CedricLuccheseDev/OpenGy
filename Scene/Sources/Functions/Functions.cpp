/*
** EPITECH PROJECT, 2019
** RType
** File description:
** Functions
*/

#include "Functions/Functions.hpp"
#include "Sfml/Ressources.hpp"
#include <iostream>

std::map<std::string, std::function<void(Visual::IWindow &, const std::string &value)>> Scene::Functions::Func;
Scene::IManager *Scene::Functions::man;

void Scene::Functions::Initialize(Scene::IManager *m)
{
    Scene::Functions::man = m;

    Func["quit"] = &Scene::Functions::quit;
    Func["swap"] = &Scene::Functions::swap;
    Func["test"] = &Scene::Functions::test;
    Func["soundSFML"] = &Scene::Functions::soundSFML;
}

void Scene::Functions::quit(Visual::IWindow &win, const std::string &value)
{
    win.quit();
}

void Scene::Functions::swap(Visual::IWindow &win, const std::string &value)
{
    Scene::Functions::man->swap(value);
}

void Scene::Functions::soundSFML(Visual::IWindow &win, const std::string &value)
{
    if (Ressources::SFML::Content::getSound(value) != nullptr)
        Ressources::SFML::Content::getSound(value)->play();
}

void Scene::Functions::test(Visual::IWindow &win, const std::string &value)
{
    std::cout << value << std::endl;
}

