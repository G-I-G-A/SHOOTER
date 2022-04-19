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

void field::PutEnemies(){

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

void field::PutPlayer(){
    map.initPlayerOnMap(1030.0f, 85.0f);
}

void field::updateEnemies()
{
    //std::cout << allEnnemies[1].getName();

    float dirX = 0.1f;
    float dirY = 0.1f;
    allEnnemies[0]->setPositionEnemy(dirX, dirY);

    //std::cout << "call every frame";
}


