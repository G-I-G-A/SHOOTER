
#include <iostream>
#include <string>
#include "Game/game.h"
#include "Field/field.h"
#include "Field/renderfield.h"

int main()
{
    field field;
    field.getTilesFromFile();
    game game;
    game.Run();
}
