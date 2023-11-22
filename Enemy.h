#pragma once
#include "GameObject.h"

class Enemy : public GameObject
{
private:
    int health;

public:
    // Constructeur utilisant GameObject::RectDesc
    Enemy(const GameObject::RectDesc& desc, int health);

    // Méthode pour recevoir des dégâts
    void receiveDamage(int damage);
    bool die();
    // Éventuellement, d'autres méthodes spécifiques aux ennemis
};

