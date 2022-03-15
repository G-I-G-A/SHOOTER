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
std::vector<sf::Sprite> renderfield::allSprites;
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
    upWallSprite.setTexture(texture);
    upWallSprite.setTextureRect(sf::IntRect(1 * 24, 0 * 24, 24, 24));
    upWallSprite.setPosition(columns * 24, lines * 24);
    allSprites.push_back(upWallSprite);
    //game::MainWindow.draw(upWallSprite);
        break;
    case 2:
    downWallSprite.setTexture(texture);
    downWallSprite.setTextureRect(sf::IntRect(1 * 24, 2 * 24, 24, 24));
    downWallSprite.setPosition(columns * 24, lines * 24);
    allSprites.push_back(downWallSprite);
    //game::MainWindow.draw(downWallSprite);
        break;
    case 3:
    rightWallSprite.setTexture(texture);
    rightWallSprite.setTextureRect(sf::IntRect(2 * 24, 1 * 24, 24, 24));
    rightWallSprite.setPosition(columns * 24, lines * 24);
    allSprites.push_back(rightWallSprite);
    //game::MainWindow.draw(rightWallSprite);
        break;
    case 4:
    leftWallSprite.setTexture(texture);
    leftWallSprite.setTextureRect(sf::IntRect(0 * 24, 1 * 24, 24, 24));
    leftWallSprite.setPosition(columns * 24, lines * 24);
    allSprites.push_back(leftWallSprite);
    //game::MainWindow.draw(leftWallSprite);
        break;
    case 5:
    groundSprite.setTexture(texture);
    groundSprite.setTextureRect(sf::IntRect(1 * 24, 1 * 24, 24, 24));
    groundSprite.setPosition(columns * 24, lines * 24);
    allSprites.push_back(groundSprite);
    //game::MainWindow.draw(groundSprite);
        break;
    case 6:
    exitSprite.setTexture(texture);
    exitSprite.setTextureRect(sf::IntRect(2 * 24, 4 * 24, 24, 24));
    exitSprite.setPosition(columns * 24, lines * 24);
    allSprites.push_back(exitSprite);
    //game::MainWindow.draw(exitSprite);
        break;
    case 7:
    topLCornerSprite.setTexture(texture);
    topLCornerSprite.setTextureRect(sf::IntRect(0 * 24, 0 * 24, 24, 24));
    topLCornerSprite.setPosition(columns * 24, lines * 24);
    allSprites.push_back(topLCornerSprite);
    //game::MainWindow.draw(topLCornerSprite);
        break;
    case 8:
    topRCornerSprite.setTexture(texture);
    topRCornerSprite.setTextureRect(sf::IntRect(2 * 24, 0 * 24, 24, 24));
    topRCornerSprite.setPosition(columns * 24, lines * 24);
    allSprites.push_back(topRCornerSprite);
    //game::MainWindow.draw(topRCornerSprite);
        break;
    case 9:
    botLCornerSprite.setTexture(texture);
    botLCornerSprite.setTextureRect(sf::IntRect(0 * 24, 2 * 24, 24, 24));
    botLCornerSprite.setPosition(columns * 24, lines * 24);
    allSprites.push_back(botLCornerSprite);
    //game::MainWindow.draw(botLCornerSprite);
        break;
    case 10:
    botRCornerSprite.setTexture(texture);
    botRCornerSprite.setTextureRect(sf::IntRect(2 * 24, 2 * 24, 24, 24));
    botRCornerSprite.setPosition(columns * 24, lines * 24);
    allSprites.push_back(botRCornerSprite);
    //game::MainWindow.draw(botRCornerSprite);
        break;
    }
    //Game::MainWindow.display();

}

void renderfield::setEnemyOnMap(char type, float x, float y){

    textureEnemy.loadFromFile("C:/Users/julie/Documents/Exos/SHOOTER/Assets/Sprites/Enemy.png");

    switch(type) {

    case 'R':
    enemySprite.setTexture(textureEnemy);
    enemySprite.setTextureRect(sf::IntRect(0 * 96, 0 * 96, 96, 96));
    enemySprite.setPosition(sf::Vector2f(x, y));
    enemySprite.setOrigin(48.0f, 48.0f);
    enemySprite.setRotation(90.0f);
    allSprites.push_back(enemySprite);
        break;
    case 'T':
    enemySprite.setTexture(textureEnemy);
    enemySprite.setTextureRect(sf::IntRect(0 * 96, 0 * 96, 96, 96));
    enemySprite.setPosition(sf::Vector2f(x, y));
    enemySprite.setRotation(0.0f);
    allSprites.push_back(enemySprite);
    }

}
