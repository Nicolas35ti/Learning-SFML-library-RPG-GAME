#include "Bullet.h"
#include "Math.h"

Bullet::Bullet() : m_speed(0)
{
}

Bullet::~Bullet()
{
}

void Bullet::Initialize(const sf::Vector2f& posiiton, const sf::Vector2f& target, float speed)
{
    //seerve basicamnete para que a velocidade seja um atributo da classe e possa ser usado por diferentes funçoes
    //a flecha serve para se referir a speed da classe
    m_speed = speed;
    rectangleShape.setSize(sf::Vector2f(50, 25));
    rectangleShape.setPosition(posiiton);
    direction = Math::NormalizeVector(target - posiiton);
}


void Bullet::Update(float deltaTime)
{
    //todo frame move a bala nessa posicao escpecifica, nessa velocidade especidfica no deltatime
    rectangleShape.setPosition(rectangleShape.getPosition() + direction * m_speed * deltaTime);
}

void Bullet::Draw(sf::RenderWindow &window)
{
    window.draw(rectangleShape);
}
