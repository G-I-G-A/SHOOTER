#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "../Field/renderfield.h"
#include "../Player/player.h"
#include "Enemy/enemy.h"
#include "Field/field.h"
#include "Bullet/bullet.h"
#include "EndGame/endgame.h"


class Game
{
public:
    Game();
    ~Game();
    void Run();
    void processEvents();
    void update(sf::Time deltaTime);
    void render();
    void handlePlayerInput(sf::Event event, bool isPressed);
    void CheckCollision();
    void checkEndCondition();

    sf::RenderWindow MainWindow;

protected:
    static const sf::Time TimePerFrame;
    Player player;
    sf::Font font;
    sf::Text mission;
    sf::RectangleShape lifeBarPlayer;
    float ScoreTime = 0;
    int enemyCounter = 3;
    bool enemyTouched = false;

};
