#include "Player.hpp"

Player::Player(string n, int x, int y, float sd, int h) : P_nom(n), P_x(x), P_y(y), P_speed(sd), P_health(h) {}

Player::~Player() {}

void Player::initPlayer() {
    if (!playerTexture.loadFromFile("C:\\Users\\quent\\OneDrive\\Pictures\\C++\\TileSheets projet\\Carré_rouge.svg.png"))
    {
        cout << "Big error wtf playerTexture not working omg" << endl << endl;
    }
    playerTexture.setSmooth(true);

    playerSprite.setTexture(playerTexture);
}

void Player::keyboardManager() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
    {
        P_y--;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        P_y++;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        P_x++;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
    {
        P_x--;
    }
}

void Player::update(float deltaTime) {
    playerSprite.setPosition(P_x, P_y);
}

void Player::draw(sf::RenderWindow& window) {
    window.draw(playerSprite);
}