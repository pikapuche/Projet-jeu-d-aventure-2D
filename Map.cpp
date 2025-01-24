#include "Map.hpp"
#include "Player.hpp"
#include "PatrollingEnemy.hpp"
#include "ChaserEnemy.hpp"
#include "Potion.hpp"
#include "Key.hpp"
#include <windows.h>
#include <thread>

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

	if (!font.loadFromFile("Assets/Minecraft.ttf"))
	{
		cout << "error font" << endl << endl;
	}
}

void Map::drawMap(sf::RenderWindow& window) {
	if (vector_Map.empty()) return;
	sf::RectangleShape tile(sf::Vector2f(40, 40));

	for (size_t i = 0; i < vector_Map.size(); i++) {
		for (size_t j = 0; j < vector_Map[i].size(); j++) {
			switch (vector_Map[i][j]) {
			case '!': tile.setFillColor(sf::Color::Red); break;
			case '#': tile.setFillColor(sf::Color::Cyan); break;
			default:  tile.setFillColor(sf::Color::Black); break;
			}
			tile.setPosition(j * 40.f, i * 40.f);
			window.draw(tile);
			if (winGame) {
				window.draw(win);
				this_thread::sleep_for(std::chrono::seconds(3));
				window.close();
			}
		}
	}

}

void Map::collisionMap(sf::Sprite& player, Key& key) {
	if (vector_Map.empty()) return;
	sf::RectangleShape tile(sf::Vector2f(40, 40));

	for (size_t i = 0; i < vector_Map.size(); i++) {
		for (size_t j = 0; j < vector_Map[i].size(); j++) {
			switch (vector_Map[i][j]) {
			case '!': 
				if (tile.getGlobalBounds().intersects(player.getGlobalBounds())) {
					player.setColor(sf::Color::Blue);
				}
				break;
			case '#':	
				if (tile.getGlobalBounds().intersects(player.getGlobalBounds())) {
					player.setColor(sf::Color::Magenta);
				}

				if (tile.getGlobalBounds().intersects(player.getGlobalBounds()) && key.keyCount >= 1 && sf::Keyboard::isKeyPressed(sf::Keyboard::E)) {
					win.setFont(font);
					win.setString("YOU WIN YOUPIIIIII");
					win.setCharacterSize(100);
					win.setPosition(360, 440);
					winGame = true;
					cout << "VOUS ETES MORT BOUUUUUUUUUUUUUUUU" << endl << endl;
				}
				break;

			default:  tile.setFillColor(sf::Color::Black); break;
			}
			tile.setPosition(j * 40.f, i * 40.f);
		}
	}

}

/*void Map::drawMap(sf::RenderWindow& window, sf::Sprite& player, sf::Sprite& patroll, sf::Sprite& chaser, sf::Sprite& potion, sf::Sprite& key) {
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
}*/

void Map::initAll() {
	if (vector_Map.empty()) return;
	sf::RectangleShape tile(sf::Vector2f(40, 40));

	for (size_t i = 0; i < vector_Map.size(); i++) {
		for (size_t j = 0; j < vector_Map[i].size(); j++) {
			switch (vector_Map[i][j]) {
			case '=':
			{
				Player* players = new Player("Joueur", j * 40.f, i * 40.f, 1.f);
				vector_player.push_back(players);
				players->initPlayer();
				break;

			}


			case '&':
			{
				PatrollingEnemy* patrollers = new PatrollingEnemy("Bob", j * 40.f, i * 40.f, 2.0f);
				vector_patroll.push_back(patrollers);
				patrollers->initPatrollingEnemy();
				break;
			}

			case '@':
			{
				ChaserEnemy* chasers = new ChaserEnemy("Fred", j * 40.f, i * 40.f, 0.25);
				vector_chaser.push_back(chasers);
				chasers->initChaserEnemy();
				break;
			}

			case 'P':
			{
				Potion* potions = new Potion("Popo", j * 40.f, i * 40.f);
				vector_potion.push_back(potions);
				potions->initPotion();
				break;
			}

			case 'K':
			{
				Key* keys = new Key("Cle", j * 40.f, i * 40.f);
				vector_key.push_back(keys);
				keys->initKey();
				break;
			}


			default:  tile.setFillColor(sf::Color::Black); break;
			}
			tile.setPosition(j * 40.f, i * 40.f);
		}
	}
}

Map::~Map() {
	for (auto players : vector_player) {
		delete players;
	}
	vector_player.clear();

	for (auto patrollers : vector_patroll) {
		delete patrollers;
	}
	vector_patroll.clear();

	for (auto chasers : vector_chaser) {
		delete chasers;
	}
	vector_chaser.clear();

	for (auto potions : vector_potion) {
		delete potions;
	}
	vector_potion.clear();

	for (auto keys : vector_key) {
		delete keys;
	}
	vector_key.clear();
}