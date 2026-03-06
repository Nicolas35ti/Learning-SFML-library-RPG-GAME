#include "Map.h"
#include <iostream>

Map::Map() :
    tileWidth(48), tileHeight(48), totalTilesX(0), totlaTilesY(0)
{

}

Map::~Map()
{

}

void Map::Initialize()
{

}

void Map::Load()
{
    if (tileSheetTexture.loadFromFile("assets/world/forest/forest-tilesheet.png")) {
        //faz o calculo da quantida dee tiles que tem horizontalmente e verticalmente
        totalTilesX = tileSheetTexture.getSize().x / tileWidth;
        totlaTilesY = tileSheetTexture.getSize().y / tileHeight;

        std::cout << totalTilesX << std::endl;
        std::cout << totlaTilesY << std::endl;

        std::cout << "City tilesheet in assets has been loaded succesfully" << std::endl;

        for (size_t i = 0; i < 10; i++) {
            sprites[i].setTexture(tileSheetTexture);
            //renderiza os 10 primeiros tiles da imagem
            sprites[i].setTextureRect(sf::IntRect(i * tileWidth, 0 * tileHeight, tileWidth, tileHeight));
            sprites[i].setPosition(sf::Vector2f(100 + i * tileWidth, 100));    
        }


    } else {
        std::cout << "Failed to load City tilesheet in assets" << std::endl;
    }
}

void Map::Update(float deltaTime)
{

}

void Map::Draw(sf::RenderWindow& window)
{
    for (size_t i = 0; i < 10; i++)
        window.draw(sprites[i]);
}