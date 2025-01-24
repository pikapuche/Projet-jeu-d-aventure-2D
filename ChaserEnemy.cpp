#include "ChaserEnemy.hpp"
#include <Windows.h>
#include <thread>

ChaserEnemy::ChaserEnemy(string n, int x, int y, float sd) : Enemy(n, x, y, sd) {}

ChaserEnemy::~ChaserEnemy() {}

void ChaserEnemy::initChaserEnemy() {
	if (!chaserTexture.loadFromFile("Assets/Carré_bleu.jpg"))
	{
		cout << "Big error wtf chaserTexture not working omg" << endl << endl;
	}
	chaserTexture.setSmooth(true);
	chaserSprite.setTexture(chaserTexture);

	chaserSprite.setPosition(500, 500);

	if (!font.loadFromFile("Assets/Minecraft.ttf"))
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
		cout << "VOUS ETES MORT BOUUUUUUUUUUUUUUUU" << endl << endl;
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
		this_thread::sleep_for(std::chrono::seconds(3));
		window.close();
	}

}
