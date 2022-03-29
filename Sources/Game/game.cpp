#include "game.h"

using namespace std;

const sf::Time game::TimePerFrame = sf::seconds(1.f/60.f);

game::game()
: MainWindow(sf::VideoMode(1600, 900), "Shooter!")
{

}
game::~game() {}

//GameLoop
void game::Run()
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

void game::processEvents()
{
    sf::Event event{};

    while (MainWindow.pollEvent(event))
    {
        switch (event.type)
        {
            case sf::Event::KeyPressed:
                handlePlayerInput(event.key.code, true);
                break;
            case sf::Event::KeyReleased:
                handlePlayerInput(event.key.code, false);
                break;
            case sf::Event::Closed:
                MainWindow.close();
                break;
            default:
                break;
        }

    }
}

void game::update(sf::Time deltaTime)
{
    // TODO: Update your objects here
    // Example: Window.draw(mPlayer);
}

void game::render()
{
    MainWindow.clear();

    for(unsigned long long i = 0; i < renderfield::allSprites.size(); ++i) {
        MainWindow.draw(renderfield::allSprites[i]);
    }

    MainWindow.display();
}

void game::handlePlayerInput(sf::Keyboard::Key key, bool isPressed)
{
    // TODO: Key events for your game
    // Example:
    // if (key == sf::Keyboard::W)
    // {
    //     mIsMovingUp = isPressed;
    // }
}
