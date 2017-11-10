//
// Created by Quentin on 11/9/2017.
//

#include <iostream>
#include <cmath>

#include "Bullet.h"

Bullet::Bullet(float x, float y) : m_speed {300.0f}, m_scale {5.0f}
{
    this->loadSprite("../bullet.png");
    this->m_sprite.setPosition(sf::Vector2f(x, y - 45));
    this->m_sprite.scale(sf::Vector2f(1.0f / 10.0f, 1.0f / 10.0f));
}

Bullet::~Bullet()
{
    std::cout << "Bullet destroyed" << std::endl;
}

void Bullet::loadSprite(const std::string &p_filename)
{
    this->m_texture.loadFromFile(p_filename);
    this->m_sprite.setTexture(this->m_texture);
}

sf::Sprite &Bullet::getSprite()
{
    return this->m_sprite;
}

float Bullet::getSpeed()
{
    return this->m_speed;
}

void Bullet::Draw(sf::RenderWindow &p_window)
{
    p_window.draw(this->m_sprite);
}

void Bullet::Update(float p_elapsedTime)
{
    static float x = 0.0f;
    float y;

    y = -this->m_scale * std::sin((x - 720) + 360);
    x -= 0.1f;
    this->m_sprite.move(-this->m_speed * p_elapsedTime, y);
}