#include "Entity.hpp"

using namespace std;

class Player : public Entity {
protected : 
	string P_nom;
	int P_x, P_y;
	float P_speed;
	int P_health = 0;

public : 

	sf::Texture playerTexture;
	sf::Sprite playerSprite;

	Player(string n, int x, int y, float sd, int h);

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