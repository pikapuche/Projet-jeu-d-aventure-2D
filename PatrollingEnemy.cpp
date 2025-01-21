#include "PatrollingEnemy.hpp"

PatrollingEnemy::PatrollingEnemy(string n, int x, int y, float sd, int dG, int h) : Enemy(n, x, y, sd, dG, h) {}

PatrollingEnemy::~PatrollingEnemy() {}

void PatrollingEnemy::initPatrollingEnemy() {

	turn = false;

	if (!patrollTexture.loadFromFile("C:\\Users\\quent\\OneDrive\\Pictures\\C++\\TileSheets projet\\Aventure 2D\\Carré_vert.jpg"))
	{
		cout << "Big error wtf patrollTexture not working omg" << endl << endl;
	}
	patrollTexture.setSmooth(true);
	patrollSprite.setTexture(patrollTexture);

	if (!xPointTexture.loadFromFile("C:\\Users\\quent\\OneDrive\\Pictures\\C++\\TileSheets projet\\Aventure 2D\\Carré Violet.png"))
	{
		cout << "Big error wtf xPointTexture not working omg" << endl << endl;
	}
	xPointTexture.setSmooth(true);
	xPointSprite.setTexture(xPointTexture);

	if (!yPointTexture.loadFromFile("C:\\Users\\quent\\OneDrive\\Pictures\\C++\\TileSheets projet\\Aventure 2D\\Carré Violet.png"))
	{
		cout << "Big error wtf yPointTexture not working omg" << endl << endl;
	}
	yPointTexture.setSmooth(true);
	yPointSprite.setTexture(yPointTexture);

	xPointSprite.setPosition(600, E_y * E_speed);
	yPointSprite.setPosition(E_x, E_y * E_speed);
}

void PatrollingEnemy::patrolPatern() {
	if (yPointSprite.getGlobalBounds().intersects(patrollSprite.getGlobalBounds())) {
		turn = false;
	}
	else if (xPointSprite.getGlobalBounds().intersects(patrollSprite.getGlobalBounds())) {
		turn = true;
	}

}

void PatrollingEnemy::catchPlayer(sf::Sprite player) {
	if (patrollSprite.getGlobalBounds().intersects(player.getGlobalBounds())) {
		player.setColor(sf::Color::Transparent);
		cout << "Game Over";
	}
}

void PatrollingEnemy::moving(int coordX) {
	if(turn == true) {
		E_x--;
	}
	else {
		E_x++;
	}
}

void PatrollingEnemy::update(float deltaTime) {
	patrollSprite.setPosition(E_x * E_speed, E_y * E_speed);
}

void PatrollingEnemy::draw(sf::RenderWindow& window) {
	window.draw(patrollSprite);

	window.draw(xPointSprite);
	window.draw(yPointSprite);
}