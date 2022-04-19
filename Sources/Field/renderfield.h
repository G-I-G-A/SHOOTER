#ifndef RENDERFIELD_H
#define RENDERFIELD_H

#include <SFML/Graphics.hpp>
#include <iostream>

class RenderField
{
public:
    RenderField();
    ~RenderField();

    void setSpriteOnMap(int type, int lines, int columns);

    static sf::Sprite grassSprite;
    static sf::Sprite dirtSprite;
    static sf::Sprite waterSprite;

    static std::vector<sf::Sprite> allSprites;

protected:
     sf::Texture texture;
};

#endif // RENDERFIELD_H
