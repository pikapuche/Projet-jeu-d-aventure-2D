#include <iostream>
#include "SFML/Graphics.hpp"

using namespace std;

class Entity {
protected : 

public : 

	virtual void update(float deltaTime) = 0;
	virtual void draw(sf::RenderWindow& window) = 0;

};
