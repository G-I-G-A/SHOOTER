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
}

void field::PutSprite() {
    for (unsigned long long i = 0; i < allTiles.size(); i++) {

        //map.setSpriteOnMap(IndexFromType[allTiles[i]], indexLines, indexColumns);

        switch(allTiles[i]) {
        case 'U':
        map.setSpriteOnMap(1, indexLines, indexColumns);
            break;
        case 'D':
        map.setSpriteOnMap(2, indexLines, indexColumns);
            break;
        case 'R':
        map.setSpriteOnMap(3, indexLines, indexColumns);
            break;
        case 'L':
        map.setSpriteOnMap(4, indexLines, indexColumns);
            break;
        case 'G':
        map.setSpriteOnMap(5, indexLines, indexColumns);
            break;
        case 'E':
        map.setSpriteOnMap(6, indexLines, indexColumns);
            break;
        case '1':
        map.setSpriteOnMap(7, indexLines, indexColumns);
            break;
        case '2':
        map.setSpriteOnMap(8, indexLines, indexColumns);
            break;
        case '3':
        map.setSpriteOnMap(9, indexLines, indexColumns);
        case '4' :
        map.setSpriteOnMap(10, indexLines, indexColumns);
            break;
        default:
            cerr << "WARNING WRONG LETTER !";
            }

        indexColumns++;

        if (indexColumns == allTiles.size() / nbLines) {
            indexLines++;
            indexColumns = 0;
        }
    }
}

void field::PutEnemies(){
    map.setEnemyOnMap('R', 74.0f, 74.0f);
    map.setEnemyOnMap('R', 120.f, 370.0f);
    map.setEnemyOnMap('T', 800.0f, 750.0f);

}
