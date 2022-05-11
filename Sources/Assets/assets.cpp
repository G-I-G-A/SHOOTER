#include "assets.h"

Assets::Assets(float x, float y, float width, float height, float angle, std::string filename)
    : m_spritePosX(x), m_spritePosY(y),m_width(width), m_height(height), m_angle(angle), m_filename(filename)
{
    draw();
}

Assets::~Assets()
{

}

void Assets::init()
{
    m_assetSprite.setPosition(m_spritePosX, m_spritePosY);
    m_assetSprite.setRotation(m_angle);
    m_assetSprite.setTextureRect(sf::IntRect(0 * m_width, 0 * m_height, m_width, m_height));
    m_assetSprite.setOrigin(m_origin, m_origin);
}

void Assets::draw()
{
    m_assetTexture.loadFromFile(m_filename);
    m_assetSprite.setTexture(m_assetTexture);
    init();
}

void Assets::setAngle(float angle)
{
    m_angle = angle;
    m_assetSprite.setRotation(angle);
}

void Assets::setMovement(float x, float y)
{
    m_spritePosX += x;
    m_spritePosY += y;
    m_assetSprite.setPosition(m_spritePosX, m_spritePosY);
}

void Assets::setPosition(float x, float y)
{
    m_spritePosX = x;
    m_spritePosY = y;
    m_assetSprite.setPosition(m_spritePosX, m_spritePosY);
}

void Assets::turnAsset(std::string direction)
{
    float angle = 0.0f;

    if(direction == "Left"){
        angle = -90.0f;
    }
    if(direction == "Right"){
        angle = 90.0f;
    }
    if(direction == "Up"){
        angle = -180.0f;
    }
    if(direction == "Down"){
        angle = 180.0f;
    }
    m_angle += angle;
    m_assetSprite.setRotation(m_angle);
    //std::cout << angle;
}

float Assets::getAngle(){return m_angle;}
sf::Sprite Assets::getSprite(){return m_assetSprite;}
sf::Texture Assets::getTexture(){return m_assetTexture;}
