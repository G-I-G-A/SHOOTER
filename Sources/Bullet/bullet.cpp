#include "bullet.h"
#include "../Field/field.h"


Bullet::Bullet(float PosEnX, float PosEnY,float AngleShoot, bool IsPlayer, float Speed)
    :  m_PosEnX(PosEnX), m_PosEnY(PosEnY), m_AngleShoot(AngleShoot), m_IsPlayer(IsPlayer), m_Speed(Speed)
{
    drawBullet();
    //std::cout << m_AngleShoot;
    //std::cout << "Bullet build";
}

Bullet::~Bullet(){
    delete[] this;
}

void Bullet::drawBullet(){

    m_bulletShape.setSize(sf::Vector2f(9.0f, 4.0f));
    m_bulletShape.setFillColor(sf::Color::Green);
    m_bulletShape.setPosition((m_PosEnX), (m_PosEnY));
    //std::cout << "bullet draw";
}

void Bullet::setOriginBullet(float x, float y){
    m_PosEnX = x;
    m_PosEnY = y;
}

void Bullet::moveBullet(float step){

    auto groundTiles = Field::Instance()->getAllTiles();
    //std::cout << m_AngleShoot;

    if(m_AngleShoot == 270)
        m_PosEnX += step;
    if(m_AngleShoot == 450 || m_AngleShoot == 90)
        m_PosEnX -= step;
    if(m_AngleShoot == 180){
        m_PosEnY -= step;
        m_bulletShape.setRotation(90.0f);
    }
    if(m_AngleShoot == 360 || m_AngleShoot == 0){
        m_PosEnY += step;
        m_bulletShape.setRotation(90.0f);
    }

    m_bulletShape.setPosition(m_PosEnX, m_PosEnY);

    for (unsigned int i = 0; i < groundTiles.size(); i++) {
        if (groundTiles[i] != 'G') {
            if (i == 55 * (m_PosEnY - 1) + m_PosEnX) {
                m_bulletShape.setFillColor(sf::Color::Transparent);
            }
            if (i == 55 * (m_PosEnY + 1) + m_PosEnX) {
               m_bulletShape.setFillColor(sf::Color::Transparent);
            }
            if (i == (55 * m_PosEnY) + (m_PosEnX - 1)) {
                m_bulletShape.setFillColor(sf::Color::Transparent);
            }
            if (i == (55 * m_PosEnY) + (m_PosEnX + 1)) {
                m_bulletShape.setFillColor(sf::Color::Transparent);
            }

            //std::cout << "Balle détruite";
        }
    }

}

sf::RectangleShape Bullet::getRectShape(){return m_bulletShape;}

