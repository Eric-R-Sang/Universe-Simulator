#include <SFML/Graphics.hpp>
#include "Universe.hpp"
#include "CelestialBodyFactory.hpp"
#include <iostream>

int main() {
    sf::RenderWindow window(sf::VideoMode(1200, 800), "Solar System Simulator");
    Universe universe;

    // Add stars
    universe.addStars(CelestialBodyFactory::createStars(200));

    // Add planets
    universe.addBody(CelestialBodyFactory::createSun());
    universe.addBody(CelestialBodyFactory::createMercury());
    universe.addBody(CelestialBodyFactory::createVenus());
    universe.addBody(CelestialBodyFactory::createEarth());
    universe.addBody(CelestialBodyFactory::createMoon());
    universe.addBody(CelestialBodyFactory::createMars());
    universe.addBody(CelestialBodyFactory::createJupiter());
    universe.addBody(CelestialBodyFactory::createSaturn());

    float timeScale = 1.0f;

    sf::Clock clock;
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Up) {
                    timeScale *= 2.0f;
                    std::cout << "Time scale: " << timeScale << std::endl;
                }
                if (event.key.code == sf::Keyboard::Down) {
                    timeScale *= 0.5f;
                    std::cout << "Time scale: " << timeScale << std::endl;
                }
                if (event.key.code == sf::Keyboard::R) {
                    timeScale = 1.0f;
                    std::cout << "Time scale reset to 1.0" << std::endl;
                }
            }
        }

        double dt = clock.restart().asSeconds();
        universe.update(dt * timeScale);

        window.clear(sf::Color::Black);
        universe.render(window);
        window.display();
    }

    return 0;
}
