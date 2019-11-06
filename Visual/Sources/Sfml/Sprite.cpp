/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** Sprite
*/

#include <iostream>

#include "Sfml/Sprite.hpp"
#include "Sfml/Ressources.hpp"

Visual::SFML::Sprite::Sprite() :
_texture(""), _numbersOfCases(Utils::Vector2(1, 1)), _whichCase(1), _isVisible(true)
{
    create(Utils::Vector2(0, 0), _texture);
}

Visual::SFML::Sprite::Sprite(const ISprite &sprite)
{
    setTexture(sprite.getTexture());
    setPosition(sprite.getPosition());
    setSize(sprite.getSize());
    setRotation(sprite.getRotation());
    setTextureRect(sprite.getTextureRect(), sprite.getTextureRectWhich());
    setVisible(sprite.getVisible());
}

Visual::SFML::Sprite::~Sprite()
{
}

Visual::ISprite &Visual::SFML::Sprite::operator=(const Visual::ISprite &sprite)
{
    setTexture(sprite.getTexture());
    setPosition(sprite.getPosition());
    setSize(sprite.getSize());
    setRotation(sprite.getRotation());
    setTextureRect(sprite.getTextureRect(), sprite.getTextureRectWhich());
    setVisible(sprite.getVisible());

    return *this;
}

Visual::ISprite &Visual::SFML::Sprite::operator>>(Visual::ISprite &sprite)
{
    sprite.setTexture(getTexture());
    sprite.setPosition(getPosition());
    sprite.setSize(getSize());
    sprite.setRotation(getRotation());
    sprite.setTextureRect(getTextureRect(), getTextureRectWhich());
    sprite.setVisible(getVisible());

    return *this;
}

void Visual::SFML::Sprite::create(const Utils::Vector2 &pos, const std::string &texturePath)
{
    setTexture(texturePath);
    setPosition(pos);
    setSize(Utils::Vector2(1, 1));
    setRotation(0);
    setTextureRect(Utils::Vector2(1, 1), 1);
    setVisible(true);
}

void Visual::SFML::Sprite::destroy(void)
{

}

void Visual::SFML::Sprite::display(void)
{

}

void Visual::SFML::Sprite::move(const Utils::Vector2 &pos)
{
    _sprite.move(sf::Vector2f(pos.X, pos.Y));
}

void Visual::SFML::Sprite::rotate(float rotation)
{
    _sprite.rotate(rotation);
}

void Visual::SFML::Sprite::scale(const Utils::Vector2 &size)
{
    _sprite.scale(sf::Vector2f(size.X, size.Y));
}

void Visual::SFML::Sprite::setPosition(const Utils::Vector2 &pos)
{
    _sprite.setPosition(sf::Vector2f(pos.X, pos.Y));
}

void Visual::SFML::Sprite::setSize(const Utils::Vector2 &size)
{
    if (Ressources::SFML::Content::getTexture(_texture) == nullptr)
        return;

    _sprite.setScale(size.X, size.Y);
}

void Visual::SFML::Sprite::setRotation(float rotation)
{
    _sprite.setRotation(rotation);
}

void Visual::SFML::Sprite::setVisible(bool visible)
{
    _isVisible = visible;
}

void Visual::SFML::Sprite::setTexture(const std::string &texture)
{
    _texture = texture;
    if (Ressources::SFML::Content::getTexture(texture) == nullptr)
        return;

    sf::Vector2u size = Ressources::SFML::Content::getTexture(texture)->getSize();

    _sprite.setTexture(*Ressources::SFML::Content::getTexture(texture));
    _sprite.setTextureRect(sf::IntRect(0, 0, size.x, size.y));
}

void Visual::SFML::Sprite::setTextureRect(const Utils::Vector2 &Position, const Utils::Vector2 &Wide)
{
    _sprite.setTextureRect(sf::IntRect(Position.X, Position.Y, Wide.X, Wide.Y));
}

void Visual::SFML::Sprite::setTextureRect(const Utils::Vector2 &numbersOfCases, unsigned int whichCase)
{
    _numbersOfCases = numbersOfCases;
    _whichCase = whichCase;
}


