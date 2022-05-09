#ifndef FIELD_H
#define FIELD_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include "renderfield.h"
#include "Enemy/enemy.h" //
#include "Player/player.h"//


class Field
{
public:
    Field();
    ~Field();

    RenderField map;

    void getTilesFromFile();
    void checkPutTower();

    void PutSprite(); //
    void PutEnemies(); //
    void updateEnemies(); //


    std::vector<Enemy*> allEnnemies; //

protected:
    int nbLines = 0;
    unsigned long long indexColumns = 0;
    int indexLines = 0;
    int SpriteCase = 0; //

    std::string getTile;
    std::vector<char> allTiles;
    sf::Texture texture;

    float posX = 0.0f;
    bool wayBack = false;
};

#endif // FIELD_H
