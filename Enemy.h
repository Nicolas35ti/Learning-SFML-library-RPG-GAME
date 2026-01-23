#pragma once
#include <SFML/Graphics.hpp>

class Enemy {
    private:
    sf::Texture texture;

    
    
    sf::Text healthText;
    sf::Font font;
    
    
    public:
    sf::Vector2i size;
    sf::RectangleShape boundingRectangle;
    sf::Sprite sprite;
    
    int health;

    public:
    Enemy();
    ~Enemy();

    void changeHealth(int hp);

    void Initialize();
    void Load();
    void Update(float deltaTime);
    void Draw(sf::RenderWindow& window);
    
};