/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** ParserSceneFiles
*/

#include <algorithm>
#include <iostream>

#include "Parser/ParserSceneFiles.hpp"

Scene::Info Scene::Parser::parse(const std::string &file)
{
    Info info;
    std::fstream f;

    if (file.find(".scene") == std::string::npos)
        throw Scene::ParserException("Wrong File format (should be .scene) : '" + file + "'", file);
    f.open(file, std::fstream::in);
    if (!f)
        throw Scene::ParserException("Can't open file : '" + file + "'", file);

    info.path = file;

    for (int i = 0; i < 4096; i++) {
        std::string line;
        std::string temp;
        std::getline(f, line);

        if (line == "" || line.length() == 0)
            continue;
        if (line[0] == '#')
            continue;
        if ((components && events) || (components && musics) || (events && musics))
            throw Scene::ParserException("'}' Forgot", file);

        if (line.find("}") != std::string::npos && components)
            components = false;
        if (line.find("}") != std::string::npos && events)
            events = false;
        if (line.find("}") != std::string::npos && musics)
            musics = false;

        if (components)
            InComponents(info, line, i);

        if (events)
            InEvents(info, line, i);

        if (musics)
            InMusics(info, line, i);

        if (line.find("Name:") != std::string::npos)
            info.name = line.substr(line.find(":") + 1);
        if (line.find("Components:{") != std::string::npos)
            components = true;
        if (line.find("Events:{") != std::string::npos)
            events = true;
        if (line.find("Musics:{") != std::string::npos)
            events = true;

    }

    if (info.name == "")
        throw Scene::ParserException("Name not found ! (add 'Name:[name]' in the file)", file);
    if (components == true || events == true || musics == true || inAction == true)
        throw Scene::ParserException("Error: '}' Forgot", file);

    return info;
}

std::vector<std::string> Scene::Parser::toWordArray(std::string line, const std::string &key)
{
    std::vector<std::string> list;
    std::string temp;

    auto it = line.find_first_not_of(" ");
    line = line.substr(it);

    while (line != "") {
        temp = line.substr(0, line.find(key));
        line = line.substr(line.find(key) + key.length());
        list.push_back(temp);
        if (line.find(key) == std::string::npos)
            break;
    }

    list.push_back(line);
    return list;
}

void Scene::Parser::InComponents(Scene::Info &info, const std::string &line, int i)
{
    std::vector<std::string> parsed = toWordArray(line, ":");
    if (parsed[0] == "img") {
        if (parsed.size() != 6)
            throw Scene::ParserException("Invalid numbers of args on components", info.path);
        try {
            Scene::Component comp(parsed[0], parsed[1], parsed[2],
                                Utils::Vector2(std::stof(parsed[3]), std::stof(parsed[4])),
                                std::stof(parsed[5]));
            info.components.push_back(comp);
        } catch (const std::invalid_argument &e) {
            std::cerr << "[file: " << info.path << "] " << "Invalid args on components | line " << i + 1 << std::endl;
        }
    }
    if (parsed[0] == "text") {
        if (parsed.size() != 7  )
            throw Scene::ParserException("Invalid numbers of args on components", info.path);
        try {
            Scene::Component comp(parsed[0], parsed[1], parsed[2],
                                Utils::Vector2(std::stof(parsed[3]), std::stof(parsed[4])),
                                std::stof(parsed[5]), parsed[6]);
            info.components.push_back(comp);
        } catch (const std::invalid_argument &e) {
            std::cerr << "[file: " << info.path << "] " << "Invalid args on components | line " << i + 1 << std::endl;
        }
    }
}

void Scene::Parser::InEvents(Scene::Info &info, const std::string &line, int i)
{
    std::vector<std::string> parsed = toWordArray(line, ":");
    if (inAction == false) {
        if (parsed.size() != 3)
            throw Scene::ParserException("Invalid numbers of args on components", info.path);
        action_name = parsed[0];
        action_type = parsed[1];
        actions.clear();
        inAction = true;
    } else {
        if (parsed[0] == ")") {
            Event ev(action_name, action_type);
            ev.actions = actions;
            info.events.push_back(ev);
            inAction = false;
            return;
        }
        if (parsed.size() == 3)
            actions.push_back(Actions(parsed[0], parsed[1], parsed[2]));
        else if (parsed.size() == 2)
            actions.push_back(Actions(parsed[0], parsed[1]));
        else
            throw Scene::ParserException("Invalid args on Actions", info.path);
    }
}

void Scene::Parser::InMusics(Scene::Info &info, const std::string &line, int i)
{
    info.musics.push_back(Music(line));
}
