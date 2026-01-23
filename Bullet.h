#pragma once
#include <SFML/Graphics.hpp>

class Bullet {
public:
float speed;


private:
sf::RectangleShape rectangleShape;
sf::Vector2f direction;

public:
Bullet();
~Bullet();

void Initialize(const sf::Vector2f& position, sf::Vector2f& target);
void Update(float deltaTime);
void Draw(sf::RenderWindow& window);
};