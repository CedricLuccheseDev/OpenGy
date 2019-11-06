/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** ParserRessourcesFiles
*/

#include <iostream>
#include <fstream>
#include "Parser/ParserRessourcesFiles.hpp"

Ressources::Parser::Parser()
{
}

std::vector<Ressources::Data> Ressources::Parser::getList(const std::string &file)
{
    std::fstream f;
    std::vector<Ressources::Data> list;

    if (file.find(".res") == std::string::npos)
        throw Ressources::ParserException("Wrong File format (should be .res) : '" + file + "'");
    f.open(file, std::fstream::in);
    if (!f)
        throw Ressources::ParserException("Can't open file : '" + file + "'");

    for (auto i = 0; i < 4096; i++) {
        std::string temp;
        std::getline(f, temp);

        if (temp == "" || temp.length() == 0)
            break;

        if (temp[0] == '#')
            continue;

        if (temp.find(":") == std::string::npos)
            throw Ressources::ParserException("Error at line : " + std::to_string(i) + "\nHelp: line='name:pathfile'");

        std::string name = temp.substr(0, temp.find(":"));
        std::string path = temp.substr(temp.find(":") + 1);

        Ressources::Data dat(name, path);
        list.push_back(dat);
    }

    return list;
}

