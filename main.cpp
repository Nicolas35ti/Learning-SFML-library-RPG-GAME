#include <SFML/Graphics.hpp>
#include <iostream>


int main() {
    //-------------------------------- INITIALIZE -----------------------------------
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    
    sf::RenderWindow window(sf::VideoMode(800, 600), "RPG Game", sf::Style::Default, settings);
    //-------------------------------- INITIALIZE -----------------------------------

    //-------------------------------- LOAD -----------------------------------
    int XIndex = 1;
    int YIndex = 0;

    sf::Texture playerTexture;
    sf::Sprite playerSprite;

    if(playerTexture.loadFromFile("assets/player/textures/character-spritesheet.png")) {
        std::cout << "Player image loaded!" << std::endl;
        playerSprite.setTexture(playerTexture);
        playerSprite.setTextureRect(sf::IntRect(XIndex * 80, YIndex * 110, 80, 110));
    } else {
        std::cout << "Player image failed to load! :(" << std::endl;
    }
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
        window.draw(playerSprite);
        window.display();
        //-------------------------------- DRAW -----------------------------------

    }

    return 0;
}
