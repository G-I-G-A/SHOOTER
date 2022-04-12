#include "enemy.h"

sf::Sprite Enemy::enemySprite;
std::vector<sf::Sprite> Enemy::EnemiesSprites;

using namespace std;

Enemy::Enemy(std::string name, float health, float power, float speed, float posX, float posY)
{
    m_name = name;
    m_health = health;
    m_power = power;
    m_speed = speed;
    m_posX = posX;
    m_posY = posY;
    EnemyDraw();
    //std::cout << "Enemy Constr";
}

Enemy::~Enemy()
{

}

void Enemy::EnemyDraw(){

    this->m_textureEnemy.loadFromFile("C:/Users/julie/Documents/Exos/SHOOTER/Assets/Sprites/Enemy.png");
    this->enemySprite.setTexture(this->m_textureEnemy);
}

float Enemy::getPower() { return m_power;}
float Enemy::getHealth() { return m_health;}
float Enemy::getEnemySpeed() {return m_speed;}
float Enemy::getPositionX() {return m_posX;}
float Enemy::getPositionY() {return m_posY;}
std::string Enemy::getName() {return m_name;}
sf::Texture Enemy::getTexture() {return m_textureEnemy;}
sf::Sprite Enemy::getSprite() {return enemySprite;}

void Enemy::setDamage(float damages)
{
    m_health = m_health - damages;
}


void Enemy::setPositionEnemy(float x, float y){
    m_posX = m_posX + x;
    m_posY = m_posY + y;
    this->enemySprite.move(sf::Vector2f(m_posX, m_posY));
    //std::cout << m_posX << m_posY;

}


void Enemy::initEnemyOnMap(char type, float x, float y){

    switch(type) {

    case 'R':
        enemySprite.setRotation(270.0f);
        break;
    case 'T':
        enemySprite.setRotation(180.0f);
        break;
    }

    this->enemySprite.setPosition(x, y);
    this->enemySprite.setTextureRect(sf::IntRect(0 * 96, 0 * 96, 96, 96));
    this->enemySprite.setOrigin(48.0f, 48.0f);
    EnemiesSprites.push_back(enemySprite);

}

