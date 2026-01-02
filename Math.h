#pragma once
#include <SFML/Graphics.hpp>
 
class Math {
    public:
    static sf::Vector2f NormalizeVector(sf::Vector2f vector);   //static permite que use uma função sem que precise criar um objeto (só deixa ter 1 classe)
};