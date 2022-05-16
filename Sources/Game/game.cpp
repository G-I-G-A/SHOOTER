#include "game.h"
#include "../Player/player.h"

using namespace std;

const sf::Time Game::TimePerFrame = sf::seconds(1.f/60.f);

Game::Game()
: MainWindow(sf::VideoMode(1600, 900), "SHOOTER JP"), player ()
{

}
Game::~Game() {}

void Game::Run()
{
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;

    sf::Clock clock2;
    sf::Time elapsedTime = clock2.getElapsedTime();

    lifeBarPlayer.setSize(sf::Vector2f(250, 20));
    lifeBarPlayer.setPosition(700, 850);
    lifeBarPlayer.setFillColor(sf::Color::Green);

    font.loadFromFile("../Assets/font/OpenSans-Bold.ttf");
    mission.setString("Faite des degats aux monstres pour gagner");
    mission.setFont(font);
    mission.setCharacterSize(24);
    mission.setPosition(550, 10);

    Field::Instance()->PutEnemies();


    while (MainWindow.isOpen())
    {
        elapsedTime = clock2.getElapsedTime();
        timeSinceLastUpdate += clock.restart();
        while (timeSinceLastUpdate > TimePerFrame)
        {
            ScoreTime++;
            timeSinceLastUpdate -= TimePerFrame;
            processEvents();
            update(TimePerFrame);
        }
        render();
    }
}

// check les events dans la fenetre de jeu

void Game::processEvents()
{
    sf::Event event;

    while (MainWindow.pollEvent(event))
    {
        switch (event.type)
        {
            case sf::Event::KeyPressed:
                handlePlayerInput(event, true);
                break;
            case sf::Event::KeyReleased:
                handlePlayerInput(event, false);
                break;
            case sf::Event::Closed:
                MainWindow.close();
                break;
            default:
                break;
        }
    }
}

// update des variable contenue dans la game loop

void Game::update(sf::Time deltaTime)
{
    if(Field::Instance()->allEnnemies.size() > 0)
    {
         Field::Instance()->updateEnemies();
    } else {
        std::cout << "No Ennemies" << std::endl;
    };

    Field::Instance()->enemiesShoot();

    for(int i = 0; i < Player::allPlayerBullets.size(); ++i) {
        Player::allPlayerBullets[i]->moveBullet(5.0f);
    }

    CheckCollision();
    checkEndCondition();
}

// verifie si la win condition est remplis

void Game::checkEndCondition() {
    if (enemyCounter < 1) {
        MainWindow.close();
        EndGame(1, ScoreTime);
    } else if (player.getLife() <= 0) {
        MainWindow.close();
        EndGame(0, ScoreTime);
    }
}

// print les sprites/shapes/... sur dans la fenetre

void Game::render()
{
    MainWindow.clear();

    for(size_t i = 0; i < RenderField::allSprites.size(); ++i) {
        MainWindow.draw(RenderField::allSprites[i]);
    }

    for(unsigned long long i = 0; i < Enemy::EnemiesSprites.size(); ++i) {
         MainWindow.draw(Enemy::EnemiesSprites[i]->getSprite());
    }

    for(unsigned long long i = 0; i < Enemy::allBullets.size(); ++i) {
         MainWindow.draw(Enemy::allBullets[i]->getRectShape());
    }

    for(unsigned long long i = 0; i < Player::allPlayerBullets.size(); ++i) {
         MainWindow.draw(Player::allPlayerBullets[i]->getRectShape());
    }

    MainWindow.draw(player.getPlayerSprite());
    MainWindow.draw(lifeBarPlayer);
    MainWindow.draw(mission);

    MainWindow.display();
}

// check les collision entre les balles et les acteurs sur le terrain

void Game::CheckCollision() {
    // Player collision
    for (Bullet* bullet : Enemy::allBullets) {
        if (player.getPlayerShape().getGlobalBounds().contains(bullet->GetPosition()))
        {
            player.UpdateLife();
            lifeBarPlayer.setSize(sf::Vector2f((player.getLife() / 2), 20));
            std::cout << "T'es touché\n";
        }
    }

    // Enemy collision
    for (Bullet* bullet : Player::allPlayerBullets) {
        for (Enemy* enemy : Field::Instance()->allEnnemies) {
            if (enemy->getSprite().getGlobalBounds().contains(bullet->GetPosition()))
            {
                enemy->setDeath();
                enemyCounter--;
                std::cout << "Enemy mort\n";
            }
        }
    }
}

// gestion des imputs du player

void Game::handlePlayerInput(sf::Event event, bool isPressed)
{

    int DeplacmentValueX = 0;
    int DeplacmentValueY = 0;
    player.resetMovable();

    if (isPressed) {
        if (event.key.code == sf::Keyboard::Z) {
            DeplacmentValueY = (-1);
            player.setAngle(180.0f);
        }
        if (event.key.code == sf::Keyboard::S) {
            DeplacmentValueY = 1;
            player.setAngle(0.0f);
        }
        if (event.key.code == sf::Keyboard::Q) {
            DeplacmentValueX = (-1);
            player.setAngle(90.0f);
        }
        if (event.key.code == sf::Keyboard::D) {
            DeplacmentValueX = 1;
            player.setAngle(270.0f);
        }
        if (event.key.code == sf::Keyboard::Space) {
            player.Shoot();
        }
        player.isMovable();
        player.playerMovement(DeplacmentValueX, DeplacmentValueY);

    }
    player.changeScene();
}
