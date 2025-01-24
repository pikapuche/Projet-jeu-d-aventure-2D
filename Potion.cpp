#include "Potion.hpp"

Potion::Potion(string n, int x, int y) : Objects(n, x, y) {}

Potion::~Potion() {}

void Potion::initPotion() {

	if (!potionTexture.loadFromFile("Assets/potion2.png"))
	{
		cout << "Big error wtf potionTexture not working omg" << endl << endl;
	}
	potionTexture.setSmooth(true);
	potionSprite.setTexture(potionTexture);
}

void Potion::glouglou(Player& player, sf::Sprite& playerSprite) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::E) && potionCount >= 1) {
		takePotion = true;
		player.giveSpeed(3.0f);
		potionCount--;
		cout << "glouglou la popo" << endl << endl;
		tempsPotion.restart();
	}
}

void Potion::stopGlouglou(Player& player, sf::Sprite& playerSprite) {
	if (tempsPotion.getElapsedTime().asSeconds() >= finDuChrono && takePotion) { 
		player.lessSpeed(3.0f);
		cout << "vitesse normal rip la glouglou" << endl << endl;
		takePotion = false;
	}
}

void Potion::interact(Player& player) {
	if (player.playerSprite.getGlobalBounds().intersects(potionSprite.getGlobalBounds()) && sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		potionCount++;
		cout << nom << "+ 1" << endl << endl;
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