#ifndef BULLET_H
#define BULLET_H

#include <iostream>
#include <vector>


class bullet
{
public:
    bullet(float PosPlayerX, float PosPlayerY, float AnglePlayer, float PosEnX, float PosEnY, bool IsPlayer, float Speed);
    ~bullet();

    void drawBullet();
    void setOriginBullet();
    void moveBullet();

protected:
    float m_PosPlayerX;
    float m_PosPlayerY;
    float m_AnglePlayer;
    float m_PosEnX;
    float m_PosEnY;
    bool m_IsPlayer;
    float m_Speed;

};

#endif // BULLET_H
