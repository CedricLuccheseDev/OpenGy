/*
** EPITECH PROJECT, 2019
** RType
** File description:
** Text
*/

#include "Sfml/Text.hpp"
#include "Sfml/Ressources.hpp"

void Visual::SFML::Text::create(const Utils::Vector2 &pos, const std::string &text, const std::string &font)
{
    _text.setFillColor(sf::Color::White);
    setPosition(pos);
    setString(text);
    setFont(font);
}

void Visual::SFML::Text::setString(const std::string str)
{
    _textstring = str;
    _text.setString(str);
}

void Visual::SFML::Text::setSize(float size)
{
    _text.setScale(size, size);
}

void Visual::SFML::Text::setPosition(const Utils::Vector2 &pos)
{
    _text.setPosition(sf::Vector2f(pos.X, pos.Y));
}

void Visual::SFML::Text::setVisible(bool visible)
{
    _visible = visible;
}

void Visual::SFML::Text::setFont(const std::string &font)
{
    if (Ressources::SFML::Content::getFont(font) == nullptr)
        return;
    _font = font;
    _text.setFont(*Ressources::SFML::Content::getFont(font));
}

void Visual::SFML::Text::move(const Utils::Vector2 &pos)
{
    _text.move(sf::Vector2f(pos.X, pos.Y));
}

