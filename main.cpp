#include <SFML/Graphics.hpp>


int main() {
    //-------------------------------- INITIALIZE -----------------------------------
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    
    sf::RenderWindow window(sf::VideoMode(800, 600), "RPG Game", sf::Style::Default, settings);
    
    sf::CircleShape shape (50.0f);
    shape.setFillColor(sf::Color::Green);
    shape.setPosition(sf::Vector2f(100, 100));
    shape.setOrigin(sf::Vector2f(shape.getRadius(), shape.getRadius()));
    shape.setOutlineThickness(10.0f);
    shape.setOutlineColor(sf::Color::Yellow);

    sf::RectangleShape rectangle (sf::Vector2f(100, 120));
    rectangle.setFillColor(sf::Color::Blue);
    rectangle.setPosition(sf::Vector2f(300, 100));
    rectangle.setOrigin(sf::Vector2f(rectangle.getSize()/2.0f));
    rectangle.setRotation(45);

    sf::CircleShape triangle(80.f, 3);
    triangle.setFillColor(sf::Color::Yellow);
    triangle.setPosition(sf::Vector2f(100, 200));

    sf::CircleShape square(80.f, 4);
    square.setFillColor(sf::Color::Magenta);
    square.setPosition(sf::Vector2f(100, 360));

    //LINHA


    //-------------------------------- INITIALIZE -----------------------------------
    
    //main game loop
    while(window.isOpen()) {

        //-------------------------------- UPDATE -----------------------------------
        sf::Event event;
        //verifica se ocorre algum evento na janela e se houver salva na variavel "evento"
        while(window.pollEvent(event)) {
            if(event.type == sf::Event::Closed) {
                window.close();
            }
        }
        //-------------------------------- UPDATE -----------------------------------

        //-------------------------------- DRAW -----------------------------------
        window.clear(sf::Color::Black);

        window.draw(shape);
        window.draw(rectangle);
        window.draw(triangle);
        window.draw(square);

        window.display();
        //-------------------------------- DRAW -----------------------------------

    }

    return 0;
}
