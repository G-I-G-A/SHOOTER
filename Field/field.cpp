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
//    for (unsigned long long i = 0; i < allTiles.size(); i++) {
//                cout << allTiles[i] << " ";
//                cout.flush();
//    }
    checkPutTower();
}

void field::checkPutTower() {
    for (unsigned long long i = 0; i < allTiles.size(); i++) {

        if (allTiles[i] == 'U') {
            map.setSpriteOnMap(1, indexLines, indexColumns);
        } else if (allTiles[i] == 'D') {
            map.setSpriteOnMap(2, indexLines, indexColumns);
        } else if (allTiles[i] == 'R') {
            map.setSpriteOnMap(3, indexLines, indexColumns);
        } else if (allTiles[i] == 'L') {
            map.setSpriteOnMap(4, indexLines, indexColumns);
        } else if (allTiles[i] == 'G') {
            map.setSpriteOnMap(5, indexLines, indexColumns);
        } else if (allTiles[i] == 'E') {
            map.setSpriteOnMap(6, indexLines, indexColumns);
        } else if (allTiles[i] == '1') {
            map.setSpriteOnMap(7 indexLines, indexColumns);
        } else if (allTiles[i] == '2') {
            map.setSpriteOnMap(8, indexLines, indexColumns);
        } else if (allTiles[i] == '3') {
            map.setSpriteOnMap(9, indexLines, indexColumns);
        } else if (allTiles[i] == '4') {
            map.setSpriteOnMap(10, indexLines, indexColumns);
        } else {
            cerr << "WARNING WRONG LETTER !";
        }
        indexColumns++;

        if (indexColumns == allTiles.size() / nbLines) {
            indexLines++;
            indexColumns = 0;
        }
    }
}
