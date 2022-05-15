#ifndef BULLET_H
#define BULLET_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>



class Bullet
{
public:
    Bullet(float PosEnX, float PosEnY, float AnglePlayer, bool IsPlayer, float Speed);
    ~Bullet();

    void drawBullet();
    void setOriginBullet(float x, float y);
    void moveBullet(float step);
    sf::RectangleShape getRectShape();

protected:
    float m_PosEnX;
    float m_PosEnY;
    float m_AngleShoot;
    bool m_IsPlayer;
    float m_Speed;

    float m_PosPlayerX;
    float m_PosPlayerY;

    sf::RectangleShape m_bulletShape;

};

#endif // BULLET_H
