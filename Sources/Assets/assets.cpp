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
    m_assetSprite.setOrigin(48.0f, 48.0f); //Ajouter une variable origine ?
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

float Assets::getAngle(){return m_angle;}
sf::Sprite Assets::getSprite(){return m_assetSprite;}
sf::Texture Assets::getTexture(){return m_assetTexture;}
