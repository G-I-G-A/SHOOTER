#include "game.h"

using namespace std;

const sf::Time game::TimePerFrame = sf::seconds(1.f/60.f);

game::game()
{

}

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
