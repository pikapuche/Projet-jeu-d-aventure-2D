#pragma once 
#include "Entity.hpp"

using namespace std;

class Enemy : public Entity {
protected :
	string E_nom;
	int E_x, E_y;
	float E_speed;
	int E_damage = 0;
	int E_health = 0;
	sf::Texture enemyTexture;
	sf::Sprite enemySprite;

	sf::Text gameOver;
	sf::Font font;
public : 

	Enemy(string n, int x, int y, float sd);

	~Enemy();

	void initEnemy();

	void update(float deltaTime) override;
	void draw(sf::RenderWindow& window) override;

};

