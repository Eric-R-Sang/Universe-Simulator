//
// Created by Eric Sang on 7/5/24.
//

#include "Star.hpp"

Star::Star(float x, float y) : CelestialBody(0, x, y, 0, 0) {
    shape.setRadius(1);
    shape.setFillColor(sf::Color::White);
    shape.setPosition(x, y);
}

void Star::update(double dt) {
    // Stars are stationary, so no update is needed
}

void Star::render(sf::RenderWindow& window) const {
    window.draw(shape);
}

sf::Vector2f Star::getPosition() const {
    return shape.getPosition();
}

void Star::setPosition(float x, float y) {
    shape.setPosition(x, y);
}