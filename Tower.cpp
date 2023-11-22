#include "Tower.h"

Tower::Tower() {
    // Default constructor, set some default properties
    shape.setSize(sf::Vector2f(50.0f, 50.0f));
    shape.setFillColor(sf::Color::Red);
    shape.setOutlineColor(sf::Color::Black);
    shape.setOutlineThickness(2.0f);
}

Tower::Tower(sf::Vector2f position) : Tower() {
    // Constructor with position, calls the default constructor and then sets the position
    shape.setPosition(position);
}

Tower::~Tower() {
    // Destructor
}

void Tower::setPosition(sf::Vector2f position) {
    shape.setPosition(position);
}

void Tower::draw(sf::RenderWindow& window) {
    window.draw(shape);
}
