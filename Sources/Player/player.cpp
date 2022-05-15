#include "player.h"
#include "../Field/field.h"

std::vector<Bullet*> Player::allPlayerBullets;

Player::Player()
{
    InitializedPlayer();
    PlayerDraw();
}


sf::Sprite Player::getPlayerSprite() {
    return PlayerSprite;
}

void Player::PlayerDraw() {

    std::string filename = "../Assets/Sprites/Player.png";
    assetPlayer = new Assets(playerPosX, playerPosY, 96.0f, 96.0f, 0.0f, filename);
    PlayerSprite = assetPlayer->getSprite();
}

void Player::InitializedPlayer() {
    playerPosX = 80.0f;
    playerPosY = 80.0f;
    angleVisee = 180.0f;
    setPlayerPosition();
}

void Player::playerMovement(int x, int y) {

    if ((CanMoveLeft && x < 0) || (CanMoveRight && x > 0))
        playerPosX += 32 * x;
    if ((CanMoveUp && y < 0) || (CanMoveDown && y > 0))
        playerPosY += 32 * y;
}

void Player::setPlayerPosition() {

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
}

void Player::resetMovable() {
    CanMoveUp = true;
    CanMoveDown = true;
    CanMoveLeft = true;
    CanMoveRight = true;
}

void Player::isMovable() {

    auto groundTiles = Field::Instance()->getAllTiles();

    unsigned int PlayerX = (playerPosX / 32);
    unsigned int PlayerY = (playerPosY / 32);


    for (unsigned int i = 0; i < groundTiles.size(); i++) {
        if (groundTiles[i] != 'G') {
            if (i == 55 * (PlayerY - 1) + PlayerX) {
                CanMoveUp = false;
            }
            if (i == 55 * (PlayerY + 1) + PlayerX) {
                CanMoveDown = false;
            }
            if (i == (55 * PlayerY) + (PlayerX - 1)) {
                CanMoveLeft = false;
            }
            if (i == (55 * PlayerY) + (PlayerX + 1)) {
                CanMoveRight = false;
            }
        }
    }
}

void Player::setRotation(std::string direction){

    //assetPlayer->turnAsset(direction);

}

void Player::setAngle(float angle) {

    PlayerSprite.setRotation(angle);
    angleVisee = angle;
}


float Player::getPosX(){return playerPosX;}
float Player::getPosY(){return playerPosY;}
float Player::getAngle(){return angleVisee;}


void Player::Shoot()
{
    m_playerBullet = new Bullet(getPosX(), getPosY(), getAngle(), true, 100.0f);
    allPlayerBullets.push_back(m_playerBullet);
}

void Player::updateShoot()
{
    float stepBullet = 5.0f;

    for(unsigned long long i = 0; i < allPlayerBullets.size(); ++i)
    {
        allPlayerBullets[i]->moveBullet(stepBullet);
    }
}
