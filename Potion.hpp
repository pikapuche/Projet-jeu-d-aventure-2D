#pragma once
#include "Objects.hpp"
#include <chrono>

class Potion : public Objects {
protected : 
	int potionCount = 0;
	sf::Texture potionTexture;
	sf::Sprite potionSprite;
	bool potionDepop = false;
	bool takePotion = false;

	sf::Clock tempsPotion;

public : 

	Potion(string n, int x, int y);

	~Potion();

	void initPotion();

	void interact(Player& player) override;

	bool getDepop();

	bool setDepop();

	void glouglou(Player& player);

	void stopGlouglou(Player& player);

	void update(float deltaTime) override;

	void draw(sf::RenderWindow& window) override;
};