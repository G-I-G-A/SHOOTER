#include "player.h"

Player::Player(float x, float y) : playerPosX(x), playerPosY(y)
{
    setPlayerPosition();
    PlayerDraw();

}

void Player::InitializedPlayer() {

    setPlayerPosition();
}

sf::Sprite Player::getPlayerShape() {
    return PlayerShape;
}

void Player::playerMovement(int x, int y) {

    playerPosX += 5 * x;
    playerPosY += 5 * y;
}

void Player::setPlayerPosition() {
    PlayerShape.setPosition(playerPosX, playerPosY);
}

void Player::PlayerDraw() {

    std::string filename = "../Assets/Sprites/Player.png";
    assetPlayer = new Assets(playerPosX, playerPosY, 96.0f, 96.0f, 0.0f, filename);
    PlayerShape = assetPlayer->getSprite();
}

void Player::setRotation(std::string direction){
    assetPlayer->turnAsset(direction);
    std::cout << direction;
}

void Player::setAngle(float angle) {
    assetPlayer->setAngle(angle);
}

