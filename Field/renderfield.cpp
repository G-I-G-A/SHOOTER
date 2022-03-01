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
std::vector<sf::Sprite> renderfield::allSprites;
//sf::Texture RenderField::texture;

renderfield::renderfield()
{

}

renderfield::~renderfield() {}

void renderfield::setSpriteOnMap(int type, int lines, int columns) {

    std::cout << "line: " << lines << "\t column: " << columns << "\n";

    texture.loadFromFile("C:/Users/julie/Documents/Exos/SHOOTER/Assets/Sprites/Set.png");

    switch (type) {
    case 1:
    upWallSprite.setTexture(texture);
    //upWallSprite.setTextureRect(sf::IntRect(4 * 48, 3 * 48, 48, 48)); a definir en fonction du sprite
    upWallSprite.setPosition(columns * 48, lines * 48);
    allSprites.push_back(upWallSprite);
    //Game::MainWindow.draw(upWallSprite);
        break;
    case 2:
    downWallSprite.setTexture(texture);
    //downWallSprite.setTextureRect(sf::IntRect(4 * 48, 3 * 48, 48, 48)); a definir en fonction du sprite
    downWallSprite.setPosition(columns * 48, lines * 48);
    allSprites.push_back(downWallSprite);
    //Game::MainWindow.draw(downWallSprite);
        break;
    case 3:
    rightWallSprite.setTexture(texture);
    //rightWallSprite.setTextureRect(sf::IntRect(4 * 48, 3 * 48, 48, 48)); a definir en fonction du sprite
    rightWallSprite.setPosition(columns * 48, lines * 48);
    allSprites.push_back(rightWallSprite);
    //Game::MainWindow.draw(rightWallSprite);
        break;
    case 4:
    leftWallSprite.setTexture(texture);
    //leftWallSprite.setTextureRect(sf::IntRect(4 * 48, 3 * 48, 48, 48)); a definir en fonction du sprite
    leftWallSprite.setPosition(columns * 48, lines * 48);
    allSprites.push_back(leftWallSprite);
    //Game::MainWindow.draw(leftWallSprite);
        break;
    case 5:
    groundSprite.setTexture(texture);
    //groundSprite.setTextureRect(sf::IntRect(4 * 48, 3 * 48, 48, 48)); a definir en fonction du sprite
    groundSprite.setPosition(columns * 48, lines * 48);
    allSprites.push_back(groundSprite);
    //Game::MainWindow.draw(groundSprite);
        break;
    case 6:
    exitSprite.setTexture(texture);
    //exitSprite.setTextureRect(sf::IntRect(4 * 48, 3 * 48, 48, 48)); a definir en fonction du sprite
    exitSprite.setPosition(columns * 48, lines * 48);
    allSprites.push_back(exitSprite);
    //Game::MainWindow.draw(exitSprite);
        break;
    case 7:
    topLCornerSprite.setTexture(texture);
    //topLCornerSprite.setTextureRect(sf::IntRect(4 * 48, 3 * 48, 48, 48)); a definir en fonction du sprite
    topLCornerSprite.setPosition(columns * 48, lines * 48);
    allSprites.push_back(topLCornerSprite);
    //Game::MainWindow.draw(topLCornerSprite);
        break;
    case 8:
    topRCornerSprite.setTexture(texture);
    //topRCornerSprite.setTextureRect(sf::IntRect(4 * 48, 3 * 48, 48, 48)); a definir en fonction du sprite
    topRCornerSprite.setPosition(columns * 48, lines * 48);
    allSprites.push_back(topRCornerSprite);
    //Game::MainWindow.draw(topRCornerSprite);
        break;
    case 9:
    botLCornerSprite.setTexture(texture);
    //botLCornerSprite.setTextureRect(sf::IntRect(4 * 48, 3 * 48, 48, 48)); a definir en fonction du sprite
    botLCornerSprite.setPosition(columns * 48, lines * 48);
    allSprites.push_back(botLCornerSprite);
    //Game::MainWindow.draw(botLCornerSprite);
        break;
    case 10:
    botRCornerSprite.setTexture(texture);
    //botRCornerSprite.setTextureRect(sf::IntRect(4 * 48, 3 * 48, 48, 48)); a definir en fonction du sprite
    botRCornerSprite.setPosition(columns * 48, lines * 48);
    allSprites.push_back(botRCornerSprite);
    //Game::MainWindow.draw(botRCornerSprite);
        break;
    }
    //Game::MainWindow.display();

}
