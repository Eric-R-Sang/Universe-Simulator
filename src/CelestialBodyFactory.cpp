#include "CelestialBodyFactory.hpp"
#include "Planet.hpp"
#include "Star.hpp"
#include "Universe.hpp"
#include <cmath>
#include <random>

const double SPEED_MULTIPLIER = 12.0;

std::unique_ptr<CelestialBody> CelestialBodyFactory::createSun() {
    return std::make_unique<Planet>(1.989e30, 0, 0, Universe::CENTER_X, Universe::CENTER_Y, 20, sf::Color::Yellow);
}

std::unique_ptr<CelestialBody> CelestialBodyFactory::createMercury() {
    return createPlanet(3.285e23, 50, 0.05 * SPEED_MULTIPLIER, 4, sf::Color(169, 169, 169));
}

std::unique_ptr<CelestialBody> CelestialBodyFactory::createVenus() {
    return createPlanet(4.867e24, 90, 0.04 * SPEED_MULTIPLIER, 6, sf::Color(255, 198, 73));
}

std::unique_ptr<CelestialBody> CelestialBodyFactory::createEarth() {
    return createPlanet(5.97e24, 130, 0.03 * SPEED_MULTIPLIER, 7, sf::Color::Blue);
}

std::unique_ptr<CelestialBody> CelestialBodyFactory::createMoon() {
    const double MOON_DISTANCE = 20;
    const double MOON_SPEED = 0.08 * SPEED_MULTIPLIER;
    return std::make_unique<Planet>(7.34767309e22, MOON_DISTANCE, MOON_SPEED, Universe::CENTER_X, Universe::CENTER_Y, 2, sf::Color::White);
}

std::unique_ptr<CelestialBody> CelestialBodyFactory::createMars() {
    return createPlanet(6.39e23, 170, 0.025 * SPEED_MULTIPLIER, 5, sf::Color::Red);
}

std::unique_ptr<CelestialBody> CelestialBodyFactory::createJupiter() {
    return createPlanet(1.898e27, 230, 0.02 * SPEED_MULTIPLIER, 15, sf::Color(255, 140, 0));
}

std::unique_ptr<CelestialBody> CelestialBodyFactory::createSaturn() {
    return createPlanet(5.683e26, 290, 0.015 * SPEED_MULTIPLIER, 13, sf::Color(238, 232, 170));
}

std::vector<std::unique_ptr<CelestialBody>> CelestialBodyFactory::createStars(int numStars) {
    std::vector<std::unique_ptr<CelestialBody>> stars;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> disX(0, 1200);
    std::uniform_real_distribution<> disY(0, 800);

    for (int i = 0; i < numStars; ++i) {
        stars.push_back(std::make_unique<Star>(disX(gen), disY(gen)));
    }
    return stars;
}

std::unique_ptr<CelestialBody> CelestialBodyFactory::createPlanet(double mass, double orbitRadius, double angularVelocity, double radius, sf::Color color) {
    return std::make_unique<Planet>(mass, orbitRadius, angularVelocity, Universe::CENTER_X, Universe::CENTER_Y, radius, color);
}