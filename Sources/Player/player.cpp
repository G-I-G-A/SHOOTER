#include "player.h"
#include "../Field/field.h"

std::vector<Bullet*> Player::allPlayerBullets;

Player::Player()
{
    InitializedPlayer();
    PlayerDraw();
}


sf::Sprite& Player::getPlayerSprite() {
    return PlayerSprite;
}

sf::RectangleShape& Player::getPlayerShape() {
    return PlayerShape;
}

void Player::PlayerDraw() {

    std::string filename = "../Assets/Sprites/Player.png";
    assetPlayer = new Assets(playerPosX, playerPosY, 96.0f, 96.0f, 0.0f, filename);
    PlayerSprite = assetPlayer->getSprite();

    PlayerShape = sf::RectangleShape();
    PlayerShape.setSize(sf::Vector2f(32, 32));
    PlayerShape.setOrigin(sf::Vector2f(16, 16));
}

void Player::InitializedPlayer() {
    playerPosX = 80.0f;
    playerPosY = 80.0f;
    angleVisee = 180.0f;
    setPlayerPosition();
}

// permet de faire bouger le joueur si aucun mur ne le bloque

void Player::playerMovement(int x, int y) {

    if ((CanMoveLeft && x < 0) || (CanMoveRight && x > 0))
        playerPosX += 32 * x;
    if ((CanMoveUp && y < 0) || (CanMoveDown && y > 0))
        playerPosY += 32 * y;
}

void Player::setPlayerPosition() {

    PlayerSprite.setPosition(playerPosX, playerPosY);
    PlayerShape.setPosition(playerPosX, playerPosY);
}

// permet au joueur de changer de salle en atteignant un bord

void Player::changeScene() {

    borderReach = true;

    if (playerPosX <= 0) {
        Border = Border - 2;
        playerPosX = 1546;
    }
    if (playerPosX >= 1600) {
        Border += 2;
        playerPosX = 64;
    }
    if (playerPosY <= 25) {
        Border = Border - 1;
        playerPosY = 846;
    }
    if (playerPosY >= 900) {
        Border += 1;
        playerPosY = 64;
    } else {
        borderReach = false;
        setPlayerPosition();
    }

    if (borderReach) {
        // appeler la fonction qui load la map
        Field::Instance()->getTilesFromFile(Border);
    }
}

void Player::resetMovable() {
    CanMoveUp = true;
    CanMoveDown = true;
    CanMoveLeft = true;
    CanMoveRight = true;
}

// check les murs au 4 coins du joueur

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

// fonctions de tir du joueur

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

// mise a jour de la vie du joueur

void Player::UpdateLife() {
    playerLife = playerLife - 5;
}

float Player::getLife() {
    return playerLife;
}
