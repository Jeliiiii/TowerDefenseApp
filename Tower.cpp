#include "Tower.h"

Tower::Tower(const GameObject::CircleDesc desc, int damage, int damageZone) : GameObject(desc)
{
	this->damage = damage;
	this->damageZone = damageZone;

}

Tower::~Tower()
{
}

void Tower::setDamageZone() {
	damageZoneShape.setRadius(damageZone);
	damageZoneShape.setOrigin(damageZone, damageZone); // Centre le cercle
	damageZoneShape.setPosition(origineX, origineY); // Positionne le cercle sur la tour
	damageZoneShape.setFillColor(sf::Color(255, 0, 0, 100)); // Couleur rouge avec transparence
}