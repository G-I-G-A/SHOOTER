#include "renderfield.h"

sf::Sprite renderfield::upWallSprite;
sf::Sprite renderfield::downWallSprite;
sf::Sprite renderfield::rightWallSprite;
sf::Sprite renderfield::leftWallSprite;
sf::Sprite renderfield::groundSprite;
sf::Sprite renderfield::exitSprite;
sf::Sprite renderfield::topLCornerSprite;
sf::Sprite renderfield::topRCornerSprite;
sf::Sprite renderfield::botLCornerSprite;
sf::Sprite renderfield::botRCornerSprite;
sf::Sprite renderfield::enemySprite;
sf::Sprite renderfield::playerSprite;
std::vector<sf::Sprite> renderfield::allSprites;

sf::Sprite renderfield::printSprite ;
//sf::Texture renderfield::texture;

renderfield::renderfield()
{

}

renderfield::~renderfield() {}

void renderfield::setSpriteOnMap(int type, int lines, int columns) {

    //std::cout << "line: " << lines << "\t column: " << columns << "\n";

    texture.loadFromFile("C:/Users/julie/Documents/Exos/SHOOTER/Assets/Sprites/Set.png");



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

void renderfield::setEnemyOnMap(char type, float x, float y){

    textureEnemy.loadFromFile("C:/Users/julie/Documents/Exos/SHOOTER/Assets/Sprites/Enemy.png");

    switch(type) {

    case 'R':
        enemySprite.setRotation(270.0f);
        break;
    case 'T':
        enemySprite.setRotation(180.0f);
        break;
    }

    enemySprite.setTexture(textureEnemy);
    enemySprite.setTextureRect(sf::IntRect(0 * 96, 0 * 96, 96, 96));
    enemySprite.setPosition(sf::Vector2f(x, y));
    enemySprite.setOrigin(48.0f, 48.0f);
    allSprites.push_back(enemySprite);

}

void renderfield::setPlayerOnMap(float x, float y){

    texturePlayer.loadFromFile("C:/Users/julie/Documents/Exos/SHOOTER/Assets/Sprites/Player.png");
    playerSprite.setTexture(texturePlayer);
    playerSprite.setTextureRect(sf::IntRect(0 * 96, 0 * 96, 96, 96));
    playerSprite.setPosition(sf::Vector2f(x, y));
    playerSprite.setOrigin(48.0f, 48.0f);
    allSprites.push_back(playerSprite);

}
