/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** ISprite
*/

#ifndef ISPRITE_HPP_
#define ISPRITE_HPP_

#include <string>
#include "Vector.hpp"

namespace Visual
{
    /**
     * @class ISprite
     * @brief Interface de sprite
     */
    class ISprite {
        public:
            virtual ~ISprite() = default;

            virtual ISprite &operator=(const ISprite &) = 0;
            virtual ISprite &operator>>(ISprite &) = 0;

            /**
             * @brief Create new sprite
             *
             * @param pos
             * @param texturePath
             */
            virtual void create(const Utils::Vector2 &pos = Utils::Vector2(0, 0), const std::string &texturePath = "") = 0;

            /**
             * @brief Destroy sprite
             *
             */
            virtual void destroy(void) = 0;

            /**
             * @brief Display sprite
             *
             */
            virtual void display(void) = 0;

            /**
             * @brief deplace le sprite depuis sa position initial
             *
             * @param pos
             */
            virtual void move(const Utils::Vector2 &pos) = 0;

            /**
             * @brief Tourne le sprite
             *
             * @param rotation
             */
            virtual void rotate(float rotation) = 0;

            /**
             * @brief Change la taille du sprite
             *
             * @param size
             */
            virtual void scale(const Utils::Vector2 &size) = 0;

            /**
             * @brief Set la position du sprite
             *
             * @param pos
             */
            virtual void setPosition(const Utils::Vector2 &pos) = 0;

            /**
             * @brief Set the Size object
             *
             * @param size
             */
            virtual void setSize(const Utils::Vector2 &size) = 0;

            /**
             * @brief Set the Rotation object
             *
             */
            virtual void setRotation(float) = 0;

            /**
             * @brief Set the Visible object
             *
             */
            virtual void setVisible(bool) = 0;

            /**
             * @brief Set the Texture object
             *
             * @param texture
             */
            virtual void setTexture(const std::string &texture) = 0;

            /**
             * @brief Set the Texture Rect object
             *
             * @param Position
             * @param Wide
             */
            virtual void setTextureRect(const Utils::Vector2 &Position, const Utils::Vector2 &Wide) = 0;

            /**
             * @brief Set the Texture Rect object
             *
             * @param NumbersOfCases
             * @param whichCase
             */
            virtual void setTextureRect(const Utils::Vector2 &NumbersOfCases, unsigned int whichCase) = 0;

            virtual const Utils::Vector2 getTextureRect() const = 0;
            virtual const unsigned int getTextureRectWhich() const = 0;

            virtual const Utils::Vector2 getPosition() const = 0;
            virtual const Utils::Vector2 getSize() const = 0;
            virtual const float getRotation() const = 0;
            virtual const bool getVisible() const = 0;

            virtual const std::string &getTexture() const = 0;

    };

}

#endif /* !ISPRITE_HPP_ */
