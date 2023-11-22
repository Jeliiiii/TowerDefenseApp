#pragma once
#include "GameObject.h"
class Tower : public GameObject
{
private:
	int damage;
	int damageZone;
	sf::CircleShape damageZoneShape;
	

public:
	Tower(const GameObject::CircleDesc desc, int damage, int damageZone);
	~Tower();

	void setDamageZone();
};

