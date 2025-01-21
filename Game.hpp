#include <iostream>
#include <chrono>
#include "SFML/Graphics.hpp"
#include "PatrollingEnemy.hpp"
#include "ChaserEnemy.hpp"
#include "Potion.hpp"
#include "Key.hpp"

class Game {
public : 
	vector<Player> vector_player;

	vector<PatrollingEnemy> vector_patroll;
	vector<ChaserEnemy> vector_chaser;

	vector<Potion> vector_potion;
	vector<Key> vector_key;

	void inGame();
};