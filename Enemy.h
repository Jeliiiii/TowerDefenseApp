#pragma once
#include "GameObject.h"
#include "Map.h"

class Enemy : public GameObject
{
private:
    int health;
    sf::Vector2i prev_point;

public:
    // Constructeur utilisant GameObject::RectDesc
    Enemy(const GameObject::RectDesc& desc, int health);

    // M�thode pour recevoir des d�g�ts
    void receiveDamage(int damage);
    bool die();

    sf::Vector2f getPosition() const;
    void setPosition(float x, float y);

    void moveAlongPath(const Map& map);
};

