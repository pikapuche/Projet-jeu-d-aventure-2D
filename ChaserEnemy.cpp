#include "ChaserEnemy.hpp"

ChaserEnemy::ChaserEnemy(string n, int x, int y, float sd, int dG, int h) : Enemy(n, x, y, sd, dG, h) {}

ChaserEnemy::~ChaserEnemy() {}

void ChaserEnemy::initChaserEnemy() {
	if (!chaserTexture.loadFromFile("C:\\Users\\quent\\OneDrive\\Pictures\\C++\\TileSheets projet\\Aventure 2D\\Carré_bleu.jpg"))
	{
		cout << "Big error wtf chaserTexture not working omg" << endl << endl;
	}
	chaserTexture.setSmooth(true);
	chaserSprite.setTexture(chaserTexture);

	chaserSprite.setPosition(500, 500);

}

void ChaserEnemy::chasePatern(sf::Sprite& player) {
	if (player.getPosition().x >= chaserSprite.getPosition().x) {
		E_x++;
	}
	else if (player.getPosition().x <= chaserSprite.getPosition().x) {
		E_x--;
	}
	if (player.getPosition().y >= chaserSprite.getPosition().y) {
		E_y++;
	}
	else if (player.getPosition().y <= chaserSprite.getPosition().y) {
		E_y--;
	}
}

void ChaserEnemy::catchPlayer(sf::Sprite& player) {
	if (chaserSprite.getGlobalBounds().intersects(player.getGlobalBounds())) {
		player.setColor(sf::Color::Green);
		//cout << "Game over";
	}
}

void ChaserEnemy::update(float deltaTime) {
	chaserSprite.setPosition(E_x * E_speed, E_y * E_speed);
}

void ChaserEnemy::draw(sf::RenderWindow& window) {
	window.draw(chaserSprite);
}
