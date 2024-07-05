//
// Created by Eric Sang on 7/5/24.
//

#ifndef UNIVERSESIMULATORPROJECT_STAR_H
#define UNIVERSESIMULATORPROJECT_STAR_H

#pragma once
#include "CelestialBody.hpp"

class Star : public CelestialBody {
public:
    Star(float x, float y);
    void update(double dt) override;
    void render(sf::RenderWindow& window) const override;
    sf::Vector2f getPosition() const override;
    void setPosition(float x, float y) override;

private:
    sf::CircleShape shape;
};

#endif //UNIVERSESIMULATORPROJECT_STAR_H
