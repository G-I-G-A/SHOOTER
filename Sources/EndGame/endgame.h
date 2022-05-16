#ifndef ENDGAME_H
#define ENDGAME_H

#include <iostream>
#include <fstream>
#include <SFML/Graphics.hpp>
#include "Menu/menu.h"

class EndGame
{
public:
    EndGame(bool isWinner, float timer);
    ~EndGame();
    void CalculateScore();
    void SaveScore();
    void Display();

protected:
    sf::Text TextEnd;
    sf::Font font;
    int ScorePlayer = 0;
    sf::Event eventEnd;
    bool m_isWinner;
    float m_timer;
};

#endif // ENDGAME_H
