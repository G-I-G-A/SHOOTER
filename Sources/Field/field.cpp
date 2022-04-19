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
    checkPutTower();
}

void Field::checkPutTower() {
    for (unsigned long long i = 0; i < allTiles.size(); i++) {

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
            break;
        case '4' :
            SpriteCase = 10;
            break;
        default:
            cerr << "WARNING WRONG LETTER !";
            }

        map.initSpriteOnMap(SpriteCase, indexLines, indexColumns);
        indexColumns++;

        if (indexColumns == allTiles.size() / nbLines) {
            indexLines++;
            indexColumns = 0;
        }
    }
}

void Field::PutEnemies(){

    //creation des ennemies || a modifier
    Enemy* enemy1 = new Enemy ("enemy1", 100, 1.0f, 1.0f, 80.0f, 80.0f);
    //Enemy* enemy2 = new Enemy("enemy2", 100,1.0f,1.0f, 120.f, 540.0f);
    Enemy* enemy3 = new Enemy("enemy3", 100,1.0f,1.0f, 960.0f, 750.0f);

    allEnnemies.push_back(enemy1);
    //allEnnemies.push_back(enemy2);
    //allEnnemies.push_back(enemy3);

    enemy1->initEnemyOnMap('R', enemy1->getPositionX(), enemy1->getPositionY());
    //enemy2->initEnemyOnMap('R', enemy2->getPositionX(), enemy2->getPositionY());
    //enemy2->initEnemyOnMap('T', enemy3->getPositionX(), enemy3->getPositionY());

}

void Field::PutPlayer(){
    map.initPlayerOnMap(1030.0f, 85.0f);
}

void Field::updateEnemies()
{
    //std::cout << allEnnemies[1].getName();

    float dirX = 1.f;
    float dirY = 1.f;

    allEnnemies[0]->setPositionEnemy(dirX, dirY);

    //std::cout << "call every frame";
}
