/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** Manager
*/

#include <dirent.h>
#include <sys/types.h>

#include <fstream>

#include "Parser/ParserSceneFiles.hpp"

#include "Sfml/Manager.hpp"
#include "Sfml/Window.hpp"
#include "Functions/Functions.hpp"
#include <iostream>

void Scene::SFML::Manager::setup(const std::string &filename)
{
    DIR *dir = nullptr;
    struct dirent* file = nullptr;
    std::fstream scenefile;

    std::string directory;
    std::string main;

    bool isDirectory = false;
    bool isMain = false;

    cl = clock();

    Scene::Functions::Initialize(this);

    if (filename.find("scenefile.scene") == std::string::npos)
        throw ManagerException("the file isn't named 'scenefile.scene'");

    scenefile.open(filename, std::fstream::in);
    if (!scenefile)
        throw Scene::ManagerException("Can't open file : '" + filename + "'");

    _offset = 1000;
    while (true) {
        std::string line;
        getline(scenefile, line);

        if (line == "" || line.length() == 0)
            break;

        if (line[0] == '#')
            continue;

        if (line.find("dir:") != std::string::npos) {
            directory = line.substr(line.find(":") + 1);
            isDirectory = true;
            continue;
        }
        if (line.find("main:") != std::string::npos) {
            main = line.substr(line.find(":") + 1);
            isMain = true;
            continue;
        }

        if (line.find("offset:") != std::string::npos) {
            _offset = std::stoi(line.substr(line.find(":") + 1));
            continue;
        }
    }

    if (!isDirectory || !isMain)
        throw Scene::ManagerException("'dir:' or 'main:' not found");

    _actualScene = main;

    if ((dir = opendir(directory.c_str())) == nullptr)
        throw Scene::ManagerException("directory not found");

    while ((file = readdir(dir))) {
        if (file == nullptr)
            break;
        if (file->d_name[0] == '.')
            continue;

        try {
            Scene::Info info = _parser.parse(directory + "/" + file->d_name);
            _scenes[info.name] = std::make_unique<View>(info);
        } catch (const Scene::ParserException &err) {
            std::cerr << err.what() << std::endl;
            Scene::Info info;
            _scenes[err._file] = std::make_unique<View>(info);
            _scenes[err._file]->setError(true);
        }
    }


}

void Scene::SFML::Manager::add(const std::string &filename)
{

}

void Scene::SFML::Manager::erase(const std::string &scenename)
{

}

void Scene::SFML::Manager::set(const std::string &scene, const std::string &filename)
{

}

void Scene::SFML::Manager::run(Visual::IWindow &w)
{
    Visual::SFML::Window *win = dynamic_cast<Visual::SFML::Window *>(&w);
    bool offset = false;

    if (win == nullptr)
        return;
    if ((float)(clock() - cl) / CLOCKS_PER_SEC >= (float)_offset / 1000) {
        cl = clock();
        offset = true;
    }
    try {
        _scenes[getActualScene()]->update(_parser.parse(_scenes[getActualScene()]->getPath()), w, offset);
        _scenes[getActualScene()]->setError(false);
    } catch (const Scene::ParserException &err) {
        std::cerr << err.what() << std::endl;
        _scenes[getActualScene()]->setError(true);
    }
    _scenes[getActualScene()]->display(*win);
}
