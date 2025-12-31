#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <math.h>

sf::Vector2f NormalizeVector(sf::Vector2f vector) {
    float m = std::sqrt(vector.x * vector.x + vector.y * vector.y);

    sf::Vector2f normalizedVector;
    normalizedVector.x = vector.x / m;
    normalizedVector.y = vector.y / m;

    return normalizedVector;
}

int main() {

    //-------------------------------- INITIALIZE -----------------------------------
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "RPG Game", sf::Style::Default, settings);
    //-------------------------------- INITIALIZE -----------------------------------

    std::vector <sf::RectangleShape> bullets;

    float bulletSpeed = 0.5f;
    //-------------------------------- LOAD -----------------------------------

    //-------------------------------- Enemy ---------------------
    sf::Texture enemyTexture;
    sf::Sprite enemySprite;

    if(enemyTexture.loadFromFile("assets/enemy/textures/enemy-spritesheet.png")) {
        std::cout << "Player image loaded!" << std::endl;
        enemySprite.setTexture(enemyTexture);
        enemySprite.setPosition(sf::Vector2f(1600, 700));

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
        playerSprite.setPosition(sf::Vector2f(0, 0));
    } else {
        std::cout << "Player image failed to load! :(" << std::endl;
    }
    //-------------------------------- Player ---------------------
    //-------------------------------- LOAD -----------------------------------
    
   //----------- CALCULATE DIRECTION OF THE BULLET -----------
    //----------- CALCULATE DIRECTION OF THE BULLET -----------

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


        //bullet.setPosition(bullet.getPosition() + bulletDirection * bulletSpeed);

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

        if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
            //adiciona uma nova bala no vetor bullets
            bullets.push_back(sf::RectangleShape(sf::Vector2f(50, 25)));
            //o size mostra o tamanho da lista = 3, mas quero o ultimo indice que é 2, por isso size() - 1
            //a ultima bala aparece no player
            int i = bullets.size() - 1;
            bullets[i].setPosition(playerSprite.getPosition());
        }

        for (size_t i = 0; i < bullets.size(); i++) {
                        //direction = target - current location
                        //onde a bala deve ir
            sf::Vector2f bulletDirection = enemySprite.getPosition() - bullets[i].getPosition();
            bulletDirection = NormalizeVector(bulletDirection);  
            //move a bala [ 0 -> -> -> ->]
            bullets[i].setPosition(bullets[i].getPosition() + bulletDirection * bulletSpeed);
        }
        //-------------------------------- UPDATE -----------------------------------

        //-------------------------------- DRAW -----------------------------------
        window.clear(sf::Color::Black);
        window.draw(enemySprite);
        window.draw(playerSprite);

        //renderiza todas as balas da lista
        for (size_t i = 0; i < bullets.size(); i++) {
            window.draw(bullets[i]);
        }

        window.display();
        //-------------------------------- DRAW -----------------------------------

    }

    return 0;
}
