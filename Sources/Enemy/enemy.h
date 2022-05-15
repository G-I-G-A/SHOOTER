#ifndef ENEMY_H
#define ENEMY_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include "Field/renderfield.h"
#include "Assets/assets.h"
#include "Bullet/bullet.h"



class Enemy
{
public:
    Enemy(std::string name, float health, float power, float speed, float posX, float posY, float angle);
    ~Enemy();

    void EnemyDraw();
    void SpawnShot();

    //getters
    float getPower();
    float getHealth();
    float getEnemySpeed();
    float getPositionX();
    float getPositionY();
    float getAngleInit();
    std::string getName();
    sf::Texture getTexture();
    sf::Sprite getSprite();


    void setDamage(float damages);

    static std::vector<Assets*> EnemiesSprites;
    static sf::Sprite *enemySprite;
    static std::vector<Bullet*> allBullets;

protected:
    sf::Texture m_textureEnemy;
    sf::Sprite spriteEnemy;
    std::string m_name;
    Assets* m_assetEnemy;
    Bullet* m_assetBullet;

    float m_health;
    float m_power;
    float m_speed;
    float m_posX;
    float m_posY;
    float m_angleInit;

};

#endif // ENEMY_H
