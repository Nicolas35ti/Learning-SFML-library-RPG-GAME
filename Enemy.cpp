#include "Enemy.h"
#include <iostream>

void Enemy::Initialize()
{
    //seta um quadrado transparente só com as bordas em vermelho
    boundingRectangle.setFillColor(sf::Color::Transparent);
    boundingRectangle.setOutlineColor(sf::Color::Blue);
    boundingRectangle.setOutlineThickness(1);
    
    size = sf::Vector2i(32, 64);
}

void Enemy::Load()
{
    if(texture.loadFromFile("assets/enemy/textures/enemy-spritesheet.png")) {
        std::cout << "Player image loaded!" << std::endl;
        sprite.setTexture(texture);
        sprite.setPosition(sf::Vector2f(1600, 700));

        int XIndex = 4;
        int YIndex = 0;

        sprite.setTextureRect(sf::IntRect(XIndex * size.x, YIndex * size.y, size.x, size.y));
        sprite.scale(sf::Vector2f(2, 2));

        boundingRectangle.setSize(sf::Vector2f(size.x * sprite.getScale().x, size.y * sprite.getScale().y));
    } else {
        std::cout  << "Enemy image failed to load! :(" << std::endl;
    }
}

void Enemy::Update(float deltaTime)
{
    boundingRectangle.setPosition(sprite.getPosition());
}

void Enemy::Draw(sf::RenderWindow& window)
{
    window.draw(sprite);
    window.draw(boundingRectangle);
}
