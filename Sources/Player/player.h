#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Assets/assets.h"

class Player
{
public:
    Player(float x, float y);
    void InitializedPlayer();
    sf::Sprite getPlayerShape();
    void PlayerDraw();
    void playerMovement(int x, int y);
    void setPlayerPosition();


protected:
    sf::Sprite PlayerShape;
    sf::Texture PlayerTexture;
    Assets* assetPlayer;
    float playerPosX;
    float playerPosY;
};


#endif // PLAYER_H
