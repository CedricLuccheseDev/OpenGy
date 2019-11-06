/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** Ressources
*/

#ifndef RESSOURCES_HPP_
#define RESSOURCES_HPP_

#include <memory>

#include	<SFML/Window.hpp>
#include	<SFML/Graphics.hpp>

#include "Parser/ParserRessourcesFiles.hpp"
#include "Sfml/Sound.hpp"

/**
 * @namespace Ressources
 *
 */
namespace Ressources
{
    namespace SFML
    {
        /**
         * @class Content
         *
         * @brief Static class
         */
        class Content
        {
        public:
            /**
             * @brief Add textures in memory from file .res
             *
             * @param file
             */
            static void addTextures(const std::string &file);

            /**
             * @brief Add sounds in memory from file .res
             *
             * @param file
             */
            static void addSounds(const std::string &file);

            /**
             * @brief Add fonts in memory from file .res
             *
             * @param file
             */
            static void addFonts(const std::string &file);

            static void destroyTextures(const std::string &file);
            static void destroySounds(const std::string &file);
            static void destroyFonts(const std::string &file);

            static void destroyTexture(const std::string &key);
            static void destroySound(const std::string &key);
            static void destroyFont(const std::string &key);

            static const std::unique_ptr<sf::Texture> &getTexture(const std::string &key) { return _textures[key]; }
            static const std::unique_ptr<Audio::SFML::Sound> &getSound(const std::string &key) { return _sounds[key]; };
            static const std::unique_ptr<sf::Font> &getFont(const std::string &key) { return _fonts[key]; };


            static Ressources::Parser _parser;

        private:
            Content() = default;

            static std::map<std::string, std::unique_ptr<sf::Texture>> _textures;
            static std::map<std::string, std::unique_ptr<Audio::SFML::Sound>> _sounds;
            static std::map<std::string, std::unique_ptr<sf::Font>> _fonts;

        };
    }
}

#endif /* !RESSOURCES_HPP_ */
