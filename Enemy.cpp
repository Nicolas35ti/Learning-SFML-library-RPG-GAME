#include "Enemy.h"
#include <iostream>

void Enemy::Initialize()
{
}

void Enemy::Load()
{
    if(texture.loadFromFile("assets/enemy/textures/enemy-spritesheet.png")) {
        std::cout << "Player image loaded!" << std::endl;
        sprite.setTexture(texture);
        sprite.setPosition(sf::Vector2f(1600, 700));

        int XIndex = 4;
        int YIndex = 0;

        sprite.setTextureRect(sf::IntRect(XIndex * 32, YIndex * 64, 32, 64));
        sprite.scale(sf::Vector2f(2, 2));
    } else {
        std::cout  << "Enemy image failed to load! :(" << std::endl;
    }
}

void Enemy::Update()
{
}

void Enemy::Draw(sf::RenderWindow& window)
{
    window.draw(sprite);
}
