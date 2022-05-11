#include "menu.h"

std::string Menu::outputPsuedo;

Menu::Menu() {
}

void Menu::mainMenu() {

    sf::RenderWindow windowMenu (sf::VideoMode(1600,900), "SFML B3");
    //buffer.loadFromFile("C:/Qt/Projects/TOWERDEF/Assets/audio/mainTheme.ogg");

    fontTtf();
    setMenuSprites();
    LoadPlayAudio();

    while (windowMenu.isOpen()) {
        while (windowMenu.pollEvent(eventMenu)) {
            if(eventMenu.key.code == sf::Keyboard::Escape)
                windowMenu.close();

            if ((eventMenu.mouseButton.y > 500 && eventMenu.mouseButton.y < 700) && (eventMenu.mouseButton.x > 525 && eventMenu.mouseButton.x < 1125)) {
                windowMenu.close();
            }
            else if ((eventMenu.mouseButton.y > 20 && eventMenu.mouseButton.y < 70) && (eventMenu.mouseButton.x > 1530 && eventMenu.mouseButton.x < 1580)) {
                notice();
            }
            else if(eventMenu.key.code == sf::Keyboard::Space) {
                soundMenu.stop();
                windowMenu.close();
            }

            if (eventMenu.key.code == sf::Keyboard::BackSpace) {
                outputPsuedo.clear();
            }
            else if (eventMenu.type == sf::Event::TextEntered) {
                typingPsuedo();
            }

            // Fonctions de debogage //

            //click();
            //focus();
        }
        //StartRand = rand() % 1600;

        flash();

        windowMenu.clear();
        windowMenu.draw(spriteBackground);
        windowMenu.draw(textTittle);
        windowMenu.draw(text);
        windowMenu.draw(inputPsuedo);
        windowMenu.draw(spriteExitB);
        windowMenu.draw(spriteRuleB);
        windowMenu.display();
    }
}

void Menu::LoadPlayAudio() {
        soundMenu.setBuffer(buffer);
        soundMenu.play();
        soundMenu.setLoop(true);
}

void Menu::notice() {

    sf::RenderWindow window (sf::VideoMode(700,850), "COMMANDES ET SCORES");
    std::string line;
    std::ifstream myfile;

    // Accede aux scores depuis un fichier txt externe

<<<<<<< Updated upstream
    myfile.open ("C:/Users/julie/Documents/Exos/SHOOTER/Assets/ExternFiles/scores.txt");
=======
    myfile.open ("../Assets/ExternFiles/scores.txt");
>>>>>>> Stashed changes

    if (myfile.is_open()) {
        while (getline(myfile,line)) {
            GetScore += line;
            GetScore += '\n';
        }
        myfile.close();
    }
    PrintScore.setString(GetScore);
    PrintScore.setFont(font);
    PrintScore.setCharacterSize(24);
    PrintScore.setPosition(20, 430);

    GetRules.clear();
    std::string lineR;
    std::ifstream Rules;

    // Accede aux regles depuis un fichier txt externe

<<<<<<< Updated upstream
    Rules.open (".. /Assets/ExternFiles/rules.txt");
=======
    Rules.open ("../Assets/ExternFiles/rules.txt");
>>>>>>> Stashed changes

    if (Rules.is_open()) {
        while (getline(Rules,lineR)) {
            GetRules += lineR;
            GetRules += '\n';
        }
        Rules.close();
    }

    // Affiche le score et les regles

    PrintRules.setString(GetRules);
    PrintRules.setFont(font);
    PrintRules.setCharacterSize(24);
    PrintRules.setPosition(20, 0);

<<<<<<< Updated upstream
    textureNoticeB.loadFromFile("../Assets/button/exit_menu.png");
=======
    textureNoticeB.loadFromFile("../Assets/AssetsFiles/button/exit_menu.png"); // mettre les images dans le bon projet
>>>>>>> Stashed changes
    spriteNoticeB.setTexture(textureNoticeB);
    spriteNoticeB.setPosition(500, 755);
    spriteNoticeB.setScale(0.5, 0.5);

    while (window.isOpen()) {
        while ( window.pollEvent(eventMenu)) {
            if(eventMenu.key.code == sf::Keyboard::Escape)
                window.close();
            else if ((eventMenu.mouseButton.y > 755 && eventMenu.mouseButton.y < 820) && (eventMenu.mouseButton.x > 500 && eventMenu.mouseButton.x < 670)) {
                GetScore.clear();
                window.close();
            }
        }
        window.clear();
        window.draw(spriteNoticeB);
        window.draw(PrintScore);
        window.draw(PrintRules);
        window.display();
    }
}

// Charge les elements de la police d'écriture

void Menu::fontTtf () {

<<<<<<< Updated upstream
    fontTittle.loadFromFile("../Assets/Font/Amatic-Bold.ttf");
    font.loadFromFile("../Assets/Font/OpenSans-Bold.ttf");
=======
    fontTittle.loadFromFile("../Assets/AssetsFiles/font/Amatic-Bold.ttf");
    font.loadFromFile("../Assets/AssetsFiles/font/OpenSans-Bold.ttf");
>>>>>>> Stashed changes

    textTittle.setFont(fontTittle);
    textTittle.setString("SHOOTER");
    textTittle.setCharacterSize(64);
    textTittle.setPosition(430, 100);
    textTittle.setFillColor( sf::Color::White );
    textTittle.setStyle(sf::Text::Style::Bold);
    textTittle.setOutlineColor(sf::Color::Black);
    textTittle.setOutlineThickness(2);

    text.setFont(font);
    text.setString("PRESS SPACE TO PLAY");
    text.setCharacterSize(32);
    text.setPosition(610, 450);
}

// Charge et place les sprites et les textures du menu

void Menu::setMenuSprites() {

<<<<<<< Updated upstream
    background.loadFromFile("../Assets/Background/menuBackground.jpg");
    textureExitB.loadFromFile("../Assets/button/exit_menu.png");
    textureRuleB.loadFromFile("../Assets/button/block_question.png");
=======
    background.loadFromFile("../Assets/AssetsFiles/Background/menuBackground.jpg");
    textureExitB.loadFromFile("../Assets/AssetsFiles/Sprites/exit.png"); // mettre les images dans le bon projet
    textureRuleB.loadFromFile("../Assets/AssetsFiles/button/info.png"); // mettre les images dans le bon projet
>>>>>>> Stashed changes

    spriteBackground.setTexture(background);
    spriteBackground.setTextureRect(sf::IntRect(0, 0, 1600, 900));
    spriteExitB.setTexture(textureExitB);
    spriteExitB.setPosition(500, 525);
    spriteRuleB.setTexture(textureRuleB);
    spriteRuleB.setPosition(1530, 20);
}

// Fait clignoter le texte

void Menu::flash() {

    milli = sf::milliseconds(10);
    clockElapsed = Clock.getElapsedTime();

    if(clockElapsed.asSeconds() > 0.75 && i == 0) {
        text.setFillColor(sf::Color::Transparent);
        i = 1;
        Clock.restart();
    }
    else if(clockElapsed.asSeconds() > 0.5 && i == 1) {
        text.setFillColor(sf::Color::White);
        i = 0;
        Clock.restart();
    }
}

void Menu::typingPsuedo() {
    if (eventMenu.text.unicode < 128) {
        outputPsuedo += static_cast<char>(eventMenu.text.unicode);
        inputPsuedo.setString(outputPsuedo);
        inputPsuedo.setFont(font);
        inputPsuedo.setCharacterSize(24);
        inputPsuedo.setPosition(20, 20);
    }
}
