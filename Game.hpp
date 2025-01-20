#include <iostream>
#include "SFML/Graphics.hpp"
#include "Player.hpp"
#include "PatrollingEnemy.hpp"
#include "ChaserEnemy.hpp"

class Game {
public : 
	vector<Player> vector_player;
	vector<PatrollingEnemy> vector_patroll;
	vector<ChaserEnemy> vector_chaser;

	void inGame();
};