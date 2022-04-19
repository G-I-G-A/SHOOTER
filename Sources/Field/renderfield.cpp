#include "renderfield.h"

sf::Sprite RenderField::upWallSprite;
sf::Sprite RenderField::downWallSprite;
sf::Sprite RenderField::rightWallSprite;
sf::Sprite RenderField::leftWallSprite;
sf::Sprite RenderField::groundSprite;
sf::Sprite RenderField::exitSprite;
sf::Sprite RenderField::topLCornerSprite;
sf::Sprite RenderField::topRCornerSprite;
sf::Sprite RenderField::botLCornerSprite;
sf::Sprite RenderField::botRCornerSprite;
sf::Sprite RenderField::playerSprite;

sf::Sprite RenderField::printSprite;
std::vector<sf::Sprite> RenderField::allSprites;
//sf::Texture RenderField::texture;


RenderField::RenderField() {
}

RenderField::~RenderField() {}

void RenderField::initSpriteOnMap(int type, int lines, int columns) {

    //std::cout << "line: " << lines << "\t column: " << columns << "\n";

    texture.loadFromFile("C:/Qt/Projects/TOWERDEF/Assets/Sprites/Set.png");

    switch (type) {
    case 1:
        printSprite = upWallSprite;
        i = 1;
        j = 0;
        break;
    case 2:
        printSprite = downWallSprite;
        i = 1;
        j = 2;
        break;
    case 3:
        printSprite = rightWallSprite;
        i = 2;
        j = 1;
        break;
    case 4:
        printSprite = leftWallSprite;
        i = 0;
        j = 1;
        break;
    case 5:
        printSprite = groundSprite;
        i = 1;
        j = 1;
        break;
    case 6:
        printSprite = exitSprite;
        i = 2;
        j = 4;
        break;
    case 7:
        printSprite = topLCornerSprite;
        i = 0;
        j = 0;
        break;
    case 8:
        printSprite = topRCornerSprite;
        i = 2;
        j = 0;
        break;
    case 9:
        printSprite = botLCornerSprite;
        i = 0;
        j = 2;
        break;
    case 10:
        printSprite = botRCornerSprite;
        i = 2;
        j = 2;
        break;
    }

    printSprite.setTexture(texture);
    printSprite.setTextureRect(sf::IntRect(i * 32, j * 32, 32, 32));
    printSprite.setPosition(columns * 32, lines * 32);
    allSprites.push_back(printSprite);
}

void RenderField::initPlayerOnMap(float x, float y){

    texturePlayer.loadFromFile("C:/Qt/Projects/TOWERDEF/Assets/Sprites/Player.png");
    playerSprite.setTexture(texturePlayer);
    playerSprite.setTextureRect(sf::IntRect(0 * 96, 0 * 96, 96, 96));
    playerSprite.setPosition(sf::Vector2f(x, y));
    playerSprite.setOrigin(48.0f, 48.0f);
    allSprites.push_back(playerSprite);

}
