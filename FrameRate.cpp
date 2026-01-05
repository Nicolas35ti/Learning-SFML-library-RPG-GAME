#include "FrameRate.h"
#include <iostream>

void FrameRate::Initialize()
{
}

void FrameRate::Load()
{
    if (font.loadFromFile("assets/fonts/Minecraft.ttf")) {
        std::cout << "Minecraft.ttf fonte carregou corretamente!" << std::endl;
        //adiciona uma fonte ao texto
        frameRateText.setFont(font);
    } else {
        std::cout << "Falha ao carregar Minecraft.ttf fonte." << std::endl;
    }
    
}

void FrameRate::Update(float deltaTime)
{
    //diz o que vai dizer o texto
    float fps = 1000.0f / deltaTime;

    frameRateText.setString("FPS: " + std::to_string((int)fps) + " | frameTime: " + std::to_string(deltaTime));
}

void FrameRate::Draw(sf::RenderWindow &window)
{
    window.draw(frameRateText);
}
