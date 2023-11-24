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
    cout << map.isValidCell(currentX, currentY + 1) << " ||| " << map.map[currentX][currentY + 1] << endl;
    cout << "(" << currentX << ", " << currentY << ")" << endl;
    cout << "(" << prev_point.x << ", " << prev_point.y << ")" << endl;
    if (map.isValidCell(currentX, currentY + 1) && map.map[currentX][currentY + 1] == 1 && currentY + 1 != prev_point.y) {
        // Déplacez l'ennemi vers le bas
        setPosition(getPosition().x, getPosition().y + map.getCellSize());
        prev_point = sf::Vector2i(currentX, currentY);
    }
    else if (map.isValidCell(currentX, currentY - 1) && map.map[currentX][currentY - 1] == 1 && currentY - 1 != prev_point.y) {
        // Déplacez l'ennemi vers le haut
        setPosition(getPosition().x, getPosition().y - map.getCellSize());
        prev_point = sf::Vector2i(currentX, currentY);
    }
    else if (map.isValidCell(currentX + 1, currentY) && map.map[currentX + 1][currentY] == 1 && currentX + 1 != prev_point.x) {
        // Déplacez l'ennemi vers le right
        setPosition(getPosition().x + map.getCellSize(), getPosition().y);
        prev_point = sf::Vector2i(currentX, currentY);
    }
    else if (map.isValidCell(currentX - 1, currentY) && map.map[currentX - 1][currentY] == 1 && currentX - 1 != prev_point.x) {
        // Déplacez l'ennemi vers le left
        setPosition(getPosition().x - map.getCellSize(), getPosition().y);
        prev_point = sf::Vector2i(currentX, currentY);
    }
    // Ajoutez des conditions similaires pour les autres directions
}