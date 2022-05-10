#ifndef RENDERFIELD_H
#define RENDERFIELD_H

#include <SFML/Graphics.hpp>
#include <iostream>

class RenderField
{
public:
    RenderField();
    ~RenderField();

    void initSpriteOnMap(int type, int lines, int columns);

    void initPlayerOnMap(float x, float y); //

    void setEnemyOnMap(float x, float y); //

    static sf::Sprite upWallSprite; //
    static sf::Sprite downWallSprite; //
    static sf::Sprite rightWallSprite; //
    static sf::Sprite leftWallSprite; //
    static sf::Sprite groundSprite; //
    static sf::Sprite exitSprite; //
    static sf::Sprite topLCornerSprite; //
    static sf::Sprite topRCornerSprite; //
    static sf::Sprite botLCornerSprite; //
    static sf::Sprite botRCornerSprite; //
    static sf::Sprite playerSprite; //

    static sf::Sprite printSprite; //
    static std::vector<sf::Sprite> allSprites;

protected:
     sf::Texture texture;
     sf::Texture texturePlayer;
     int i; // a changer
     int j; // a changer
};

#endif // RENDERFIELD_H
