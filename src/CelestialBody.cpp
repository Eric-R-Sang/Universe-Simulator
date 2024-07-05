#include "CelestialBody.hpp"

CelestialBody::CelestialBody(double mass, double x, double y, double vx, double vy)
        : mass(mass), position(x, y), velocity(vx, vy) {}

void CelestialBody::updateVelocity(const sf::Vector2f& acceleration, float timeScale) {
    velocity += acceleration * timeScale;
}