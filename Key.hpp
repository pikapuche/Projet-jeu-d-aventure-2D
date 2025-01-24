#pragma once
#include "Objects.hpp"

class Key : public Objects {
protected : 
	bool keyDepop = false;
public : 

	sf::Texture keyTexture;
	sf::Sprite keySprite;
	int keyCount = 0;


	Key(string n, int x, int y);

	~Key();

	void initKey();

	bool getDepop();

	void interact(Player& player) override;

	void update(float deltaTime) override;

	void draw(sf::RenderWindow& window) override;
};