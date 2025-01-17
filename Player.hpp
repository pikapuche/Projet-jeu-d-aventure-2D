#include "Entity.hpp"

using namespace std;

class Player : public Entity {
protected : 
	string P_nom;
	int P_x, P_y;
	float P_speed;
	int P_damage = 0;
	int P_health = 0;
	sf::Texture playerTexture;
	sf::Sprite playerSprite;

public : 

	Player(string n, int x, int y, float sd, int dg, int h);

	~Player();

	void initPlayer();
	void keyboardManager();

	int getX() {
		return P_x;
	}

	int getY() {
		return P_y;
	}

	void update(float deltaTime) override ;
	void draw(sf::RenderWindow& window) override;

};