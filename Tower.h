#pragma once
<<<<<<< Updated upstream
=======
#include "GameObject.h"
class Tower : public GameObject
{
private:
	int damage;
	int damageZone;

	sf::Shape* zoneDamage;

>>>>>>> Stashed changes

#include <SFML/Graphics.hpp>

<<<<<<< Updated upstream
class Tower {

};
=======
	sf::Shape* GetZoneDamage();

	sf::Vector2f getPosition() const;

	int GetDamage() const;

	bool IsEnemyInAttackRange(sf::Drawable& enemy);
};
>>>>>>> Stashed changes
