#pragma once
#include "GameManager.h"
#include <SFML/Graphics.hpp> 
#include <iostream>
#include <vector> 
#include <windows.h>
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif
#define _USE_MATH_DEFINES

using namespace sf;
using namespace std;

class GameObject
{
public:
	GameObject(float x, float y, float w, float h, Color color);
    GameObject(float x, float y, float r, float orientation, float speed, Color color);
    Shape* getShape(); // Fonction pour obtenir la forme du GameObject
    Shape* getHitbox();
    Vector2f getPosition();
    void Move(float deltaTime);
    void setRotationAngle(float angle);
    void VerticalBounce();
    void HorizontalBounce();
    void CheckWindowCollision();
    void setPositionCircle(float x, float y);
    void setPositionRect(float x, float y);

private:
    Shape* pShape; // Pointeur vers la forme graphique (rectangle, cercle ou autre)
    Shape* hitbox; // AABB pour les collisions
    Color color; // Couleur de l'objet
    Vector2f position; // Vecteur de position
    float w; // Largeur
    float h; // Hauteur
    float r; // Rayon (pour les cercles)
    float speed; // Vitesse
    float orientation = 0; // Angle de d�part
    Vector2f direction; // Vecteur de direction
};
