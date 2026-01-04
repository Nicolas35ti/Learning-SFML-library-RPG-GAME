#include "Player.h"
#include "Math.h"
#include <iostream>

void Player::Initialize()
{
    //seta um quadrado transparente só com as bordas em vermelho
    boundingRectangle.setFillColor(sf::Color::Transparent);
    boundingRectangle.setOutlineColor(sf::Color::Red);
    boundingRectangle.setOutlineThickness(1);
    
    size = sf::Vector2i(80, 110);
}

void Player::Load()
{
    if(texture.loadFromFile("assets/player/textures/character-spritesheet.png")) {
        std::cout << "Player image loaded!" << std::endl;
        sprite.setTexture(texture);

        int XIndex = 1;
        int YIndex = 0;

        sprite.setTextureRect(sf::IntRect(XIndex * size.x, YIndex * size.y, size.x, size.y));
        sprite.setPosition(sf::Vector2f(0, 0));

        boundingRectangle.setSize(sf::Vector2f(size.x, size.y));
    } else {
        std::cout << "Player image failed to load! :(" << std::endl;
    }
}

void Player::Update(float deltaTime,Enemy& enemy)
{
    //SISTEMA DE MOVIMENTACAO
    sf::Vector2f position = sprite.getPosition();

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        sprite.setPosition(position + sf::Vector2f(0, -1) * playerSpeed * deltaTime);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        sprite.setPosition(position + sf::Vector2f(-1, 0) * playerSpeed * deltaTime);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        sprite.setPosition(position + sf::Vector2f(0, 1) * playerSpeed * deltaTime);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        sprite.setPosition(position + sf::Vector2f(1, 0) * playerSpeed * deltaTime);


    if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
        //adiciona uma nova bala no vetor bullets
        bullets.push_back(sf::RectangleShape(sf::Vector2f(50, 25)));
        //o size mostra o tamanho da lista = 3, mas quero o ultimo indice que é 2, por isso size() - 1
        //a ultima bala aparece no player
        int i = bullets.size() - 1;
        bullets[i].setPosition(sprite.getPosition());
    }

    for (size_t i = 0; i < bullets.size(); i++) {
        //direction = target - current location
        //onde a bala deve ir
        sf::Vector2f bulletDirection = enemy.sprite.getPosition() - bullets[i].getPosition();
        bulletDirection = Math::NormalizeVector(bulletDirection);  
        //move a bala [ 0 -> -> -> ->]
        bullets[i].setPosition(bullets[i].getPosition() + bulletDirection * bulletSpeed * deltaTime);
    }

    boundingRectangle.setPosition(sprite.getPosition());

    //verifica, pela funcao se o sprite do nosso player encostou no sprite do inimigo
    if(Math::DidRectCollide(sprite.getGlobalBounds(), enemy.sprite.getGlobalBounds())) {
        std::cout << "Collision" << std::endl;
    }

}

void Player::Draw(sf::RenderWindow& window)
{
    window.draw(sprite);
    window.draw(boundingRectangle);

    //renderiza todas as balas da lista
    for (size_t i = 0; i < bullets.size(); i++) {
        window.draw(bullets[i]);
    }
}
