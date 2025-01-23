#pragma once
#include "Objects.hpp"

class Key : public Objects {
protected : 
	int keyCount = 0;
	bool keyDepop = false;
public : 

	sf::Texture keyTexture;
	sf::Sprite keySprite;

	Key(string n, int x, int y);

	~Key();

	void initKey();

	bool getDepop();

	void interact(Player& player) override;

	void useKey();

	void update(float deltaTime) override;

	void draw(sf::RenderWindow& window) override;
};