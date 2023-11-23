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

void Enemy::setPosition(float x, float y) {
    // Assurez-vous que 'graphic' est le composant graphique de l'ennemi
    graphic->setPosition(x, y);
}

sf::Vector2f Enemy::getPosition() const {
    // Assurez-vous que 'graphic' est le composant graphique de l'ennemi
    return graphic->getPosition();
}

void Enemy::moveAlongPath(const Map& map) {
    // Exemple de logique de déplacement
    // Obtenez la position actuelle de l'ennemi
    int currentX = getPosition().x / map.getCellSize();
    int currentY = getPosition().y / map.getCellSize();

    // Vérifiez les cellules voisines pour trouver la prochaine étape
    // Cette logique doit être adaptée en fonction de la conception de votre jeu
    if (map.isValidCell(currentX, currentY + 1) && map.map[currentX][currentY + 1] == 1) {
        // Déplacez l'ennemi vers le bas
        setPosition(getPosition().x, getPosition().y + map.getCellSize());
    }
    // Ajoutez des conditions similaires pour les autres directions
}
