#pragma once
#include "Entity.hpp"

using namespace std;

class Player : public Entity {
protected : 
	string P_nom;
	int P_x, P_y;
	float P_speed = 3.0f;
	int P_health = 0;

public : 

	sf::Texture playerTexture;
	sf::Sprite playerSprite;


	Player(string n, int x, int y, float sd);

	~Player();

	void initPlayer();
	void keyboardManager(sf::Sprite& player);

	int getX();

	int setX(int x);

	int setY(int y);

	int getY();

	float getSpeed();

	float lessSpeed(float sd);

	float giveSpeed(float sd);

	void update(float deltaTime) override ;
	void draw(sf::RenderWindow& window) override;

};