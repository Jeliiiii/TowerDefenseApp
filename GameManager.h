#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <windows.h>

using namespace sf;
using namespace std;

const int WIN_WIDTH = 1280;
const int WIN_HEIGHT = 720;

class GameManager {

public:
	GameManager();
	void InputHandler(Event event, RenderWindow& window);

private:

};