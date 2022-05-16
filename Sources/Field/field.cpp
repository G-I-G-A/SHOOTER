#include "field.h"

using namespace std;

Field* Field::_instance = nullptr;
std::mutex Field::_mutex;

// instancie le terrain

Field* Field::Instance()
{
  std::lock_guard lock(_mutex);

  if (!_instance) _instance = new Field();
  return _instance;
}

Field::Field() = default;
Field::~Field() = default;

vector<char> Field::getAllTiles() {
    return allTiles;
}

// Recupere les fichier textes servant de base pour print le terrain

void Field::getTilesFromFile(int scene)
{
    allTiles.clear();
    map.clearSpriteMap();

    string lineR;
    ifstream tile;

    if (scene == 1) {
        std::cout << "1" << std::endl;
        tile.open ("../Assets/ExternFiles/setupField.txt");
    }
    if (scene == 2) {
        std::cout << "2" << std::endl;
        tile.open ("../Assets/ExternFiles/setupField2.txt");
    }
    if (scene == 3) {
        std::cout << "3" << std::endl;
        tile.open ("../Assets/ExternFiles/setupField3.txt");
    }
    if (scene == 4) {
        std::cout << "4" << std::endl;
        tile.open ("../Assets/ExternFiles/setupField4.txt");
    }

    if (tile.is_open()) {
        while (getline(tile,lineR)) {
            for (int i = 0; lineR[i] != 0; ++i) {
                allTiles.push_back(lineR[i]);
            }
            nbLines++;
        }
        tile.close();
    }
    checkMap();
}

// transforme les donnees du fichier en valeurs pour le renderfield

void Field::checkMap() {
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

// set les ennemies

void Field::PutEnemies(){

    //creation des ennemies || a modifier
    Enemy* enemy1 = new Enemy("enemy1", 100, 1.0f, 1.0f, 80.0f, 230.0f, 270.0f);
    Enemy* enemy2 = new Enemy("enemy2", 100,1.0f,1.0f, 120.f, 540.0f, 270.0f);
    Enemy* enemy3 = new Enemy("enemy3", 100,1.0f,1.0f, 960.0f, 750.0f, 180.0f);


    allEnnemies.push_back(enemy1);
    allEnnemies.push_back(enemy2);
    allEnnemies.push_back(enemy3);

/*
    enemy1->initEnemyOnMap('R', enemy1->getPositionX(), enemy1->getPositionY());
    enemy2->initEnemyOnMap('R', enemy2->getPositionX(), enemy2->getPositionY());
    enemy2->initEnemyOnMap('T', enemy3->getPositionX(), enemy3->getPositionY());
*/

}

// met a jours differentes infos des ennemies

void Field::updateEnemies()
{
    float step = 0.25f;
    int maxRangeX = 300.0f;

    for(unsigned int i = 0; i < Enemy::EnemiesSprites.size(); ++i)
    {
        if(posX < maxRangeX && wayBack == false)
        {
            Enemy::EnemiesSprites[0]->setMovement(step, 0.0f);
            Enemy::EnemiesSprites[1]->setMovement(step, 0.0f);
            Enemy::EnemiesSprites[2]->setMovement(0.0f, -step);
            posX += step;
            if (posX == maxRangeX){
                wayBack = true;
                for (unsigned long long j = 0; j < Enemy::EnemiesSprites.size(); ++j){
                    Enemy::EnemiesSprites[j]->turnAsset("Down");
                }
            }
        }
        if (posX > 0.0f && wayBack == true){
            Enemy::EnemiesSprites[0]->setMovement(-step, 0.0f);
            Enemy::EnemiesSprites[1]->setMovement(-step, 0.0f);
            Enemy::EnemiesSprites[2]->setMovement(0.0f, step);
            posX -= step;
            if (posX == 0.0f){
                wayBack = false;
                for (unsigned long long j = 0; j < Enemy::EnemiesSprites.size(); ++j){
                    Enemy::EnemiesSprites[j]->turnAsset("Up");
                }
            }
        }
    }

    clockElapsed = Clock.getElapsedTime();
    if(clockElapsed.asSeconds() > 0.7)
    {
        for(unsigned long long i = 0; i < allEnnemies.size(); ++i)
        {
            allEnnemies[i]->SpawnShot();
        }
        Clock.restart();
    }
}

void Field::enemiesShoot()
{


    float stepBullet = 5.0f;
    for(unsigned long long i = 0; i < Enemy::allBullets.size(); ++i)
    {
        Enemy::allBullets[i]->moveBullet(stepBullet);
    }


}
