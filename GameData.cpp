#include "GameData.h"

void GameData::CreateEnemy() {
    GameObject::RectDesc EnemyDesc = { 120, 40, 50, 50, 25, 25, sf::Color::Blue };

    Enemy enemy(EnemyDesc, 10);
    enemies.push_back(enemy);
}

void GameData::CreateTower() {
    GameObject::CircleDesc TowerDesc = { 100, 100, 50, 25, 25, sf::Color::Red };

    Tower tower(TowerDesc, 10, 75);
    towers.push_back(tower);
}

bool GameData::isTowerAtPosition(int gridX, int gridY) const {
    for (const auto& tower : towers) {
        int towerGridX = tower.getPosition().x / gameMap.getCellSize();
        int towerGridY = tower.getPosition().y / gameMap.getCellSize();

        if (towerGridX == gridX && towerGridY == gridY) {
            return true; // Une tour est déjà présente à cette position
        }
    }
    return false;
}

void GameData::CreateTowerAtPosition(float x, float y) {
    int gridX = x / gameMap.getCellSize();
    int gridY = y / gameMap.getCellSize();

    // Vérifiez si la cellule est interactive et s'il n'y a pas déjà une tour
    if (gameMap.isInteractable(gridX, gridY) && !isTowerAtPosition(gridX, gridY)) {
        GameObject::CircleDesc TowerDesc = { x, y, 50, 25, 25, sf::Color::Red };
        Tower tower(TowerDesc, 10, 125);
        towers.push_back(tower);

        // Marquez la cellule comme ayant une tour
        gameMap.map[gridX][gridY] = 2;
    }
}

void GameData::CreateMap(sf::RenderWindow& window) {
    int cellSize = gameMap.getCellSize();

    for (int i = 0; i < gameMap.map.size(); i++) {
        for (int j = 0; j < gameMap.map[i].size(); j++) {
            sf::RectangleShape cell(sf::Vector2f(cellSize, cellSize));
            cell.setPosition(cellSize * i, cellSize * j);

            // Configurez la couleur de la cellule en fonction de son type
            if (gameMap.map[i][j] == 1) {
                cell.setFillColor(sf::Color(175, 100, 0, 255)); // Chemin
            }
            else if (gameMap.map[i][j] == 2) {
                cell.setFillColor(sf::Color::Magenta); // Emplacement de tour
            }
            else if (gameMap.map[i][j] == 3) {
                cell.setFillColor(sf::Color::Blue); // Cellule interactive
            }
            else {
                cell.setFillColor(sf::Color::Green); // Cellule vide
            }

            cell.setOutlineColor(sf::Color::Black);
            cell.setOutlineThickness(1);

            window.draw(cell);
        }
    }
}