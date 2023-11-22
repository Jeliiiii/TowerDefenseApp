#pragma once
#include "GameObject.h"

class Enemy : public GameObject
{
private:
    int health;

public:
    // Constructeur utilisant GameObject::RectDesc
    Enemy(const GameObject::RectDesc& desc, int health);

    // M�thode pour recevoir des d�g�ts
    void receiveDamage(int damage);
    bool die();
    // �ventuellement, d'autres m�thodes sp�cifiques aux ennemis
};

