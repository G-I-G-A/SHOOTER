#ifndef FIELD_H
#define FIELD_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include "renderfield.h"

class Field
{
public:
    Field();
    ~Field();

    RenderField map;

    void getTilesFromFile();
    void checkPutTower();

protected:
    int nbLines = 0;
    unsigned long long indexColumns = 0;
    int indexLines = 0;

    std::string getTile;
    std::vector<char> allTiles;
    sf::Texture texture;
};

#endif // FIELD_H
