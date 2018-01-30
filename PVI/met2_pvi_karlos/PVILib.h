#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <iostream>

#ifndef PVILIB_H
#define PVILIB_H

using namespace std;

class PVILib
{
public:
    PVILib();
    ~PVILib();
    double F(double x);

    double f(double, double);
    double* forwardEuler(double, double, double, int);
    double* backwardEuler(double, double, double, int);
    double* modifiedEuler(double, double, double, int);
    double* rungeKuttaG5(double, double, double, int);
    double* predictorCorrector(double, double, double, int);

private:
};

#endif // PVILIB_H
