//
// Created by Quentin on 11/10/2017.
//

#include <iostream>

#include "Enemy_manager.h"

Enemy_manager::Enemy_manager() : m_enemyList {}
{

}

Enemy_manager::~Enemy_manager()
{
    std::cout << "Bullet_manager destroyed" << std::endl;
}

std::vector<Enemy *> &Enemy_manager::getEnemyList()
{
    return this->m_enemyList;
}

void Enemy_manager::Draw(sf::RenderWindow &p_window)
{
    for (auto it : this->m_enemyList)
        it->Draw(p_window);
}

void Enemy_manager::Update(float p_elapsedTime)
{
    for (auto it : this->m_enemyList)
        it->Update(p_elapsedTime);
}

void Enemy_manager::addEnemy(Enemy *p_enemy)
{
    if (p_enemy == nullptr) return;

    this->m_enemyList.push_back(p_enemy);
}

void Enemy_manager::removeEnemy(Enemy *p_enemy)
{
    if (p_enemy == nullptr) return;

    for (int i = 0; i < this->m_enemyList.size(); ++i)
    {
        if (this->m_enemyList[i] == p_enemy)
            this->m_enemyList.erase(this->m_enemyList.begin() + i);
    }
}