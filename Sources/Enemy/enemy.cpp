#include "enemy.h"

using namespace std;

Enemy::Enemy()
{

}

Enemy::~Enemy()
{

}

void Enemy::setDamage(float damages)
{
    health = health - damages;
}

float Enemy::getPower()
{
    return power;
}

float Enemy::getHealth()
{
    return health;
}


