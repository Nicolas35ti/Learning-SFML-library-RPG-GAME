#pragma once
#include <SFML/Graphics.hpp>
#include "Enemy.h"

class Player {
private:
    sf::Texture texture;

    std::vector <sf::RectangleShape> bullets;
    float bulletSpeed;
    float playerSpeed;

    sf::RectangleShape boundingRectangle;

    sf::Vector2i size;

    public:
    sf::Sprite sprite;

    public:
    Player();
    ~Player();

    void Initialize();  // <- called once
    void Load();        // <- called once per app start
    void Update(float deltaTime,Enemy& enemy);      // <- once per frame
    void Draw(sf::RenderWindow& window);        // <- once per frame
};