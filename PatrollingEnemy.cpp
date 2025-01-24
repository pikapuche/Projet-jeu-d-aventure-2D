#include "PatrollingEnemy.hpp"
#include <Windows.h>

PatrollingEnemy::PatrollingEnemy(string n, int x, int y, float sd) : Enemy(n, x, y, sd) {}

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

	xPointSprite.setPosition(900, E_y * E_speed);
	yPointSprite.setPosition(E_x, E_y * E_speed);

	if (!font.loadFromFile("C:\\Users\\quent\\OneDrive\\Pictures\\Font\\minecraft\\Minecraft.ttf"))
	{
		cout << "error font" << endl << endl;
	}
}

void PatrollingEnemy::patrolPatern() {
	if (yPointSprite.getGlobalBounds().intersects(patrollSprite.getGlobalBounds())) {
		turn = false;
	}
	else if (xPointSprite.getGlobalBounds().intersects(patrollSprite.getGlobalBounds())) {
		turn = true;
	}

}

void PatrollingEnemy::catchPlayer(sf::Sprite& player) {
	if (patrollSprite.getGlobalBounds().intersects(player.getGlobalBounds())) {
		player.setColor(sf::Color::Red);
		gameOver.setFont(font);
		gameOver.setString("GAME OVER HAHAHAHA");
		gameOver.setCharacterSize(100);
		gameOver.setPosition(360, 440);
	}
	else {
		player.setColor(sf::Color::White);
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

	if (kill)
	{
		window.draw(gameOver);
		Sleep(3000);
		window.close();
	}
}