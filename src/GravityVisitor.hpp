//
// Created by Eric Sang on 7/5/24.
//
/** applies gravitational forces between celestial bodies. **/
#ifndef UNIVERSESIMULATOR_GRAVITYVISITOR_H
#define UNIVERSESIMULATOR_GRAVITYVISITOR_H

#pragma once
#include "CelestialBody.hpp"

class GravityVisitor {
public:
    GravityVisitor();
    void visit(CelestialBody& body1, CelestialBody& body2);
    void setTimeScale(float scale);

private:
    float timeScale;
};


#endif //UNIVERSESIMULATOR_GRAVITYVISITOR_H
