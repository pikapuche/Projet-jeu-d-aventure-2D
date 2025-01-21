#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"

using namespace std;

class Entity {
public : 

	virtual void update(float deltaTime) = 0;
	virtual void draw(sf::RenderWindow& window) = 0;

};
