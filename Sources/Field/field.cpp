#include "field.h"

using namespace std;

field::field()
{

}

field::~field() {}

void field::getTilesFromFile()
{
    string lineR;
    ifstream tile;

    tile.open ("C:/Users/julie/Documents/Exos/SHOOTER/Assets/ExternFiles/terrain.txt");

    if (tile.is_open()) {
        while (getline(tile,lineR)) {
            for (int i = 0; lineR[i] != 0; ++i) {
                allTiles.push_back(lineR[i]);
            }
            nbLines++;
        }
        tile.close();
    }
    PutSprite();
    PutEnemies();
    PutPlayer();
}

void field::PutSprite() {
    for (unsigned long long i = 0; i < allTiles.size(); i++) {

        //map.setSpriteOnMap(IndexFromType[allTiles[i]], indexLines, indexColumns);

        switch(allTiles[i]) {
        case 'U':
            SpriteCase = 1;
            break;
        case 'D':
            SpriteCase = 2;
            break;
        case 'R':
            SpriteCase = 3;
            break;
        case 'L':
            SpriteCase = 4;
            break;
        case 'G':
            SpriteCase = 5;
            break;
        case 'E':
            SpriteCase = 6;
            break;
        case '1':
            SpriteCase = 7;
            break;
        case '2':
            SpriteCase = 8;
            break;
        case '3':
            SpriteCase = 9;
        case '4' :
            SpriteCase = 10;
            break;
        default:
            cerr << "WARNING WRONG LETTER !";
            }

        map.setSpriteOnMap(SpriteCase, indexLines, indexColumns);
        indexColumns++;

        if (indexColumns == allTiles.size() / nbLines) {
            indexLines++;
            indexColumns = 0;
        }
    }
}

void field::PutEnemies(){
    map.setEnemyOnMap('R', 74.0f, 74.0f);
    map.setEnemyOnMap('R', 120.f, 540.0f);
    map.setEnemyOnMap('T', 960.0f, 750.0f);

}

void field::PutPlayer(){
    map.setPlayerOnMap(1030.0f, 85.0f);
}
