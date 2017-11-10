//
// Created by Quentin on 11/9/2017.
//

#ifndef GRADIUS_ENEMY_H
#define GRADIUS_ENEMY_H

#include <SFML/Graphics.hpp>

class Enemy
{
private:
    sf::Texture m_texture;
    sf::Sprite m_sprite;

    float m_speed;
    float m_scale;
    float m_offset;

protected:

public:
    Enemy(float offset);
    ~Enemy();

    sf::Sprite &getSprite();
    sf::Texture &getTexture();

    void loadSprite(const std::string &p_filename);
    void Draw(sf::RenderWindow &p_window);

    void Update(float p_elapsedTime);

};

#endif //GRADIUS_ENEMY_H