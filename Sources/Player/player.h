#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include <iostream>

class Player
{
public:
    Player();
    void InitializedPlayer();
    sf::RectangleShape getPlayerShape();
    void playerMovement(int x, int y);
    void playerMoveUp();
    void playerMoveDown();
    void playerMoveLeft();
    void playerMoveRight();
    void setPlayerPosition();


protected:
    sf::RectangleShape PlayerShape;
    float playerPosX;
    float playerPosY;
};

#endif // PLAYER_H
