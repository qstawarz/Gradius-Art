//
// Created by Quentin on 11/9/2017.
//

#include <iostream>
#include <cmath>

#include "Enemy.h"

Enemy::Enemy(float offset) : m_speed {300.0f}, m_scale {5.0f}, m_offset {offset}
{
    this->loadSprite("../enemy.png");
    this->m_sprite.setPosition(sf::Vector2f(1080 - this->m_texture.getSize().x / 2, offset - this->m_texture.getSize().y / 2));
    this->m_sprite.scale(sf::Vector2f(1.0f / 2.0f, 1.0f / 2.0f));
}

Enemy::~Enemy()
{
    std::cout << "Enemy destroyed" << std::endl;
}

sf::Sprite &Enemy::getSprite()
{
    return this->m_sprite;
}

sf::Texture &Enemy::getTexture()
{
    return this->m_texture;
}

void Enemy::loadSprite(const std::string &p_filename)
{
    this->m_texture.loadFromFile(p_filename);
    this->m_sprite.setTexture(this->m_texture);
}

void Enemy::Draw(sf::RenderWindow &p_window)
{
    p_window.draw(this->m_sprite);
}

void Enemy::Update(float p_elapsedTime)
{
    if (this->m_sprite.getPosition().x <= 0)
        this->m_sprite.setPosition(sf::Vector2f(1080 - this->m_texture.getSize().x / 2, this->m_sprite.getPosition().y));

    static float x = 0.0f;
    float y;

    y = -this->m_scale * std::sin((x - this->m_offset * 2) + this->m_offset);
    x -= 0.1f;
    this->m_sprite.move(-this->m_speed * p_elapsedTime, y);
}
