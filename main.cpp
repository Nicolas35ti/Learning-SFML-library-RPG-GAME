#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>


int main() {
    std::vector <std::string> topFiveBandsOfAllTime;
    topFiveBandsOfAllTime.reserve(5); //reserva extamante 5 espaços na RAM

    topFiveBandsOfAllTime.push_back("Nirvana");
    topFiveBandsOfAllTime.push_back("Ramones");
    topFiveBandsOfAllTime.push_back("Green Day");
    topFiveBandsOfAllTime.push_back("Descendents");
    topFiveBandsOfAllTime.push_back("Sex Pistols");

    std::cout << "Count:" << topFiveBandsOfAllTime.size() << std::endl;
    std::cout << "Capacity:" << topFiveBandsOfAllTime.capacity() << std::endl; //Quanto espaço tem reservado na RAM.

    /*for (size_t i = 0; i < topFiveBandsOfAllTime.size(); i++) {
        std::cout << topFiveBandsOfAllTime[i] << std::endl;
    } */

















    //-------------------------------- INITIALIZE -----------------------------------
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "RPG Game", sf::Style::Default, settings);
    //-------------------------------- INITIALIZE -----------------------------------

    //-------------------------------- LOAD -----------------------------------

    //-------------------------------- Enemy ---------------------
    sf::Texture enemyTexture;
    sf::Sprite enemySprite;

    if(enemyTexture.loadFromFile("assets/enemy/textures/enemy-spritesheet.png")) {
        std::cout << "Player image loaded!" << std::endl;
        enemySprite.setTexture(enemyTexture);
        enemySprite.setPosition(sf::Vector2f(400, 100));

        int XIndex = 4;
        int YIndex = 0;

        enemySprite.setTextureRect(sf::IntRect(XIndex * 32, YIndex * 64, 32, 64));
        enemySprite.scale(sf::Vector2f(2, 2));
    } else {
        std::cout  << "Enemy image failed to load! :(" << std::endl;
    }
    //-------------------------------- Enemy ---------------------

    //-------------------------------- Player ---------------------
    sf::Texture playerTexture;
    sf::Sprite playerSprite;

    if(playerTexture.loadFromFile("assets/player/textures/character-spritesheet.png")) {
        std::cout << "Player image loaded!" << std::endl;
        playerSprite.setTexture(playerTexture);

        int XIndex = 1;
        int YIndex = 0;

        playerSprite.setTextureRect(sf::IntRect(XIndex * 80, YIndex * 110, 80, 110));
    } else {
        std::cout << "Player image failed to load! :(" << std::endl;
    }
    //-------------------------------- Player ---------------------

    //-------------------------------- LOAD -----------------------------------
    
    //main game loop
    while(window.isOpen()) {

        //-------------------------------- UPDATE -----------------------------------
        sf::Event event;
        //verifica se ocorre algum evento na janela e se houver salva na variavel "evento"
        while(window.pollEvent(event)) {
            if(event.type == sf::Event::Closed) {
                window.close();
            }
        }

        //SISTEMA DE MOVIMENTACAO
        sf::Vector2f position = playerSprite.getPosition();

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            playerSprite.setPosition(position + sf::Vector2f(0, -1));

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            playerSprite.setPosition(position + sf::Vector2f(-1, 0));

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            playerSprite.setPosition(position + sf::Vector2f(0, 1));

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            playerSprite.setPosition(position + sf::Vector2f(1, 0));
        //-------------------------------- UPDATE -----------------------------------

        //-------------------------------- DRAW -----------------------------------
        window.clear(sf::Color::Black);
        window.draw(enemySprite);
        window.draw(playerSprite);
        window.display();
        //-------------------------------- DRAW -----------------------------------

    }

    return 0;
}
