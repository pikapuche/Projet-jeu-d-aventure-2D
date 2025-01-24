#pragma once 
#include "SFML/Graphics.hpp"
#include <fstream>
#include <iostream>
#include <vector>
#include "Player.hpp"
#include "PatrollingEnemy.hpp"
#include "ChaserEnemy.hpp"
#include "Potion.hpp"
#include "Key.hpp"

using namespace std;

class Map {
protected : 
	sf::Texture groundTexture;
	sf::Texture wallTexture;

	sf::Text win;
	sf::Font font;

	bool winGame = false;

public :

	vector<Player*> vector_player;
	vector<PatrollingEnemy*> vector_patroll;
	vector<ChaserEnemy*> vector_chaser;
	vector<Potion*> vector_potion;
	vector<Key*> vector_key;

	~Map();

	vector<string> vector_Map;

	void initAll();

	bool loadFromFile(string filename);
	void drawMap(sf::RenderWindow& window);
	void collisionMap(sf::Sprite& player, Key& key);
};