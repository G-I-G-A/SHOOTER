#include "game.h"
#include "../Player/player.h"

using namespace std;



const sf::Time Game::TimePerFrame = sf::seconds(1.f/60.f);

Game::Game()
: MainWindow(sf::VideoMode(1600, 900), "Your Awesome Game!"), player()
{
    player.InitializedPlayer();
}
Game::~Game() {}

void Game::Run()
{
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;

    while (MainWindow.isOpen())
    {
        timeSinceLastUpdate += clock.restart();
        while (timeSinceLastUpdate > TimePerFrame)
        {
            timeSinceLastUpdate -= TimePerFrame;
            processEvents();
            update(TimePerFrame);
        }
        render();
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
    // TODO: Update your objects here
    // Example: Window.draw(mPlayer);
}

void Game::render()
{
    MainWindow.clear();

    for(size_t i = 0; i < RenderField::allSprites.size(); ++i) {
        MainWindow.draw(RenderField::allSprites[i]);
    }

    MainWindow.draw(player.getPlayerShape());

    MainWindow.display();
}

void Game::handlePlayerInput(sf::Event event, bool isPressed)
{
//    switch (event.key.code)
//    {
//        case sf::Keyboard::Z:
//            DeplacmentValueX += 1.f;
//            break;
//        case sf::Keyboard::S:
//            DeplacmentValueX -= 1.f;
//            break;
//        case sf::Keyboard::Q:
//            DeplacmentValueY -= 1.f;
//            break;
//        case sf::Keyboard::D:
//            DeplacmentValueY += 1.f;
//            break;
//        default:
//            DeplacmentValueX = 0;
//            DeplacmentValueX = 0;
//            break;
//    }

    int DeplacmentValueX = 0;
    int DeplacmentValueY = 0;

    if (isPressed) {
        if (event.key.code == sf::Keyboard::Z) {
            DeplacmentValueY = (-1);
            //player.playerMoveUp();
        }
        if (event.key.code == sf::Keyboard::S) {
            DeplacmentValueY = 1;
            //player.playerMoveDown();
        }
        if (event.key.code == sf::Keyboard::Q) {
            DeplacmentValueX = (-1);
            //player.playerMoveLeft();
        }
        if (event.key.code == sf::Keyboard::D) {
            DeplacmentValueX = 1;
            //player.playerMoveRight();
        }
    }
    //sf::Keyboard::isKeyPressed(sf::Keyboard::Z)

    player.playerMovement(DeplacmentValueX, DeplacmentValueY);
    player.setPlayerPosition();
}
