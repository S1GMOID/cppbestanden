#include <SFML/Graphics.hpp>
#include <algorithm>
#include "winners.hpp"

int main() {
    vector<float> results {5.322, 8.76, 2.12, 745, 98.1, 23.6, 87.3};

    float winner = nearestScore2Average(results);
    float mole = furthestScoreFromWinner(results);
    float maxScore = *max_element(results.begin(), results.end());

    sf::RenderWindow window(sf::VideoMode(800, 400), "TV sensatie");

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::White);

        for (size_t i = 0; i < results.size(); i++) {
            float height = results[i] / maxScore * 350;
            sf::RectangleShape bar(sf::Vector2f(80.f, height));
            bar.setPosition(20.f + i * 110.f, 380.f - height);

            if (results[i] == winner)    bar.setFillColor(sf::Color::Green);
            else if (results[i] == mole) bar.setFillColor(sf::Color::Red);
            else                         bar.setFillColor(sf::Color(150, 150, 150));

            window.draw(bar);
        }
        window.display();
    }
    return 0;
}