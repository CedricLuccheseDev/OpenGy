/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** IManager
*/

#ifndef IMANAGER_HPP_
#define IMANAGER_HPP_

#include <string>

#include "IWindow.hpp"

/**
 * @namespace Scene
 *
 */
namespace Scene
{

    class ManagerException : public std::exception {
        public:
            ManagerException(const std::string &msg) : _msg(msg) {}
            virtual ~ManagerException() throw (){}

            virtual const char *what() const throw() { return _msg.c_str(); }

        private:
            std::string _msg;
    };

    class IManager {
        public:
            virtual ~IManager() = default;

            /**
             * @brief créé toute les scenes depuis le fichier d'informations scenefile.scene
             *
             * @param filename : scenefile.scene
             */
            virtual void setup(const std::string &filename) = 0;

            /**
             * @brief add new scene in the manager
             *
             * @param filename
             */
            virtual void add(const std::string &filename) = 0;

            /**
             * @brief erase scene
             *
             * @param scenename
             */
            virtual void erase(const std::string &scenename) = 0;

            /**
             * @brief set scene from filename
             *
             * @param scene
             * @param filename
             */
            virtual void set(const std::string &scene, const std::string &filename) = 0;

            /**
             * @brief run scene with IWindow
             *
             * @param win
             */
            virtual void run(Visual::IWindow &win) = 0;

            /**
             * @brief swap current scene
             *
             * @param scenename
             */
            virtual void swap(const std::string &scenename) = 0;

            virtual const std::string &getActualScene() = 0;
    };

}

#endif /* !IMANAGER_HPP_ */
