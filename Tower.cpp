#include "Tower.h"

Tower::Tower(const sf::Vector2f& position) {
    shape.setSize(sf::Vector2f(80, 80)); // Set the size of the tower
    shape.setPosition(position);
    shape.setFillColor(sf::Color::Magenta); // Set the initial fill color
}

Tower::~Tower()
{

}

void Tower::draw(sf::RenderWindow& window) const {
    window.draw(shape);
}
