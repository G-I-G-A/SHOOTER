#include "endgame.h"

EndGame::EndGame(bool isWinner, float timer) : m_isWinner(isWinner), m_timer(timer)
{
    font.loadFromFile("../Assets/font/OpenSans-Bold.ttf");
    CalculateScore();
    SaveScore();
    Display();
}

EndGame::~EndGame() {}

// calcule le score en fonction du temps et de la condition de victoire

void EndGame::CalculateScore() {
    ScorePlayer = 1000.f - (m_timer / 100.f);
    if (m_isWinner) ScorePlayer *= 2;
}

// Enregistre le score du joueur quand il gagne

void EndGame::SaveScore() {
    std::string const inventaire("../Assets/ExternFiles/scoreFile.txt");
    std::ofstream data(inventaire.c_str(), std::ofstream::out | std::ofstream::app);
    if (data) {
        data << "Nom : " << Menu::outputPsuedo << std::endl;
        data << "Score : " << ScorePlayer << std::endl;
    } else {
        std::cout << "ERREUR: Impossible d'ouvrir le fichier." << std::endl;
    }
}

// Fonction de la boucle de gameplay EndGame : Afficher le si l_on gagner ou perdu

void EndGame::Display() {
    sf::RenderWindow windowEND (sf::VideoMode(1600,900), "END");
    TextEnd.setFont(font);
    TextEnd.setCharacterSize(80);
    TextEnd.setPosition(100, 450);

    while (windowEND.isOpen()) {
        while (windowEND.pollEvent(eventEnd)) {
            if(eventEnd.key.code == sf::Keyboard::Enter) {
                windowEND.close();
            }
        }
        if (m_isWinner) {
            TextEnd.setString("BRAVO VOUS AVEZ GAGNER " + Menu::outputPsuedo);
        } else {
            TextEnd.setPosition(450, 350);
            TextEnd.setString("GAME OVER !!\n\nENTER TO QUIT");
        }

        windowEND.clear();
        windowEND.draw(TextEnd);
        windowEND.display();
    }
}
