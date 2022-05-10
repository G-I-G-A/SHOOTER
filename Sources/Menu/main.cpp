#include <iostream>
#include "Game/game.h"
#include "Field/field.h"
#include "Field/renderfield.h"
#include "Menu/menu.h"

using namespace std;

int main()
{
    Menu menu;
    menu.mainMenu();
    Field::Instance()->getTilesFromFile();
    Game game;
    game.Run();
    return (0);
}
