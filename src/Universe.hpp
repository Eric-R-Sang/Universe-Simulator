//
// Created by Eric Sang on 7/5/24.
//
/** manages the collection of celestial bodies and handles updates and rendering. **/
#ifndef UNIVERSESIMULATOR_UNIVERSE_H
#define UNIVERSESIMULATOR_UNIVERSE_H

#pragma once
#include "CelestialBody.hpp"
#include <vector>
#include <memory>
#include <SFML/Graphics.hpp>

class Universe {
public:
    static constexpr double CENTER_X = 600;
    static constexpr double CENTER_Y = 400;

    void addBody(std::unique_ptr<CelestialBody> body);
    void addStars(std::vector<std::unique_ptr<CelestialBody>> stars);
    void update(double dt);
    void render(sf::RenderWindow& window) const;

private:
    std::vector<std::unique_ptr<CelestialBody>> bodies;
    std::vector<std::unique_ptr<CelestialBody>> stars;
};

#endif //UNIVERSESIMULATOR_UNIVERSE_H
