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

    //setPlayerPosition();
}

void Player::playerMoveUp() {
    playerPosY -= 5.f;
}

void Player::playerMoveDown() {
    playerPosY += 5.f;
}

void Player::playerMoveLeft() {
    playerPosX -= 5.f;
}

void Player::playerMoveRight() {
    playerPosX += 5.f;
}

void Player::setPlayerPosition() {
    PlayerShape.setPosition(playerPosX, playerPosY);
}
