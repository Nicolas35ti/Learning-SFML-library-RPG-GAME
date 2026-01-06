#include "FrameRate.h"
#include <iostream>

//quando iniciar o coinsttutor, setar a minha variavek timer para o valor 0
FrameRate::FrameRate() : timer(0){
}

FrameRate::~FrameRate(){

}

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

void FrameRate::Update(double deltaTime)
{
    timer += deltaTime;

    //faz com que a leiturta do fps e do frametime ocorrra a cada 0,1 segudnos, deiuxando mais legivel e ai reseta o timer
    if (timer >= 100.0) {
        //diz o que vai dizer o texto
        double fps = 1000.0 / deltaTime;

        frameRateText.setString("FPS: " + std::to_string((int)fps) + " | frameTime: " + std::to_string((int)(deltaTime)));
        timer = 0;
    }
}

void FrameRate::Draw(sf::RenderWindow &window)
{
    window.draw(frameRateText);
}
