#ifndef RENDERFIELD_H
#define RENDERFIELD_H

#include <SFML/Graphics.hpp>
#include <iostream>

class renderfield
{
public:
    renderfield();
    ~renderfield();

    void setSpriteOnMap(int type, int lines, int columns);

    static sf::Sprite upWallSprite;
    static sf::Sprite downWallSprite;
    static sf::Sprite rightWallSprite;
    static sf::Sprite leftWallSprite;
    static sf::Sprite groundSprite;
    static sf::Sprite exitSprite;
    static sf::Sprite topLCornerSprite;
    static sf::Sprite topRCornerSprite;
    static sf::Sprite botLCornerSprite;
    static sf::Sprite botRCornerSprite;

    static std::vector<sf::Sprite> allSprites;

protected:
     sf::Texture texture;
};

#endif // RENDERFIELD_H
