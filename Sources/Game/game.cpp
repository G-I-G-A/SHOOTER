#include "game.h"
#include "../Player/player.h"

using namespace std;

const sf::Time Game::TimePerFrame = sf::seconds(1.f/60.f);

Game::Game()
: MainWindow(sf::VideoMode(1600, 900), "SHOOTER JP"), player()
{
    player.InitializedPlayer();
}
Game::~Game() {}

void Game::Run()
{
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;

    sf::Clock clock2;
    sf::Time elapsedTime = clock2.getElapsedTime();

    Field::Instance()->PutEnemies();

    while (MainWindow.isOpen())
    {
        elapsedTime = clock2.getElapsedTime();
        timeSinceLastUpdate += clock.restart();
        while (timeSinceLastUpdate > TimePerFrame)
        {
            timeSinceLastUpdate -= TimePerFrame;
            processEvents();
            update(TimePerFrame);
        }
        render();
/*
        if (elapsedTime.asMilliseconds() > 60) {
            update(TimePerFrame);
            clock2.restart();
        }
*/
    }
}

void Game::processEvents()
{
    sf::Event event;

    while (MainWindow.pollEvent(event))
    {
        switch (event.type)
        {
            case sf::Event::KeyPressed:
                handlePlayerInput(event, true);
                break;
            case sf::Event::KeyReleased:
                handlePlayerInput(event, false);
                break;
            case sf::Event::Closed:
                MainWindow.close();
                break;
            default:
                break;
        }
    }
}

void Game::update(sf::Time deltaTime)
{
    if(Field::Instance()->allEnnemies.size() > 0)
    {
        Field::Instance()->updateEnemies();
    } else {
        std::cout << "No Ennemies" << std::endl;
    }
    ;
}

void Game::render()
{
    MainWindow.clear();

    for(size_t i = 0; i < RenderField::allSprites.size(); ++i) {
        MainWindow.draw(RenderField::allSprites[i]);
    }

    MainWindow.draw(player.getPlayerSprite());
    //MainWindow.draw(Enemy::enemySprite);

    MainWindow.display();
}

void Game::handlePlayerInput(sf::Event event, bool isPressed)
{

    int DeplacmentValueX = 0;
    int DeplacmentValueY = 0;
    player.resetMovable();

    if (isPressed) {
        if (event.key.code == sf::Keyboard::Z) {
            DeplacmentValueY = (-1);
        }
        if (event.key.code == sf::Keyboard::S) {
            DeplacmentValueY = 1;
        }
        if (event.key.code == sf::Keyboard::Q) {
            DeplacmentValueX = (-1);
        }
        if (event.key.code == sf::Keyboard::D) {
            DeplacmentValueX = 1;
        }
        player.isMovable();
        player.playerMovement(DeplacmentValueX, DeplacmentValueY);
    }
    player.setAngle(90.0f);
    player.changeScene();
    //player.setPlayerPosition();
}
