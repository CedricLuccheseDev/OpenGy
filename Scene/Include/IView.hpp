/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** IView
*/

#ifndef IVIEW_HPP_
#define IVIEW_HPP_

#include "ISprite.hpp"
#include "IWindow.hpp"
#include "Parser/ParserSceneFiles.hpp"

/**
 * @namespace Scene
 *
 */
namespace Scene
{

    class IView {
        public:
            virtual ~IView() = default;

            /**
             * @brief set scene with Info parsed by scene parser
             *
             * @param info
             */
            virtual void set(const Info &info) = 0;

            /**
             * @brief update scene in running times
             *
             * @param info
             * @param win
             * @param offset
             */
            virtual void update(const Info &info, Visual::IWindow &win, bool offset) = 0;

            /**
             * @brief display scene to window
             *
             * @param win
             */
            virtual void display(Visual::IWindow &win) = 0;

            /**
             * @brief Set the Error object
             *
             */
            virtual void setError(bool) = 0;

            virtual std::string getName() = 0;
            virtual std::string getPath() = 0;
            virtual bool getError() = 0;
    };
}

#endif /* !IVIEW_HPP_ */
