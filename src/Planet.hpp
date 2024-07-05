#pragma once
#include "CelestialBody.hpp"
#include <SFML/Graphics.hpp>

class Planet : public CelestialBody {
public:
    Planet(double mass, double orbitRadius, double angularVelocity, double centerX, double centerY, double radius, sf::Color color);
    void update(double dt) override;
    void render(sf::RenderWindow& window) const override;
    sf::Vector2f getPosition() const override;
    void setPosition(float x, float y) override;

private:
    double orbitRadius;
    double angularVelocity;
    double centerX;
    double centerY;
    double radius;
    double angle;
    sf::Color color;
    sf::CircleShape shape;

    void updatePosition();
};