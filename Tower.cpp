#include "Tower.h"

Tower::Tower(const GameObject::CircleDesc desc, int damage, int damageZone) : GameObject(desc)
{
	this->damage = damage;
	this->damageZone = damageZone;

	zoneDamage = new sf::CircleShape(damageZone);
	zoneDamage->setOrigin(damageZone, damageZone); // Centre le cercle
	zoneDamage->setPosition(origineX, origineY); // Positionne le cercle sur la tour
	zoneDamage->setFillColor(sf::Color(255, 0, 0, 100)); // Couleur rouge avec transparence

}

Tower::~Tower()
{
}

sf::Shape* Tower::GetZoneDamage()
{
	return zoneDamage;
}