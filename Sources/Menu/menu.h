#ifndef MENU_H
#define MENU_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <fstream>
#include "Game/game.h"


class Menu
{
public:
    Menu();
    void mainMenu();
    void fontTtf();
    void LoadPlayAudio();
    void setMenuSprites();
    void typingPsuedo();
    void flash();
    void notice();

    static std::string outputPsuedo;

protected:
    int i = 0;

    sf::SoundBuffer buffer;
    sf::Event eventMenu;
    sf::Sound soundMenu;

    sf::Text textTittle;
    sf::Text text;
    sf::Font fontTittle;
    sf::Font font;

    sf::Clock Clock;
    sf::Time milli;
    sf::Time clockElapsed;

    sf::Text inputPsuedo;

    sf::Texture background;
    sf::Sprite spriteBackground;

    sf::Texture textureExitB;
    sf::Sprite spriteExitB;

    sf::Texture textureRuleB;
    sf::Sprite spriteRuleB;

    sf::Texture textureNoticeB;
    sf::Sprite spriteNoticeB;

    sf::Text PrintScore;
    std::string GetScore;
    sf::Text PrintRules;
    std::string GetRules;
    sf::Text PrintPause;
};

#endif // MENU_H
