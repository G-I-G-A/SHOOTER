#include "game.h"
#include "../Player/player.h"

using namespace std;

const sf::Time Game::TimePerFrame = sf::seconds(1.f/60.f);

Game::Game()
: MainWindow(sf::VideoMode(1600, 900), "SHOOTER JP"), player (80.0f, 80.0f)
{

}
Game::~Game() {}

void Game::Run()
{
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;

    sf::Clock clock2;
    sf::Time elapsedTime = clock2.getElapsedTime();

    field.PutEnemies();

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
    if(field.allEnnemies.size() > 0)
    {
        field.updateEnemies();
    } else {
        std::cout << "No Ennemies" << std::endl;
    };
}

void Game::render()
{
    MainWindow.clear();

    for(size_t i = 0; i < RenderField::allSprites.size(); ++i) {
        MainWindow.draw(RenderField::allSprites[i]);
    }

    for(unsigned long long i = 0; i < Enemy::EnemiesSprites.size(); ++i) {
         MainWindow.draw(Enemy::EnemiesSprites[i]->getSprite());
    }
<<<<<<< Updated upstream
=======

    MainWindow.draw(player.getPlayerSprite());
>>>>>>> Stashed changes
    //MainWindow.draw(Enemy::enemySprite);
    MainWindow.draw(player.getPlayerShape());

    MainWindow.display();
}

void Game::handlePlayerInput(sf::Event event, bool isPressed)
{

    int DeplacmentValueX = 0;
    int DeplacmentValueY = 0;
<<<<<<< Updated upstream
    std::string direction;
=======
    float angleVision = 0.0f;
    player.resetMovable();
>>>>>>> Stashed changes

    if (isPressed) {
        if (event.key.code == sf::Keyboard::Z) {
            DeplacmentValueY = (-1);
<<<<<<< Updated upstream
            direction = "Up";
        }
        if (event.key.code == sf::Keyboard::S) {
            DeplacmentValueY = 1;
            direction = "Down";
        }
        if (event.key.code == sf::Keyboard::Q) {
            DeplacmentValueX = (-1);
            direction = "Left";
        }
        if (event.key.code == sf::Keyboard::D) {
            DeplacmentValueX = 1;
            direction = "Right";
        }
    }

    player.setAngle(90.0f);
    player.playerMovement(DeplacmentValueX, DeplacmentValueY);
    player.setPlayerPosition();

=======
            angleVision = 180.0f;
        }
        if (event.key.code == sf::Keyboard::S) {
            DeplacmentValueY = 1;
            angleVision = 0.0f;
        }
        if (event.key.code == sf::Keyboard::Q) {
            DeplacmentValueX = (-1);
            angleVision = 90.0f;
        }
        if (event.key.code == sf::Keyboard::D) {
            DeplacmentValueX = 1;
            angleVision = 270.0f;
        }
        player.isMovable();
        player.setAngle(angleVision);
        player.playerMovement(DeplacmentValueX, DeplacmentValueY);

    }
    player.changeScene();
    //player.setPlayerPosition();
>>>>>>> Stashed changes
}
