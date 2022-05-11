#include "enemy.h"

sf::Sprite *Enemy::enemySprite;
std::vector<Assets*> Enemy::EnemiesSprites;

using namespace std;

Enemy::Enemy(std::string name, float health, float power, float speed, float posX, float posY, float angle)
    : m_name(name), m_health(health), m_power(power), m_speed(speed), m_posX(posX), m_posY(posY), m_angleInit(angle)
{
    EnemyDraw();
    //std::cout << "Enemy Constr";
}

Enemy::~Enemy()
{

}

void Enemy::EnemyDraw(){

<<<<<<< Updated upstream
    std::string filename = "../Assets/Sprites/Enemy.png";
=======
    std::string filename = "../Assets/AssetsFiles/Sprites/Enemy.png";
>>>>>>> Stashed changes
    m_assetEnemy = new Assets(m_posX, m_posY, 96.0f, 96.0f, m_angleInit, filename);
    spriteEnemy = m_assetEnemy->getSprite();
    EnemiesSprites.push_back(m_assetEnemy);
<<<<<<< Updated upstream

    /*m_textureEnemy.loadFromFile("../Assets/Sprites/Enemy.png");
    enemySprite->setTexture(this->m_textureEnemy);*/
=======
    //std::cout << EnemiesSprites.size();

/*
    m_textureEnemy.loadFromFile("../Assets/Sprites/Enemy.png");
    enemySprite->setTexture(this->m_textureEnemy);
*/

>>>>>>> Stashed changes
}

float Enemy::getPower() { return m_power;}
float Enemy::getHealth() { return m_health;}
float Enemy::getEnemySpeed() {return m_speed;}
float Enemy::getPositionX() {return m_posX;}
float Enemy::getPositionY() {return m_posY;}
std::string Enemy::getName() {return m_name;}
sf::Texture Enemy::getTexture() {return m_textureEnemy;}
sf::Sprite Enemy::getSprite() {return *enemySprite;}

void Enemy::setDamage(float damages)
{
    m_health = m_health - damages;
}


