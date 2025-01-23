#include "Enemy.hpp"

class PatrollingEnemy : public Enemy {
protected : 
	bool turn = false;

	sf::Texture xPointTexture;
	sf::Sprite xPointSprite;

	sf::Texture yPointTexture;
	sf::Sprite yPointSprite;
public : 

	sf::Texture patrollTexture;
	sf::Sprite patrollSprite;

	PatrollingEnemy(string n, int x, int y, float sd, int dG, int h);

	~PatrollingEnemy();

	void initPatrollingEnemy();

	void patrolPatern();
	void catchPlayer(sf::Sprite& player);
	void moving(int coordX);

	void update(float deltaTime) override;
	void draw(sf::RenderWindow& window) override;
};