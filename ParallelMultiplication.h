//
// Created by kusal on 2/21/18.
//

#ifndef LAB4_PARALLELMULTIPLICATION_H
#define LAB4_PARALLELMULTIPLICATION_H

#include <iostream>
#include <vector>

using namespace std;

class ParallelMultiplication {
public:
    double parallelMultiply(vector<vector<double>> matA,
                              vector<vector<double>> matB,
                              vector<vector<double>> matC);

public:
    int noThreadCount = 1;
};


#endif //LAB4_PARALLELMULTIPLICATION_H
