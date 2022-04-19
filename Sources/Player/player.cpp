#include "player.h"

Player::Player()
{
    PlayerShape.setSize(sf::Vector2f(50, 50));
}

void Player::InitializedPlayer() {
    playerPosX = 50;
    playerPosY = 50;
    setPlayerPosition();
}

sf::RectangleShape Player::getPlayerShape() {
    return PlayerShape;
}

void Player::playerMovement(int x, int y) {

    playerPosX += 5 * x;
    playerPosY += 5 * y;
}

void Player::setPlayerPosition() {
    PlayerShape.setPosition(playerPosX, playerPosY);
}
