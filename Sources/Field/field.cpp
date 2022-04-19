#include "field.h"

using namespace std;


Field::Field() {
}

Field::~Field() {}

void Field::getTilesFromFile()
{
    string lineR;
    ifstream tile;

    tile.open ("C:/Qt/Projects/TOWERDEF/Assets/ExternFiles/setupField.txt");

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

void Field::checkPutTower() {
    for (unsigned long long i = 0; i < allTiles.size(); i++) {

        if (allTiles[i] == 'D') {
            map.setSpriteOnMap(1, indexLines, indexColumns);
        } else if (allTiles[i] == 'G') {
            map.setSpriteOnMap(2, indexLines, indexColumns);
        } else if (allTiles[i] == 'W') {
            map.setSpriteOnMap(3, indexLines, indexColumns);
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
