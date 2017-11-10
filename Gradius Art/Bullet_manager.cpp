//
// Created by Quentin on 11/9/2017.
//

#include <iostream>

#include "Bullet_manager.h"

Bullet_manager::Bullet_manager() : m_bulletList {}
{

}

Bullet_manager::~Bullet_manager()
{
    std::cout << "Bullet_manager destroyed" << std::endl;
}

std::vector<Bullet *> &Bullet_manager::getBulletList()
{
    return this->m_bulletList;
}

void Bullet_manager::Draw(sf::RenderWindow &p_window)
{
    for (auto it : this->m_bulletList)
        it->Draw(p_window);
}

void Bullet_manager::Update(float p_elapsedTime)
{
    for (auto it : this->m_bulletList)
        it->Update(p_elapsedTime);
}

void Bullet_manager::addBullet(Bullet *p_bullet)
{
    if (p_bullet == nullptr) return;

    this->m_bulletList.push_back(p_bullet);
}

void Bullet_manager::removeBullet(Bullet *p_bullet)
{
    if (p_bullet == nullptr) return;

    for (int i = 0; i < this->m_bulletList.size(); ++i)
    {
        if (this->m_bulletList[i] == p_bullet)
            this->m_bulletList.erase(this->m_bulletList.begin() + i);
    }
}