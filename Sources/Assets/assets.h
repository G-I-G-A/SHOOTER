#ifndef ASSETS_H
#define ASSETS_H
#include <SFML/Graphics.hpp>
#include <fstream>
#include <iostream>

class Assets
{
public:
    Assets(float x, float y, float width, float height, float angle, std::string filename);
    virtual ~Assets();

    void draw();
    void init();

    virtual float getAngle();
    virtual sf::Texture getTexture();
    virtual sf::Sprite getSprite();
    virtual void setAngle(float angle);
    virtual void setMovement(float x, float y);
    virtual void setPosition(float x, float y);
    virtual void turnAsset(std::string direction);

protected:
    sf::Texture m_assetTexture;
    sf::Sprite m_assetSprite;

    float m_spritePosX;
    float m_spritePosY;
    float m_width;
    float m_height;
    float m_angle;
    std::string m_filename;

private:
    float m_origin = 48.0f;
};

#endif // ASSETS_H
