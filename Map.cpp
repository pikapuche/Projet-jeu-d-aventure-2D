#include "Map.hpp"
#include "Player.hpp"
#include "PatrollingEnemy.hpp"
#include "ChaserEnemy.hpp"
#include "Potion.hpp"
#include "Key.hpp"

bool Map::loadFromFile(string filename) { // permet de verif si le fichier txt est importé
	ifstream file(filename);
	if (!file) {
		cerr << "Impossible d'ouvrir le fichier de la carte." << endl;
		return false;
	}

	string line;
	while (getline(file, line)) {
		vector_Map.push_back(line);
	}
}


void Map::drawMap(sf::RenderWindow& window, sf::Sprite& player, sf::Sprite& patroll, sf::Sprite& chaser, sf::Sprite& potion, sf::Sprite& key) {
	if (vector_Map.empty()) return;
	if (gameCount == 0) {
		sf::RectangleShape tile(sf::Vector2f(40, 40));

		for (size_t i = 0; i < vector_Map.size(); i++) {
			for (size_t j = 0; j < vector_Map[i].size(); j++) {
				switch (vector_Map[i][j]) {
				case '=': player.setPosition(j * 40, i * 40); break;
				case '!': tile.setFillColor(sf::Color::Red); break;
				case '&': patroll.setPosition(j * 40, i * 40); break;
				case '@': chaser.setPosition(j * 40, i * 40); break;
				case '#': tile.setFillColor(sf::Color::Cyan); break;
				case 'P': potion.setPosition(j * 40, i * 40); break;
				case 'K': key.setPosition(j * 40, i * 40); break;
				default:  tile.setFillColor(sf::Color::Black); break;
				}
				tile.setPosition(j * 40, i * 40);
				window.draw(tile);
				window.draw(player);
				window.draw(patroll);
				window.draw(chaser);
				window.draw(potion);
				window.draw(key);
			}
		}
	}
	else {
		sf::RectangleShape tile(sf::Vector2f(40, 40));

		for (size_t i = 0; i < vector_Map.size(); i++) {
			for (size_t j = 0; j < vector_Map[i].size(); j++) {
				switch (vector_Map[i][j]) {
				case '!': tile.setFillColor(sf::Color::Red); break;
				case '#': tile.setFillColor(sf::Color::Cyan); break;
				default:  tile.setFillColor(sf::Color::Black); break;
				}
				tile.setPosition(j * 40, i * 40);
				window.draw(tile);
				window.draw(potion);
				window.draw(key);
			}
		}
	}
	// = : pop du joueur
	// ! : mur
	// . : sol
	// & : patrolling
	// @ : chaser
	// # : porte
	// P : potion
	// K : clé
}

void Map::drawPlayer(sf::RenderWindow& window, sf::Sprite& player) {
	for (size_t i = 0; i < vector_Map.size(); i++) {
		for (size_t j = 0; j < vector_Map[i].size(); j++) {
			switch (vector_Map[i][j]) {
			case '=': player.setPosition(j * 40, i * 40); break;
			}
			window.draw(player);
		}
	}
}

void Map::drawPatroll(sf::RenderWindow& window, sf::Sprite& patroll) {
	for (size_t i = 0; i < vector_Map.size(); i++) {
		for (size_t j = 0; j < vector_Map[i].size(); j++) {
			switch (vector_Map[i][j]) {
			case '&': patroll.setPosition(j * 40, i * 40); break;
			}
			window.draw(patroll);
		}
	}
}

void Map::drawChaser(sf::RenderWindow& window, sf::Sprite& chaser) {
	for (size_t i = 0; i < vector_Map.size(); i++) {
		for (size_t j = 0; j < vector_Map[i].size(); j++) {
			switch (vector_Map[i][j]) {
			case '@': chaser.setPosition(j * 40, i * 40); break;
			}
			window.draw(chaser);
		}
	}
}

void Map::openDoor() {

}

int Map::getGameCount() {
	return gameCount;
}

int Map::setGameCount(int g) {
	gameCount += g;
	return gameCount;
}