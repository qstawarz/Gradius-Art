//
// Created by Quentin on 11/9/2017.
//

#ifndef GRADIUS_DISPLAY_H
#define GRADIUS_DISPLAY_H

#include <SFML/Graphics.hpp>

class Display
{
    typedef float(*curveFunc)(const float&);

private:
    sf::RenderWindow m_window;
    static const unsigned m_windowW = 1080;
    static const unsigned m_windowH = 720;

protected:

public:
    Display();
    ~Display();

    sf::RenderWindow &getWindow();

    void Setup();

};

#endif //GRADIUS_DISPLAY_H