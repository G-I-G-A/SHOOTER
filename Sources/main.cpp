#include <iostream>
#include "Game/game.h"
#include "Field/field.h"
#include "Field/renderfield.h"
#include "Menu/menu.h"

using namespace std;

int main()
{
    Field::Instance()->getTilesFromFile(1);
    Menu menu;
    menu.mainMenu();
    return (0);
}
