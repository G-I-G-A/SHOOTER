#include "bullet.h"
#include "../Field/field.h"


Bullet::Bullet(float PosEnX, float PosEnY,float AngleShoot, bool IsPlayer, float Speed)
    :  m_PosEnX(PosEnX), m_PosEnY(PosEnY), m_AngleShoot(AngleShoot), m_IsPlayer(IsPlayer), m_Speed(Speed)
{
    drawBullet();
}

Bullet::~Bullet(){
}

// Sert a print le shape de la balle

void Bullet::drawBullet(){

    m_bulletShape.setSize(sf::Vector2f(9.0f, 4.0f));
    m_bulletShape.setFillColor(sf::Color::Green);
    m_bulletShape.setPosition((m_PosEnX), (m_PosEnY));
}

void Bullet::setOriginBullet(float x, float y){
    m_PosEnX = x;
    m_PosEnY = y;
}

sf::Vector2f Bullet::GetPosition() {
    return sf::Vector2f(m_PosEnX, m_PosEnY);
}

// permet le mouvement de la balle

void Bullet::moveBullet(float step){

    auto groundTiles = Field::Instance()->getAllTiles();

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

    if (m_bulletShape.getPosition().x > 1580 || m_bulletShape.getPosition().x < 20) {
        m_bulletShape.setFillColor(sf::Color::Transparent);
        //allBullets.erase(std::find(allBullets.begin(), allBullets.end(), this));
    }
    if (m_bulletShape.getPosition().y > 880 || m_bulletShape.getPosition().y < 20) {
        m_bulletShape.setFillColor(sf::Color::Transparent);
    }
}

sf::RectangleShape& Bullet::getRectShape(){return m_bulletShape;}

