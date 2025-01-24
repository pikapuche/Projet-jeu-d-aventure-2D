#include "PatrollingEnemy.hpp"
#include <Windows.h>
#include <thread>

PatrollingEnemy::PatrollingEnemy(string n, int x, int y, float sd) : Enemy(n, x, y, sd) {}

PatrollingEnemy::~PatrollingEnemy() {}

void PatrollingEnemy::initPatrollingEnemy() {

	turn = false;

	if (!patrollTexture.loadFromFile("Assets/Carré_vert.jpg"))
	{
		cout << "Big error wtf patrollTexture not working omg" << endl << endl;
	}
	patrollTexture.setSmooth(true);
	patrollSprite.setTexture(patrollTexture);

	if (!xPointTexture.loadFromFile("Assets/Carré Violet.png"))
	{
		cout << "Big error wtf xPointTexture not working omg" << endl << endl;
	}
	xPointTexture.setSmooth(true);
	xPointSprite.setTexture(xPointTexture);

	if (!yPointTexture.loadFromFile("Assets/Carré Violet.png"))
	{
		cout << "Big error wtf yPointTexture not working omg" << endl << endl;
	}
	yPointTexture.setSmooth(true);
	yPointSprite.setTexture(yPointTexture);

	xPointSprite.setPosition(900, E_y * E_speed);
	yPointSprite.setPosition(E_x, E_y * E_speed);

	if (!font.loadFromFile("Assets/Minecraft.ttf"))
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
		cout << "VOUS ETES MORT BOUUUUUUUUUUUUUUUU" << endl << endl;
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
		this_thread::sleep_for(std::chrono::seconds(3));
		window.close();
	}
}