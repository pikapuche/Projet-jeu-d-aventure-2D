#include "Enemy.hpp"

class ChaserEnemy : public Enemy {
protected : 
	bool turn = false;

public:

	sf::Texture chaserTexture;
	sf::Sprite chaserSprite;

	ChaserEnemy(string n, int x, int y, float sd, int dG, int h);

	~ChaserEnemy();

	void initChaserEnemy();

	void chasePatern(sf::Sprite& player);
	void catchPlayer(sf::Sprite& player);

	void update(float deltaTime) override;
	void draw(sf::RenderWindow& window) override;
};