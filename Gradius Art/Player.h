//
// Created by Quentin on 11/9/2017.
//

#ifndef GRADIUS_PLAYER_H
#define GRADIUS_PLAYER_H

#include <SFML/Graphics.hpp>

#include "Event.h"
#include "Bullet_manager.h"

class Player
{
private:
    sf::Texture m_texture;
    sf::Sprite m_sprite;

    float m_speed;

    Bullet_manager m_bulletManager;

protected:

public:
    Player();
    ~Player();

    sf::Sprite &getSprite();
    sf::Texture &getTexture();

    void loadSprite(const std::string &p_filename);
    void Draw(sf::RenderWindow &p_window);

    void Update(sf::Vector2f &dir, float p_elapsedTime);
    void shoot(Event &p_event);

};

#endif //GRADIUS_PLAYER_H