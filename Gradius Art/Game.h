//
// Created by Quentin on 11/9/2017.
//

#ifndef GRADIUS_GAME_H
#define GRADIUS_GAME_H

#include "Display.h"
#include "Event.h"
#include "Player.h"
#include "Enemy.h"
#include "Bullet_manager.h"
#include "Enemy_manager.h"

class Game
{
private:
    Display m_display;
    Event m_event;
    Player m_player;
    Enemy_manager m_enemyManager;
    Bullet_manager m_bulletManager;

    sf::Clock m_clock;
    float m_elapsedTime;
    float m_lastTime;

protected:

public:
    Game();
    ~Game();

    void Setup();
    void Update(float p_elapsedTime);
    void Draw();
    void Run();

};

#endif //GRADIUS_GAME_H