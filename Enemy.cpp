#include "Enemy.h"

Enemy::Enemy(const GameObject::RectDesc& desc, int health) : GameObject(desc), health(health)
{
    // Initialisation supplémentaire si nécessaire
}

void Enemy::receiveDamage(int damage)
{
    this->health -= damage; 
}

bool Enemy::die()
{
	bool isDead = false;
    if (health <= 0) {
		isDead = true;
	}
	return isDead;
}
