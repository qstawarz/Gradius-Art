//
// Created by Quentin on 11/9/2017.
//

#ifndef GRADIUS_BULLET_MANAGER_H
#define GRADIUS_BULLET_MANAGER_H

#include <vector>

#include "Bullet.h"

class Bullet_manager
{
private:
    std::vector<Bullet*> m_bulletList;

protected:

public:
    Bullet_manager();
    ~Bullet_manager();

    std::vector<Bullet*> &getBulletList();

    void Draw(sf::RenderWindow &p_window);
    void Update(float p_elapsedTime);

    void addBullet(Bullet *p_bullet);
    void removeBullet(Bullet *p_bullet);

};

#endif //GRADIUS_BULLET_MANAGER_H