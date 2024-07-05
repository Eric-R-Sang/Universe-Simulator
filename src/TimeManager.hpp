//
// Created by Eric Sang
//

/** Uses the Singleton pattern to ensure a single instance manages the simulation time step. **/
#ifndef UNIVERSESIMULATOR_TIMEMANAGER_H
#define UNIVERSESIMULATOR_TIMEMANAGER_H

#pragma once

class TimeManager {
public:
    static TimeManager& getInstance();
    void setTimeStep(double step);
    double getTimeStep() const;

private:
    TimeManager();
    double timeStep;
};

#endif //UNIVERSESIMULATOR_TIMEMANAGER_H
