#include "GravityVisitor.hpp"
#include <cmath>

GravityVisitor::GravityVisitor() : timeScale(1.0f) {}

void GravityVisitor::visit(CelestialBody& body1, CelestialBody& body2) {
    const double G = 0.15;  // Increased from 0.1 to 0.15
    const double SUN_MASS = 1000000;  // Mass of the Sun in our scale

    sf::Vector2f r = body2.getPosition() - body1.getPosition();
    double distance = std::sqrt(r.x * r.x + r.y * r.y);

    const double MIN_DISTANCE = 1.0;
    if (distance < MIN_DISTANCE) {
        distance = MIN_DISTANCE;
    }

    // Check if body1 is the Sun (assuming it's always at the center)
    bool isSun = (body1.getPosition() == sf::Vector2f(600, 400));

    double forceMagnitude;
    if (isSun) {
        forceMagnitude = G * SUN_MASS * body2.getMass() / (distance * distance);
    } else {
        // Greatly reduce inter-planetary gravitational effects
        forceMagnitude = G * body1.getMass() * body2.getMass() / (distance * distance) * 0.0001;
    }

    sf::Vector2f forceDirection = r / static_cast<float>(distance);
    sf::Vector2f force = forceDirection * static_cast<float>(forceMagnitude);

    // Only apply force to body2 if body1 is the Sun, otherwise apply to both
    if (isSun) {
        sf::Vector2f acc2 = force / static_cast<float>(body2.getMass());
        body2.updateVelocity(acc2, timeScale * 0.015f);  // Increased from 0.01f to 0.015f
    } else {
        sf::Vector2f acc1 = -force / static_cast<float>(body1.getMass());
        sf::Vector2f acc2 = force / static_cast<float>(body2.getMass());
        body1.updateVelocity(acc1, timeScale * 0.015f);  // Increased from 0.01f to 0.015f
        body2.updateVelocity(acc2, timeScale * 0.015f);  // Increased from 0.01f to 0.015f
    }
}

void GravityVisitor::setTimeScale(float scale) {
    timeScale = scale;
}