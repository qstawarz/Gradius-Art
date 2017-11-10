//
// Created by Quentin on 11/9/2017.
//

#ifndef GRADIUS_BULLET_H
#define GRADIUS_BULLET_H

#include <SFML/Graphics.hpp>

#include "Event.h"

class Bullet
{
private:
    sf::Texture m_texture;
    sf::Sprite m_sprite;

    float m_speed;
    float m_scale;

protected:

public:
    Bullet(float x, float y);
    ~Bullet();

    sf::Sprite &getSprite();
    float getSpeed();

    void loadSprite(const std::string &p_filename);
    void Draw(sf::RenderWindow &p_window);

    void Update(float p_elapsedTime);


};

#endif //GRADIUS_BULLET_H