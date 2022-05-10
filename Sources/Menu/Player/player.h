#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Assets/assets.h"

class Player
{
public:
    Player();
    void InitializedPlayer();
    sf::RectangleShape getPlayerShape();
    sf::Sprite getPlayerSprite(); //
    void PlayerDraw(); //
    void playerMovement(int x, int y);
    void setPlayerPosition();
    void changeScene();

    void setRotation(std::string direction); //

    void isMovable();
    void resetMovable();
    void setAngle(float angle);

protected:

    sf::Sprite PlayerSprite; //
    sf::Texture PlayerTexture; //
    Assets* assetPlayer; //
    sf::RectangleShape PlayerShape;

    float playerPosX;
    float playerPosY;
    bool borderReach;
    int VBorder;
    int HBorder;

    bool CanMoveUp = true;
    bool CanMoveDown = true;
    bool CanMoveLeft = true;
    bool CanMoveRight = true;
};

#endif // PLAYER_H
