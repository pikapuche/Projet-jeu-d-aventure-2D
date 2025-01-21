#include "Key.hpp"

Key::Key(string n, int x, int y) : Objects(n, x, y) {}

Key::~Key() {}

void Key::initKey() {

	if (!keyTexture.loadFromFile("C:\\Users\\quent\\OneDrive\\Pictures\\C++\\TileSheets projet\\Aventure 2D\\La c'est les vrais assets\\Key 2D2.png"))
	{
		cout << "Big error wtf keyTexture not working omg" << endl << endl;
	}
	keyTexture.setSmooth(true);
	keySprite.setTexture(keyTexture);
}

void Key::useKey() {
	// ouvre une porte ? / coffre 
}

void Key::interact(Player& player) {
	if (player.playerSprite.getGlobalBounds().intersects(keySprite.getGlobalBounds())) {
		keyCount++;
		cout << nom << "+1" << endl << endl;
		keyDepop = true;
	}
}

bool Key::getDepop() {
	return keyDepop;
}

void Key::update(float deltaTime) {
	keySprite.setPosition(x, y);
	// animations ?
}

void Key::draw(sf::RenderWindow& window) {
	window.draw(keySprite);
}