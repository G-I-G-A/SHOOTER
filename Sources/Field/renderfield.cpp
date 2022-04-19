#include "renderfield.h"

sf::Sprite RenderField::grassSprite;
sf::Sprite RenderField::dirtSprite;
sf::Sprite RenderField::waterSprite;
std::vector<sf::Sprite> RenderField::allSprites;
//sf::Texture RenderField::texture;


RenderField::RenderField() {
}

RenderField::~RenderField() {}

void RenderField::setSpriteOnMap(int type, int lines, int columns) {

    //std::cout << "line: " << lines << "\t column: " << columns << "\n";

    texture.loadFromFile("C:/Qt/Projects/TOWERDEF/Assets/Background/tileset.png");

    switch (type) {
    case 1:
    grassSprite.setTexture(texture);
    grassSprite.setTextureRect(sf::IntRect(4 * 48, 3 * 48, 48, 48));
    grassSprite.setPosition(columns * 48, lines * 48);
    allSprites.push_back(grassSprite);
    //Game::MainWindow.draw(grassSprite);
        break;
    case 2:
    dirtSprite.setTexture(texture);
    dirtSprite.setTextureRect(sf::IntRect(5 * 48, 3 * 48, 48, 48));
    dirtSprite.setPosition(columns * 48, lines * 48);
    allSprites.push_back(dirtSprite);
    //Game::MainWindow.draw(dirtSprite);
        break;
    case 3:
    waterSprite.setTexture(texture);
    waterSprite.setTextureRect(sf::IntRect(6 * 48, 3 * 48, 48, 48));
    waterSprite.setPosition(columns * 48, lines * 48);
    allSprites.push_back(waterSprite);
    //Game::Window.draw(waterSprite);
        break;
    }
    //Game::MainWindow.display();

}
