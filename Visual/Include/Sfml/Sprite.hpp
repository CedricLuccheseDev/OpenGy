/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** Sprite
*/

#ifndef SPRITE_HPP_
#define SPRITE_HPP_

#include <string>

#include	<SFML/Graphics.hpp>

#include "ISprite.hpp"

namespace Visual
{
    namespace SFML
    {

        class Sprite : public ISprite {
            public:
                Sprite();
                Sprite(const ISprite &);

                ~Sprite();

                virtual ISprite &operator=(const ISprite &) final;
                virtual ISprite &operator>>(ISprite &) final;

                virtual void create(const Utils::Vector2 &pos = Utils::Vector2(0, 0), const std::string &texturePath = "") final;
                virtual void destroy(void) final;

                virtual void display(void) final;

                virtual void move(const Utils::Vector2 &pos) final;
                virtual void rotate(float rotation) final;
                virtual void scale(const Utils::Vector2 &size) final;

                virtual void setPosition(const Utils::Vector2 &pos) final;
                virtual void setSize(const Utils::Vector2 &size) final;
                virtual void setRotation(float rotation) final;
                virtual void setVisible(bool) final;

                virtual void setTexture(const std::string &texture) final;

                virtual void setTextureRect(const Utils::Vector2 &Position, const Utils::Vector2 &Wide) final;
                virtual void setTextureRect(const Utils::Vector2 &NumbersOfCases, unsigned int whichCase) final;

                virtual const Utils::Vector2 getTextureRect() const final { return Utils::Vector2(_sprite.getTextureRect().width, _sprite.getTextureRect().height); }
                virtual const unsigned int getTextureRectWhich() const final { return _whichCase; }

                virtual const Utils::Vector2 getPosition() const final { return Utils::Vector2(_sprite.getPosition().x, _sprite.getPosition().y); }
                virtual const Utils::Vector2 getSize() const final { return Utils::Vector2(_sprite.getScale().x, _sprite.getPosition().y); }
                virtual const float getRotation() const final { return _sprite.getRotation(); }
                virtual const bool getVisible() const final { return _isVisible; }

                virtual const std::string &getTexture() const final { return _texture; }

                sf::Sprite get() const { return _sprite; }

            private:
                sf::Sprite _sprite;

                std::string _texture;

                Utils::Vector2 _numbersOfCases;
                unsigned int _whichCase;

                bool _isVisible;
        };

    }
}

#endif /* !SPRITE_HPP_ */
