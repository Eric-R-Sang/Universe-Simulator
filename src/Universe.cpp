#include "Universe.hpp"
#include "GravityVisitor.hpp"
#include <cmath>

void Universe::addBody(std::unique_ptr<CelestialBody> body) {
    bodies.push_back(std::move(body));
}

void Universe::addStars(std::vector<std::unique_ptr<CelestialBody>> newStars) {
    for (auto& star : newStars) {
        stars.push_back(std::move(star));
    }
}

void Universe::update(double dt) {
    GravityVisitor gravityVisitor;

    // Apply gravity between all pairs of bodies, except stars
    for (size_t i = 0; i < bodies.size(); ++i) {
        for (size_t j = i + 1; j < bodies.size(); ++j) {
            gravityVisitor.visit(*bodies[i], *bodies[j]);
        }
    }

    // Update positions of all bodies
    for (auto& body : bodies) {
        body->update(dt);
    }

    // Special handling for the Moon (assuming it's the 5th body, index 4)
    if (bodies.size() >= 5) {
        sf::Vector2f earthPos = bodies[3]->getPosition(); // Earth is the 4th body (index 3)
        sf::Vector2f moonPos = bodies[4]->getPosition(); // Moon is the 5th body (index 4)

        // Calculate the Moon's position relative to Earth
        double moonAngle = std::atan2(moonPos.y - CENTER_Y, moonPos.x - CENTER_X);
        double moonDistance = 20; // Same as in CelestialBodyFactory::createMoon

        // Set the Moon's new position relative to Earth
        bodies[4]->setPosition(
                earthPos.x + moonDistance * std::cos(moonAngle),
                earthPos.y + moonDistance * std::sin(moonAngle)
        );
    }
}

void Universe::render(sf::RenderWindow& window) const {
    // Render stars first (background)
    for (const auto& star : stars) {
        star->render(window);
    }

    // Then render planets and moon
    for (const auto& body : bodies) {
        body->render(window);
    }
}