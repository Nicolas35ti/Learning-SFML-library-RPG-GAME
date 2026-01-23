#include "Enemy.h"
#include <iostream>

Enemy::Enemy() : health(100)
{
}

Enemy::~Enemy()
{
}

void Enemy::changeHealth(int hp)
{
    health += hp;
    healthText.setString(std::to_string(health));
}

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
    if (font.loadFromFile("assets/fonts/Minecraft.ttf")) {
        std::cout << "Minecraft.ttf fonte carregou corretamente!" << std::endl;
        //adiciona uma fonte ao texto
        healthText.setFont(font);
        healthText.setString(std::to_string(health));
    } else {
        std::cout << "Falha ao carregar Minecraft.ttf fonte." << std::endl;
    }

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
    if (health > 0) {
        boundingRectangle.setPosition(sprite.getPosition());

        healthText.setPosition(sprite.getPosition());
    }
}

void Enemy::Draw(sf::RenderWindow& window)
{
    if (health > 0) {
        window.draw(sprite);
        window.draw(boundingRectangle);
        window.draw(healthText);
    }
}
