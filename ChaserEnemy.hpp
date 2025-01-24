#pragma once 
#include "Enemy.hpp"

class ChaserEnemy : public Enemy {
protected : 
	bool turn = false;
	bool kill = false;
	bool end = false;

public:

	sf::Texture chaserTexture;
	sf::Sprite chaserSprite;

	ChaserEnemy(string n, int x, int y, float sd);

	~ChaserEnemy();

	void initChaserEnemy();

	void chasePatern(sf::Sprite& player);
	void catchPlayer(sf::Sprite& player, sf::RenderWindow& window);

	void update(float deltaTime) override;
	void draw(sf::RenderWindow& window) override;
};