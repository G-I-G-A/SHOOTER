#include "enemy.h"

sf::Sprite *Enemy::enemySprite;
std::vector<Assets*> Enemy::EnemiesSprites;
std::vector<Bullet*> Enemy::allBullets;

using namespace std;

Enemy::Enemy(std::string name, float health, float power, float speed, float posX, float posY, float angle)
    : m_name(name), m_health(health), m_power(power), m_speed(speed), m_posX(posX), m_posY(posY), m_angleInit(angle)
{
    EnemyDraw();
}

Enemy::~Enemy()
{
}

// permet le print des ennemies

void Enemy::EnemyDraw(){

    std::string filename = "../Assets/Sprites/Enemy.png";
    m_assetEnemy = new Assets(m_posX, m_posY, 96.0f, 96.0f, m_angleInit, filename);
    spriteEnemy = m_assetEnemy->getSprite();
    EnemiesSprites.push_back(m_assetEnemy);
}

// permet de creer une balle a partir des donnees de l'ennemie

void Enemy::SpawnShot() {

    m_assetBullet = new Bullet(m_assetEnemy->getPosX(), m_assetEnemy->getPosY(), m_assetEnemy->getAngle(), false, 100.0f);
    allBullets.push_back(m_assetBullet);
}


// getteurs et setteurs

float Enemy::getPower() { return m_power;}
float Enemy::getHealth() { return m_health;}
float Enemy::getEnemySpeed() {return m_speed;}
float Enemy::getPositionX() {return m_posX;}
float Enemy::getPositionY() {return m_posY;}
std::string Enemy::getName() {return m_name;}
sf::Texture Enemy::getTexture() {return m_textureEnemy;}
sf::Sprite& Enemy::getSprite() {return spriteEnemy;}
float Enemy::getAngleInit() {return m_angleInit;}

void Enemy::setDamage(float damages)
{
    m_health = m_health - damages;
}

void Enemy::setDeath()
{
    m_posX = 0;
    m_posY = 0;
    spriteEnemy.setColor(sf::Color::Transparent);
    spriteEnemy.setPosition(m_posX, m_posY);
}



