#include "Player.h"
#include "Math.h"
#include <iostream>

Player::Player() :  playerSpeed(1.0f), maxFireRate(150), fireRateTimer(0)
{
}

Player::~Player()
{
}

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

void Player::Update(float deltaTime,Enemy& enemy, sf::Vector2f& mousePosition)
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


    //-----------------------------------------------------------------------------------------------------------------------------
    //quanto tempo demnora ate o proximo disparo
    fireRateTimer += deltaTime;
    //dispara com a arma depois de um certo tempo
    if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && fireRateTimer >= maxFireRate) {
        //adiciona uma nova bala no vetor bullets
        bullets.push_back(Bullet());
        int i = bullets.size() - 1;
        bullets[i].Initialize(sprite.getPosition(), mousePosition, 0.5f);
        fireRateTimer = 0;
    }

    for (size_t i = 0; i < bullets.size(); i++) {
        //direction = target - current location
        //onde a bala deve ir
        //sf::Vector2f bulletDirection = mousePosition - bullets[i].getPosition();
        //bulletDirection = Math::NormalizeVector(bulletDirection);  
        //move a bala [ 0 -> -> -> ->]
        //bullets[i].setPosition(bullets[i].getPosition() + bulletDirection * bulletSpeed * deltaTime);

        bullets[i].Update(deltaTime);

        if (enemy.health >= 0) {
            //verifica se cada bala encostou no sprite do inimigo
            //sempre que bala encosta no inimigo, diminui a vida dele, a bala some  e printa a vida dele
            if(Math::DidRectCollide(bullets[i].GetGlobalBounds(), enemy.sprite.getGlobalBounds())) {
                enemy.changeHealth(-10);
                bullets.erase(bullets.begin() + i);
        }
    }
}

    boundingRectangle.setPosition(sprite.getPosition());
    //-----------------------------------------------------------------------------------------------------------------------------

}

void Player::Draw(sf::RenderWindow& window)
{
    window.draw(sprite);
    window.draw(boundingRectangle);

    //renderiza todas as balas da lista
    for (size_t i = 0; i < bullets.size(); i++) {
        bullets[i].Draw(window);
    }
}
