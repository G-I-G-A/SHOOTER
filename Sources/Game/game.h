#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Field/renderfield.h"
#include "Bullet/bullet.h"

class game
{
public:
    game();
    ~game();

    void Run();
    void processEvents();
    void update(sf::Time deltaTime);
    void render();
    void handlePlayerInput(sf::Keyboard::Key key, bool isPressed);

    sf::RenderWindow MainWindow;
protected:
    static const sf::Time TimePerFrame;

    std::vector<bullet> allBullets;
};

#endif // GAME_H
