#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Assets/assets.h"
#include "Bullet/bullet.h"

class Player
{
public:
    Player();
    void InitializedPlayer();
    sf::Sprite getPlayerShape();
    sf::Sprite getPlayerSprite();
    void PlayerDraw();
    void playerMovement(int x, int y);
    void setPlayerPosition();
    void setRotation(std::string direction);
    void changeScene();

    void isMovable();
    void resetMovable();
    void setAngle(float angle);

    float getPosX();
    float getPosY();
    float getAngle();

    void Shoot();
    void updateShoot();
    static std::vector<Bullet*> allPlayerBullets;

protected:
    sf::Sprite PlayerSprite;
    sf::Texture PlayerTexture;
    Assets* assetPlayer;
    Bullet* m_playerBullet;


    float playerPosX;
    float playerPosY;

    float angleVisee;
    bool borderReach;
    int VBorder;
    int HBorder;

    bool CanMoveUp = true;
    bool CanMoveDown = true;
    bool CanMoveLeft = true;
    bool CanMoveRight = true;
};


#endif // PLAYER_H
