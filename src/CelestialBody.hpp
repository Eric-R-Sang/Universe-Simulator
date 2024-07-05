#pragma once
#include <SFML/Graphics.hpp>

class CelestialBody {
public:
    CelestialBody(double mass, double x, double y, double vx, double vy);
    virtual ~CelestialBody() = default;

    virtual void update(double dt) = 0;
    virtual void render(sf::RenderWindow& window) const = 0;

    virtual sf::Vector2f getPosition() const = 0;
    virtual void setPosition(float x, float y) = 0;
    virtual void updateVelocity(const sf::Vector2f& acceleration, float timeScale);

    double getMass() const { return mass; }

protected:
    double mass;
    sf::Vector2f position;
    sf::Vector2f velocity;
};