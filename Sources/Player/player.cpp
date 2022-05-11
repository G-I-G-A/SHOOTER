#include "player.h"

Player::Player(float x, float y) : playerPosX(x), playerPosY(y)
{
<<<<<<< Updated upstream
    setPlayerPosition();
    PlayerDraw();

}

void Player::InitializedPlayer() {

=======
    InitializedPlayer();
    PlayerDraw();

}

sf::Sprite Player::getPlayerSprite() {
    return PlayerSprite;
}

void Player::PlayerDraw() {

    std::string filename = "../Assets/AssetsFiles/Sprites/Player.png";
    assetPlayer = new Assets(playerPosX, playerPosY, 96.0f, 96.0f, 0.0f, filename);
    PlayerSprite = assetPlayer->getSprite();
}

void Player::InitializedPlayer() {
    playerPosX = 80.0f;
    playerPosY = 80.0f;
    angleVisee = 180.0f;
>>>>>>> Stashed changes
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
<<<<<<< Updated upstream
    PlayerShape.setPosition(playerPosX, playerPosY);
=======

    PlayerSprite.setPosition(playerPosX, playerPosY);
}

void Player::changeScene() {

    borderReach = true;

    if (playerPosX <= 0) {
        HBorder = -1;
    }
    if (playerPosX >= 1920) {
        HBorder = 1;
    }
    if (playerPosY <= 0) {
        VBorder = -1;
    }
    if (playerPosY >= 1080) {
        VBorder = 1;
    } else {
        borderReach = false;
        HBorder = 0;
        VBorder = 0;
        setPlayerPosition();
    }

    if (borderReach) {
        // appeler la fonction qui load la map
        // reset la position du perso
    }
>>>>>>> Stashed changes
}

void Player::PlayerDraw() {

    std::string filename = "../Assets/Sprites/Player.png";
    assetPlayer = new Assets(playerPosX, playerPosY, 96.0f, 96.0f, 0.0f, filename);
    PlayerShape = assetPlayer->getSprite();
}

void Player::setRotation(std::string direction){
<<<<<<< Updated upstream
    assetPlayer->turnAsset(direction);
    std::cout << direction;
=======
     assetPlayer->turnAsset(direction);
>>>>>>> Stashed changes
}

void Player::setAngle(float angle) {
    //assetPlayer->setAngle(angle);

    PlayerSprite.setRotation(angle);
}

