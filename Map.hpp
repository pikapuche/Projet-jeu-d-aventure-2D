#pragma once 
#include "SFML/Graphics.hpp"
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

class Map {
protected : 
	sf::Texture groundTexture;
	sf::Texture wallTexture;

public : 
	int gameCount = 0;

	//const int TILE_SIZE = 32;

	vector<string> vector_Map;
	bool loadFromFile(string filename);
	void drawMap(sf::RenderWindow& window, sf::Sprite& player, sf::Sprite& patroll, sf::Sprite& chaser, sf::Sprite& potion, sf::Sprite& key);
	void drawPlayer(sf::RenderWindow& window, sf::Sprite& player);
	void drawPatroll(sf::RenderWindow& window, sf::Sprite& patroll);
	void drawChaser(sf::RenderWindow& window, sf::Sprite& chaser);


	void openDoor();
	int getGameCount();
	int setGameCount(int g);
};