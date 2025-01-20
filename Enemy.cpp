#include "Enemy.hpp"

Enemy::Enemy(string n, int x, int y, float sd, int dg, int h) : E_nom(n), E_x(x), E_y(y), E_speed(sd), E_damage(dg), E_health(h) {}

Enemy::~Enemy() {}

void Enemy::initEnemy() {

}

void Enemy::update(float deltaTime) {

}

void Enemy::draw(sf::RenderWindow& window) {

}