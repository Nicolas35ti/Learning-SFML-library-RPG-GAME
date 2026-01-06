#pragma once
#include <SFML/Graphics.hpp>

class FrameRate {
    private:
    sf::Text frameRateText;
    sf::Font font;

    double timer;

    public:
    //O construitor é sewmpr e chamado quando se cria um objeto
    //Constructor
    FrameRate();

    //Destructor
    ~FrameRate();

    void Initialize();
    void Load();
    void Update(double deltaTime);
    void Draw(sf::RenderWindow& window);
};