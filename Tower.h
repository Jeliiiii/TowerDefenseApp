#pragma once
#include "GameObject.h"
class Tower : public GameObject
{
private:
	int damage;
	int damageZone;
	
	sf::Shape* zoneDamage;
	

public:
	Tower(const GameObject::CircleDesc desc, int damage, int damageZone);
	~Tower();

	sf::Shape* GetZoneDamage();
};

