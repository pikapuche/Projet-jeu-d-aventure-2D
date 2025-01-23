#include "Game.hpp" 
 
void Game::inGame() {

    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Escape The Dungeon", sf::Style::Fullscreen);
    window.setFramerateLimit(165);

    Player player("Joueur", 10, 10, 3.0f, 100);
    PatrollingEnemy patrollEnemy1("Fred", 50, 50, 2.0f, 1, 20);
    ChaserEnemy chaserEnemy1("Patoche", 500, 500, 1.0f, 1, 20);
    Potion potion1("Potion de vitesse ", 600, 400);
    Key key1("Cle ", 500, 200);
    Map map;

    player.initPlayer();
    vector_player.push_back(player);

    patrollEnemy1.initPatrollingEnemy();
    vector_patroll.push_back(patrollEnemy1);

    chaserEnemy1.initChaserEnemy();
    vector_chaser.push_back(chaserEnemy1);

    potion1.initPotion();
    vector_potion.push_back(potion1);

    key1.initKey();
    vector_key.push_back(key1);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        for (auto& potions : vector_potion) {
            if (!potions.getDepop()) {
                for (auto& players : vector_player) {
                    potions.interact(players);
                }
                potions.update(1);
                potions.draw(window);
            }

            for (auto& players : vector_player) {
                potions.glouglou(players, players.playerSprite);
                potions.stopGlouglou(players, players.playerSprite);
            }
        }

        for (auto& keys : vector_key) {
            if (!keys.getDepop()) {
                for (auto& players : vector_player) {
                    keys.interact(players);
                }
                keys.useKey();
                keys.update(1);
                keys.draw(window);
            }
        }

        for (auto& players : vector_player) {
            players.update(1);
            players.draw(window);
        }

        for (auto& patrollers : vector_patroll) {
            patrollers.moving(1);
            patrollers.patrolPatern();
            for (auto& players : vector_player) {
                patrollers.catchPlayer(players.playerSprite);
            }
            patrollers.update(1);
            patrollers.draw(window);
        }

        for (auto& chasers : vector_chaser) {
            for (auto& players : vector_player) {
                chasers.chasePatern(players.playerSprite);
                chasers.catchPlayer(players.playerSprite);
            }
            chasers.update(1);
            chasers.draw(window);
        }

        map.loadFromFile("C:\\Users\\quent\\source\\repos\\Projet jeu d'aventure 2D\\Assets\\Map\\fichier_txt_map.txt");
        map.openDoor();
        for (auto& players : vector_player) {
            for (auto& patrollers : vector_patroll) {
                for (auto& chasers : vector_chaser) {
                    for (auto& potions : vector_potion) {
                        for (auto& keys : vector_key) {
                            map.drawMap(window, players.playerSprite, patrollers.patrollSprite, chasers.chaserSprite, potions.potionSprite, keys.keySprite);
                        }
                    }
                }
            }
        }

        for (auto& players : vector_player) {
            map.drawPlayer(window, players.playerSprite);
        }

        for (auto& patrollers : vector_patroll) {
            map.drawPatroll(window, patrollers.patrollSprite);
        }

        for (auto& chasers : vector_chaser) {
            map.drawChaser(window, chasers.chaserSprite);
        }

        // on continue mais dcp ca marche pas sa grand mere

        if (map.gameCount == 0) {
            map.gameCount++;
        }

        window.display();
    }
}