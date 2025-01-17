#include "Game.hpp" 
 
void Game::inGame() {

    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Escape The Dungeon", sf::Style::Fullscreen);


    Player player("Joueur", 10, 10, 1.0f, 10, 100);

    player.initPlayer();
    vector_player.push_back(player);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        for (auto& players : vector_player) {
            players.keyboardManager();
            players.update(100);
            players.draw(window);
        }

        window.display();
    }
}