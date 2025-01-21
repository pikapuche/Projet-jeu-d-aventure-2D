#include "Game.hpp" 
 
void Game::inGame() {

    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Escape The Dungeon", sf::Style::Fullscreen);
    window.setFramerateLimit(165);


    Player player("Joueur", 10, 10, 3.0f, 100);
    PatrollingEnemy patrollEnemy1("Fred", 50, 50, 2.0f, 1, 20);
    ChaserEnemy chaserEnemy1("Patoche", 500, 500, 1.0f, 1, 20);
    Potion potion1("Potion de vitesse", 600, 400);
    Key key1("Premiere cle", 500, 200);

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
            potions.interact(player);
            potions.glouglou(player);
            potions.update(1);
            if (!potions.getDepop()) potions.draw(window);
        }

        for (auto& keys : vector_key) {
            keys.interact(player);
            keys.useKey();
            keys.update(1);
            if (!keys.getDepop()) keys.draw(window);
        }

        for (auto& players : vector_player) {
            players.keyboardManager();
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

        window.display();
    }
}