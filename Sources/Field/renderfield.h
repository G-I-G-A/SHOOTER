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
    void clearSpriteMap();

    void setEnemyOnMap(float x, float y);

    sf::Sprite upWallSprite;
    sf::Sprite downWallSprite;
    sf::Sprite rightWallSprite;
    sf::Sprite leftWallSprite;
    sf::Sprite groundSprite;
    sf::Sprite exitSprite;
    sf::Sprite topLCornerSprite;
    sf::Sprite topRCornerSprite;
    sf::Sprite botLCornerSprite;
    sf::Sprite botRCornerSprite;
    sf::Sprite playerSprite;

    static sf::Sprite printSprite;
    static std::vector<sf::Sprite> allSprites;

protected:
     sf::Texture texture;
     sf::Texture texturePlayer;
     int i; // a changer
     int j; // a changer
};

#endif // RENDERFIELD_H
