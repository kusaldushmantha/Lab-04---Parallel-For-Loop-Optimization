//
// Created by kusal on 2/21/18.
//

#ifndef LAB4_SAMPLECALCULATOR_H
#define LAB4_SAMPLECALCULATOR_H

#include <iostream>
#include <vector>

using namespace std;


class SampleCalculator {
public:
    void noOfSamplesCalc(int iterations, int dimensions, bool isParallel);

public:
    double meanCalculator(vector<double> timeCollection);

public:
    double standardDevCalc(vector<double> timeCollection, double mean);
};


#endif //LAB4_SAMPLECALCULATOR_H
