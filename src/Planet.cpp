#include "Planet.hpp"
#include <cmath>

Planet::Planet(double mass, double orbitRadius, double angularVelocity, double centerX, double centerY, double radius, sf::Color color)
        : CelestialBody(mass, centerX + orbitRadius, centerY, 0, 0),
          orbitRadius(orbitRadius), angularVelocity(angularVelocity), centerX(centerX), centerY(centerY),
          radius(radius), color(color), angle(0) {
    shape.setRadius(radius);
    shape.setFillColor(color);
    updatePosition();
}

void Planet::update(double dt) {
    angle += angularVelocity * dt;
    updatePosition();
}

void Planet::updatePosition() {
    position.x = centerX + orbitRadius * std::cos(angle);
    position.y = centerY + orbitRadius * std::sin(angle);
    shape.setPosition(position.x - radius, position.y - radius);
}

void Planet::render(sf::RenderWindow& window) const {
    window.draw(shape);
}

sf::Vector2f Planet::getPosition() const {
    return position;
}

void Planet::setPosition(float x, float y) {
    position.x = x;
    position.y = y;
    shape.setPosition(x - radius, y - radius);
}