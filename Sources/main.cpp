#include <iostream>
#include "Game/game.h"
#include "Field/field.h"
#include "Field/renderfield.h"
#include "Menu/menu.h"

using namespace std;

int main()
{
    Field::Instance()->getTilesFromFile();
    Menu menu;
    menu.mainMenu();
    //RenderField map;
    //map.setSpriteOnMap();
//    Game game;
//    game.Run();
    return (0);
}
