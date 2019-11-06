/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** Ressources
*/

#include <memory>
#include "Sfml/Ressources.hpp"
#include "Sfml/Sound.hpp"
#include "Sfml/Text.hpp"
#include <iostream>

std::map<std::string, std::unique_ptr<sf::Texture>> Ressources::SFML::Content::_textures;
std::map<std::string, std::unique_ptr<Audio::SFML::Sound>> Ressources::SFML::Content::_sounds;
std::map<std::string, std::unique_ptr<sf::Font>> Ressources::SFML::Content::_fonts;
Ressources::Parser Ressources::SFML::Content::_parser;

void Ressources::SFML::Content::addTextures(const std::string &file)
{
    try {
        std::vector<Ressources::Data> list = _parser.getList(file);

        for (auto data : list) {
            auto it = _textures.find(data.name);
            if (it != _textures.end())
                continue;
            _textures[data.name] = std::make_unique<sf::Texture>();
            if (!_textures[data.name]->loadFromFile(data.path))
                std::cerr << "File: " << data.name << " '" << data.path << "' is wrong" << std::endl;
            else
                std::cout << "file added: " << data.name << std::endl;
        }
    } catch(const Ressources::ParserException &e)
    {
        std::cerr << e.what() << std::endl;
    }
}

void Ressources::SFML::Content::addSounds(const std::string &file)
{
    try {
        std::vector<Ressources::Data> list = _parser.getList(file);

        for (auto data : list) {
            auto it = _sounds.find(data.name);
            if (it != _sounds.end())
                continue;
            _sounds[data.name] = std::make_unique<Audio::SFML::Sound>(data.path);
            std::cout << "audio added: " << data.name << std::endl;
        }
    } catch(const Ressources::ParserException &e)
    {
        std::cerr << e.what() << std::endl;
    } catch (const Audio::Exception &se)
    {
        std::cerr << se.what() << std::endl;
    }
}

void Ressources::SFML::Content::addFonts(const std::string &file)
{
    try {
        std::vector<Ressources::Data> list = _parser.getList(file);

        for (auto data : list) {
            auto it = _sounds.find(data.name);
            if (it != _sounds.end())
                continue;
            _fonts[data.name] = std::make_unique<sf::Font>();
            if (!_fonts[data.name]->loadFromFile(data.path))
                std::cerr << "Font: " << data.name << " '" << data.path << "' is wrong" << std::endl;
            else
                std::cout << "Font added: " << data.name << std::endl;
        }
    } catch(const Ressources::ParserException &e)
    {
        std::cerr << e.what() << std::endl;
    } catch (const Audio::Exception &se)
    {
        std::cerr << se.what() << std::endl;
    }
}
