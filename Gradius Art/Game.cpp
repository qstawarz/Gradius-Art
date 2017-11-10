//
// Created by Quentin on 11/9/2017.
//
#include <iostream>

#include "Game.h"

Game::Game() : m_elapsedTime {0}, m_lastTime {0}
{

}

Game::~Game()
{
    std::cout << "Game destroyed" << std::endl;
}

void Game::Setup()
{
  this->m_display.Setup();
}

void Game::Update(float p_elapsedTime)
{
    this->m_event.checkInput(this->m_display.getWindow());

    this->m_player.Update(this->m_event.getDir(), p_elapsedTime);
    this->m_player.shoot(this->m_event);

    this->m_enemyManager.Update(p_elapsedTime);

    this->m_enemyManager.addEnemy(new Enemy(360));

    this->m_bulletManager.Update(p_elapsedTime);
}

void Game::Draw()
{
    this->m_display.getWindow().clear();

    this->m_player.Draw(this->m_display.getWindow());

    this->m_enemyManager.Draw(this->m_display.getWindow());

    this->m_bulletManager.Draw(this->m_display.getWindow());

    this->m_display.getWindow().display();
}

void Game::Run()
{
    while (this->m_display.getWindow().isOpen())
    {
        this->Update(this->m_elapsedTime);

        this->Draw();

        this->m_elapsedTime = this->m_clock.getElapsedTime().asSeconds();
        this->m_clock.restart();
    }
}