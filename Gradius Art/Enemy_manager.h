//
// Created by Quentin on 11/10/2017.
//

#ifndef GRADIUS_ENEMY_MANAGER_H
#define GRADIUS_ENEMY_MANAGER_H

#include <vector>

#include "Enemy.h"
class Enemy_manager
{
private:
    std::vector<Enemy*> m_enemyList;

protected:

public:
    Enemy_manager();
    ~Enemy_manager();

    std::vector<Enemy*> &getEnemyList();

    void Draw(sf::RenderWindow &p_window);
    void Update(float p_elapsedTime);

    void addEnemy(Enemy *p_enemy);
    void removeEnemy(Enemy *p_enemy);

};

#endif //GRADIUS_ENEMY_MANAGER_H