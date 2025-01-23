#include "Player.hpp"

Player::Player(string n, int x, int y, float sd, int h) : P_nom(n), P_x(x), P_y(y), P_speed(sd), P_health(h) {}

Player::~Player() {}

void Player::initPlayer() {
    if (!playerTexture.loadFromFile("C:\\Users\\quent\\source\\repos\\Projet jeu d'aventure 2D\\Assets\\Skeleton.png"))
    {
        cout << "Big error wtf playerTexture not working omg" << endl << endl;
    }
    playerTexture.setSmooth(true);

    playerSprite.setTexture(playerTexture);
}

void Player::keyboardManager(sf::Sprite& player) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
    {
        player.move(0, -1 * P_speed);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        player.move(0, 1 * P_speed);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        player.move(1 * P_speed, 0);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
    {
        player.move(-1 * P_speed, 0);
    }
}

void Player::update(float deltaTime) {
    getSpeed();
    keyboardManager(playerSprite);
}

void Player::draw(sf::RenderWindow& window) {
    window.draw(playerSprite);
}

int Player::getX() {
    return P_x;
}

int Player::getY() {
    return P_y;
}

float Player::lessSpeed(float sd) {
    P_speed = P_speed - sd;
    return P_speed;
}

float Player::giveSpeed(float sd) {
    P_speed = P_speed + sd;
    return P_speed;
}

float Player::getSpeed() {
    return P_speed;
}
