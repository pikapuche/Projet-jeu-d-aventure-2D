#include "Game.hpp" 
 
void Game::inGame() {

    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Escape The Dungeon", sf::Style::Fullscreen);
    window.setFramerateLimit(165);

    Map map;

    map.loadFromFile("Assets/fichier_txt_map.txt");
    map.initAll();


    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        map.drawMap(window);

        for (auto& potions : map.vector_potion) {
            if (!potions->getDepop()) {
                for (auto& players : map.vector_player) {
                    potions->interact(*players);
                }
                potions->update(1);
                potions->draw(window);
            }

            for (auto& players : map.vector_player) {
                potions->glouglou(*players, players->playerSprite);
                potions->stopGlouglou(*players, players->playerSprite);
            }

        }

        for (auto& keys : map.vector_key) {
            if (!keys->getDepop()) {
                for (auto& players : map.vector_player) {
                    keys->interact(*players);
                }
                keys->update(1);
                keys->draw(window);
            }
        }

        for (auto& players : map.vector_player) {
            players->update(1);
            for (auto& keys : map.vector_key) {
                map.collisionMap(players->playerSprite, *keys);
            }
            players->draw(window);
        }

        for (auto& patrollers : map.vector_patroll) {
            patrollers->moving(1);
            patrollers->patrolPatern();
            for (auto& players : map.vector_player) {
                patrollers->catchPlayer(players->playerSprite);
            }
            patrollers->update(1);
            patrollers->draw(window);
        }

        for (auto& chasers : map.vector_chaser) {
            for (auto& players : map.vector_player) {
                chasers->chasePatern(players->playerSprite);
                chasers->catchPlayer(players->playerSprite);
            }
            chasers->update(1);
            chasers->draw(window);
        }

        window.display();
    }
}