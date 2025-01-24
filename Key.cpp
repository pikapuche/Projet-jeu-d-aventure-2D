#include "Key.hpp"

Key::Key(string n, int x, int y) : Objects(n, x, y) {}

Key::~Key() {}

void Key::initKey() {

	if (!keyTexture.loadFromFile("Assets/Key 2D2.png"))
	{
		cout << "Big error wtf keyTexture not working omg" << endl << endl;
	}
	keyTexture.setSmooth(true);
	keySprite.setTexture(keyTexture);
}

void Key::interact(Player& player) {
	if (player.playerSprite.getGlobalBounds().intersects(keySprite.getGlobalBounds()) && sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		keyCount++;
		cout << nom << "+ 1" << endl << endl;
		keyDepop = true;
	}
}

bool Key::getDepop() {
	return keyDepop;
}

void Key::update(float deltaTime) {
	keySprite.setPosition(x, y);
}

void Key::draw(sf::RenderWindow& window) {
	window.draw(keySprite);
}