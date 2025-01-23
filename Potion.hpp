#pragma once
#include "Objects.hpp"
#include <chrono>

class Potion : public Objects {
protected : 
	int potionCount = 0;
	float finDuChrono = 3.0f;
	bool potionDepop = false;
	bool takePotion = false;

	sf::Clock tempsPotion;

public : 

	sf::Texture potionTexture;
	sf::Sprite potionSprite;

	Potion(string n, int x, int y);

	~Potion();

	void initPotion();

	void interact(Player& player) override;

	bool getDepop();

	bool setDepop();

	void glouglou(Player& player, sf::Sprite& playerSprite);

	void stopGlouglou(Player& player, sf::Sprite& playerSprite);

	void update(float deltaTime) override;

	void draw(sf::RenderWindow& window) override;
};