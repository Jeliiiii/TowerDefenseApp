#include "Tower.h"

<<<<<<< Updated upstream
=======
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


sf::Vector2f Tower::getPosition() const {
	return zoneDamage->getPosition();
}

int Tower::GetDamage() const {
	return damage;
}

bool Tower::IsEnemyInAttackRange(sf::Drawable& enemy) {
	// Essayez de convertir enemy en sf::Shape
	sf::Shape* shapeEnemy = dynamic_cast<sf::Shape*>(&enemy);

	if (shapeEnemy) {
		// Vérifiez si l'ennemi est dans la zone d'attaque de la tour
		if (zoneDamage->getGlobalBounds().intersects(shapeEnemy->getGlobalBounds())) {
			return true;
		}
	}

	return false;
}




>>>>>>> Stashed changes
