//
// Created by Quentin on 11/9/2017.
//

#include <iostream>

#include "Display.h"

Display::Display() : m_window {sf::VideoMode(this->m_windowW, this->m_windowH), "Gradius"}
{

}

Display::~Display()
{
    std::cout << "Display destroyed" << std::endl;
}

sf::RenderWindow &Display::getWindow()
{
    return this->m_window;
}

void Display::Setup()
{
    this->m_window.setVerticalSyncEnabled(true);
    this->m_window.setFramerateLimit(60);
}
