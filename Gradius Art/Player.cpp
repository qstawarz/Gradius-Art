//
// Created by Quentin on 11/9/2017.
//
#include <iostream>

#include "Player.h"

Player::Player() : m_speed {500.0f}
{
    this->loadSprite("../player.png");
    this->m_sprite.setPosition(sf::Vector2f(0.0f, 720 / 2 - this->m_texture.getSize().y / 2));
    this->m_sprite.scale(sf::Vector2f(1.0f / 2.0f, 1.0f / 2.0f));
}

Player::~Player()
{
    std::cout << "Player destroyed" << std::endl;
}

sf::Sprite &Player::getSprite()
{
    return this->m_sprite;
}

sf::Texture &Player::getTexture()
{
    return this->m_texture;
}

void Player::loadSprite(const std::string &p_filename)
{
    this->m_texture.loadFromFile(p_filename);
    this->m_sprite.setTexture(this->m_texture);
}

void Player::Draw(sf::RenderWindow &p_window)
{
    p_window.draw(this->m_sprite);
}

void Player::Update(sf::Vector2f &dir, float p_elapsedTime)
{
    if (this->m_sprite.getPosition().x <= 0)
        this->m_sprite.move(1.0f, 0.0f);

    if (this->m_sprite.getPosition().x >= 1080 - this->m_texture.getSize().y / 2)
        this->m_sprite.move(-1.0f, 0.0f);

    if (this->m_sprite.getPosition().y <= 0)
        this->m_sprite.move(0.0f, 1.0f);

    if (this->m_sprite.getPosition().y >= 720 - this->m_texture.getSize().y / 2)
        this->m_sprite.move(0.0f, -1.0f);

    if (this->m_sprite.getPosition().x > 0 && this->m_sprite.getPosition().x < 1080 - this->m_texture.getSize().x / 2 &&
        this->m_sprite.getPosition().y > 0 && this->m_sprite.getPosition().y < 720 - this->m_texture.getSize().y / 2)
        this->m_sprite.move(dir.x * this->m_speed * p_elapsedTime, dir.y * this->m_speed * p_elapsedTime);
}

void Player::shoot(Event &p_event)
{
    if (p_event.isSpace())
    {
//        m_bulletManager.addBullet(new Bullet(this->m_sprite.getPosition().x + this->m_texture.getSize().x / 2,
//                                             this->m_sprite.getPosition().y + this->m_texture.getSize().y / 2));

    }
}