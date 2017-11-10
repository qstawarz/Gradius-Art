//
// Created by Quentin on 11/9/2017.
//

#include <iostream>

#include "Event.h"

Event::Event() : m_dir {0.0f, 0.0f}
{
    this->m_isSpace = false;
}

Event::~Event()
{
    std::cout << "Event destroyed" << std::endl;
}

sf::Vector2f &Event::getDir()
{
    return this->m_dir;
}

void Event::checkInput(sf::RenderWindow &p_window)
{
    sf::Event event;

    while (p_window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            p_window.close();

        if (event.type == sf::Event::KeyPressed)
        {
            if (event.key.code == sf::Keyboard::Right ||
                event.key.code == sf::Keyboard::D)
                this->m_dir.x = 1;

            if (event.key.code == sf::Keyboard::Left ||
                event.key.code == sf::Keyboard::A)
                this->m_dir.x = -1;

            if (event.key.code == sf::Keyboard::Up ||
                event.key.code == sf::Keyboard::W)
                this->m_dir.y = -1;

            if (event.key.code == sf::Keyboard::Down ||
                event.key.code == sf::Keyboard::S)
                this->m_dir.y = 1;

            if (event.key.code == sf::Keyboard::Space)
                this->m_isSpace = true;
        }

        if (event.type == sf::Event::KeyReleased)
        {
            if (event.key.code == sf::Keyboard::Right || event.key.code == sf::Keyboard::D ||
                event.key.code == sf::Keyboard::Left || event.key.code == sf::Keyboard::A)
                this->m_dir.x = 0;

            if (event.key.code == sf::Keyboard::Up || event.key.code == sf::Keyboard::W ||
                event.key.code == sf::Keyboard::Down || event.key.code == sf::Keyboard::S)
                this->m_dir.y = 0;

            if (event.key.code == sf::Keyboard::Space)
                this->m_isSpace = false;
        }

        if (event.key.code == sf::Keyboard::Escape)
            p_window.close();
    }
}

bool Event::isSpace()
{
    return this->m_isSpace;
}