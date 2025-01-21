#include "Potion.hpp"

Potion::Potion(string n, int x, int y) : Objects(n, x, y) {}

Potion::~Potion() {}

void Potion::initPotion() {

	if (!potionTexture.loadFromFile("C:\\Users\\quent\\OneDrive\\Pictures\\C++\\TileSheets projet\\Aventure 2D\\La c'est les vrais assets\\potion2.png"))
	{
		cout << "Big error wtf potionTexture not working omg" << endl << endl;
	}
	potionTexture.setSmooth(true);
	potionSprite.setTexture(potionTexture);
}

void Potion::glouglou(Player& player) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::E) && potionCount >= 1) {
		takePotion = true;
		player.giveSpeed(100.0f);
		potionCount--;
	}
}

void Potion::stopGlouglou(Player& player) {
	if (tempsPotion.getElapsedTime().asSeconds() == 5 && takePotion == true) {
		player.giveSpeed(3.0f);
	}
}

void Potion::interact(Player& player) {
	if (player.playerSprite.getGlobalBounds().intersects(potionSprite.getGlobalBounds())) {
		potionCount++;
		cout << nom << "+1" << endl << endl;
		potionDepop = true;
	}
}

bool Potion::getDepop() {
	return potionDepop;
}

bool Potion::setDepop() {
	potionDepop = false;
	return potionDepop;
}

void Potion::update(float deltaTime) {
	potionSprite.setPosition(x, y);
	// animation ?
}

void Potion::draw(sf::RenderWindow& window) {
	window.draw(potionSprite);
}