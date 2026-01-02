#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <math.h>

#include "Player.h"
#include "Enemy.h"

int main() {

    //-------------------------------- INITIALIZE -----------------------------------
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "RPG Game", sf::Style::Default, settings);
    //-------------------------------- INITIALIZE -----------------------------------
    Player player;
    Enemy enemy;

    //-------------------------------- INITIALIZE -----------------------------------
    player.Initialize();
    enemy.Initialize();
    //-------------------------------- INITIALIZE -----------------------------------
    
    //-------------------------------- LOAD -----------------------------------
    player.Load();
    enemy.Load();
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

        enemy.Update();
        player.Update(enemy);


        //-------------------------------- UPDATE -----------------------------------

        //-------------------------------- DRAW -----------------------------------
        window.clear(sf::Color::Black);

        enemy.Draw(window);
        player.Draw(window);
    
        window.display();
        //-------------------------------- DRAW -----------------------------------

    }

    return 0;
}
