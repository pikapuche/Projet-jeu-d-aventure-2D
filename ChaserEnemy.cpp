#include "ChaserEnemy.hpp"
#include <Windows.h>

ChaserEnemy::ChaserEnemy(string n, int x, int y, float sd) : Enemy(n, x, y, sd) {}

ChaserEnemy::~ChaserEnemy() {}

void ChaserEnemy::initChaserEnemy() {
	if (!chaserTexture.loadFromFile("C:\\Users\\quent\\OneDrive\\Pictures\\C++\\TileSheets projet\\Aventure 2D\\Carré_bleu.jpg"))
	{
		cout << "Big error wtf chaserTexture not working omg" << endl << endl;
	}
	chaserTexture.setSmooth(true);
	chaserSprite.setTexture(chaserTexture);

	chaserSprite.setPosition(500, 500);

	if (!font.loadFromFile("C:\\Users\\quent\\OneDrive\\Pictures\\Font\\minecraft\\Minecraft.ttf"))
	{
		cout << "error font" << endl << endl;
	}

}

void ChaserEnemy::chasePatern(sf::Sprite& player) {
	if (player.getPosition().x + 32 >= chaserSprite.getPosition().x) {
		E_x++;
	}
	else if (player.getPosition().x - 32 <= chaserSprite.getPosition().x) {
		E_x--;
	}
	if (player.getPosition().y + 32 >= chaserSprite.getPosition().y) {
		E_y++;
	}
	else if (player.getPosition().y - 32 <= chaserSprite.getPosition().y) {
		E_y--;
	}
}

void ChaserEnemy::catchPlayer(sf::Sprite& player) {
	if (chaserSprite.getGlobalBounds().intersects(player.getGlobalBounds())) {
		player.setColor(sf::Color::Green);
		gameOver.setFont(font);
		gameOver.setString("GAME OVER HAHAHAHA");
		gameOver.setCharacterSize(100);
		gameOver.setPosition(360, 440);
		kill = true;
	}
	else {
		player.setColor(sf::Color::White);
	}
}

void ChaserEnemy::update(float deltaTime) {
	chaserSprite.setPosition(E_x * E_speed, E_y * E_speed);
}

void ChaserEnemy::draw(sf::RenderWindow& window) {
	window.draw(chaserSprite);

	if (kill) {
		window.draw(gameOver);
		Sleep(3000);
		window.close();
	}

}
