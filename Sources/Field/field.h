#ifndef FIELD_H
#define FIELD_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include "renderfield.h"
#include "Enemy/enemy.h" //
#include "Player/player.h"//
#include <mutex>


class Field
{
public:

    static Field* Instance();
    Field(Field&) = delete;
    void operator=(Field&) = delete;


    RenderField map;
    void getTilesFromFile();
    void checkMap();
    void resetPosition();

    void PutSprite(); //
    void PutEnemies(); //
    void PutPlayer(); //
    void updateEnemies(); //
    void enemiesShoot();

    std::vector<char> getAllTiles();


    std::vector<Enemy*> allEnnemies; //

protected:
    Field();
    virtual ~Field();
    int nbLines = 0;
    unsigned long long indexColumns = 0;
    int indexLines = 0;
    int SpriteCase = 0; //

    std::string getTile;
    std::vector<char> allTiles;
    sf::Texture texture;
    float posX = 0.0f;
    bool wayBack = false;
    sf::Clock Clock;
    sf::Time clockElapsed ;

private:
  static Field* _instance;
  static std::mutex _mutex;
};

#endif // FIELD_H
