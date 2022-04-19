#ifndef ENEMY_H
#define ENEMY_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include "Field/renderfield.h"



class Enemy
{
public:
    Enemy(std::string name, float health, float power, float speed, float posX, float posY);
    ~Enemy();

    void initEnemyOnMap(char type, float x, float y);

    float getPower();
    float getHealth();
    float getEnemySpeed();
    float getPositionX();
    float getPositionY();

    std::string getName();
    sf::Texture getTexture();
    sf::Sprite getSprite();

    void setDamage(float damages);
    void setPositionEnemy(float posX, float posY);
    void EnemyDraw();

    static std::vector<sf::Sprite> EnemiesSprites;
    static sf::Sprite enemySprite;

protected:

    sf::Texture m_textureEnemy;
    std::string m_name;

    float m_health;
    float m_power;
    float m_speed;
    float m_posX;
    float m_posY;
};

#endif // ENEMY_H
