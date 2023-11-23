#include "GameObject.h"



GameObject::GameObject(RectDesc desc)
{
	this->origineX = desc.origineX;
	this->origineY = desc.origineY;
	this->width = desc.width;
	this->height = desc.height;
	this->ancrageX = desc.ancrageX;
	this->ancrageY = desc.ancrageY;
	
	this->color = desc.color;


	graphic = new sf::RectangleShape(sf::Vector2f(width, height));
	graphic->setOrigin(ancrageX, ancrageY);
	graphic->setPosition(origineX, origineY);
	graphic->setFillColor(color);
	graphic->setOutlineThickness(1);
	graphic->setOutlineColor(sf::Color::Black);

}

GameObject::GameObject(CircleDesc desc) {

	this->origineX = desc.origineX;
	this->origineY = desc.origineY;
	this->width = desc.radius / 2;
	this->height = desc.radius / 2;
	this->ancrageX = desc.ancrageX;
	this->ancrageY = desc.ancrageY;
	this->color = desc.color;

	graphic = new sf::CircleShape(width);
	graphic->setOrigin(ancrageX, ancrageY);
	graphic->setPosition(origineX, origineY);
	graphic->setFillColor(color);
}

GameObject::~GameObject()
{

}

sf::Shape* GameObject::GetRender()
{
	return graphic;
}

sf::Vector2f GameObject::getOrigine() const {
	int X = origineX;
	int Y = origineY;
	return sf::Vector2f(X, Y);
}