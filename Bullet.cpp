#include "Bullet.h"
#include "Math.h"

Bullet::Bullet() : speed(0)
{
}

Bullet::~Bullet()
{
}

void Bullet::Initialize(const sf::Vector2f& posiiton, sf::Vector2f& target)
{
    rectangleShape.setSize(sf::Vector2f(50, 25));
    rectangleShape.setPosition(posiiton);
    direction = Math::NormalizeVector(target - posiiton);
}


void Bullet::Update(float deltaTime)
{
    //todo frame move a bala nessa posicao escpecifica, nessa velocidade especidfica no deltatime
    rectangleShape.setPosition(rectangleShape.getPosition() + direction * speed * deltaTime);
}

void Bullet::Draw(sf::RenderWindow &window)
{
    window.draw(rectangleShape);
}
