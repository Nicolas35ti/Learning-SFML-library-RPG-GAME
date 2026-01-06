#include <SFML/Graphics.hpp>
#include <iostream>

#include "FrameRate.h"
#include "Player.h"
#include "Enemy.h"

int main() {

    //-------------------------------- INITIALIZE -----------------------------------
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "RPG Game", sf::Style::Default, settings);
    window.setFramerateLimit(360);
    //-------------------------------- INITIALIZE -----------------------------------
    FrameRate frameRate;
    Player player;
    Enemy enemy;

    //-------------------------------- INITIALIZE -----------------------------------
    frameRate.Initialize();
    player.Initialize();
    enemy.Initialize();
    //-------------------------------- INITIALIZE -----------------------------------
    
    //-------------------------------- LOAD -----------------------------------
    frameRate.Load();
    player.Load();
    enemy.Load();
    //-------------------------------- LOAD -----------------------------------

    sf::Clock clock;
    double deltaTime;
    //main game loop
    while(window.isOpen()) {
        //começa a medir quanto tempo o clock demora
        //agora nao importa em quanto estiver o fps, o movimento de tudo vai ser igual 
        sf::Time deltaTimeTimer = clock.restart();
        double deltaTime = deltaTimeTimer.asMicroseconds() / 1000.0;

        //std::cout << "FPS: " << 1000 / deltaTime << " | frameTime:" << deltaTime<< std::endl;

        //-------------------------------- UPDATE -----------------------------------
        sf::Event event;
        //verifica se ocorre algum evento na janela e se houver salva na variavel "evento"
        while(window.pollEvent(event)) {
            if(event.type == sf::Event::Closed) {
                window.close();
            }
        }

        frameRate.Update(deltaTime);
        enemy.Update(deltaTime);
        player.Update(deltaTime,enemy);

        //-------------------------------- UPDATE -----------------------------------

        //-------------------------------- DRAW -----------------------------------
        window.clear(sf::Color::Black);

        enemy.Draw(window);
        player.Draw(window);
        frameRate.Draw(window);
    
        window.display();
        //-------------------------------- DRAW -----------------------------------

    }

    return 0;
}
