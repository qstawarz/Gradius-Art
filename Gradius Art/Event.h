//
// Created by Quentin on 11/9/2017.
//

#ifndef GRADIUS_EVENT_H
#define GRADIUS_EVENT_H

#include <SFML/Graphics.hpp>

class Event
{
private:
    sf::Vector2f m_dir;

    bool m_isSpace;

protected:

public:
    Event();
    ~Event();

    sf::Vector2f &getDir();

    void checkInput(sf::RenderWindow &p_window);

    bool isSpace();

};

#endif //GRADIUS_EVENT_H