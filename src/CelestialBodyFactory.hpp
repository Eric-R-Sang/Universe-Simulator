#pragma once
#include "CelestialBody.hpp"
#include <memory>
#include <vector>
#include <SFML/Graphics.hpp>

class CelestialBodyFactory {
public:
    static std::unique_ptr<CelestialBody> createSun();
    static std::unique_ptr<CelestialBody> createMercury();
    static std::unique_ptr<CelestialBody> createVenus();
    static std::unique_ptr<CelestialBody> createEarth();
    static std::unique_ptr<CelestialBody> createMoon();
    static std::unique_ptr<CelestialBody> createMars();
    static std::unique_ptr<CelestialBody> createJupiter();
    static std::unique_ptr<CelestialBody> createSaturn();
    static std::vector<std::unique_ptr<CelestialBody>> createStars(int numStars);

private:
    static std::unique_ptr<CelestialBody> createPlanet(double mass, double orbitRadius, double angularVelocity, double radius, sf::Color color);
};