#ifndef ENEMY_H
#define ENEMY_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include "Field/renderfield.h"

class Enemy
{
public:
    Enemy();
    ~Enemy();

    float getPower();
    void setDamage(float damages);
    float getHealth();


protected:
        std::string getEnemy;

        float health;
        float power;
};

#endif // ENEMY_H
