//
// Created by Eric Sang on 7/5/24.
//
#include "TimeManager.hpp"

TimeManager& TimeManager::getInstance() {
    static TimeManager instance;
    return instance;
}

TimeManager::TimeManager() : timeStep(1.0) {}

void TimeManager::setTimeStep(double step) { timeStep = step; }
double TimeManager::getTimeStep() const { return timeStep; }