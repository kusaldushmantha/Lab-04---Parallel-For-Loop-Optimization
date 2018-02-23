//
// Created by kusal on 2/21/18.
//

#include <iostream>
#include "InitializationMatrix.h"

vector<vector<double>> InitializationMatrix::generateSquareMatrix(int dimensions) {
    vector<vector<double>> finalMatrix;

    for (int i = 0; i < dimensions; i++) {
        vector<double> temp;
        for (int j = 0; j < dimensions; j++) {
            double randomValue = (rand() % 100 + 1) / double((rand() % 5 + 1));
            temp.push_back(randomValue);
        }
        finalMatrix.push_back(temp);
    }

    return finalMatrix;
}

vector<vector<double>> InitializationMatrix::generateEmptyMatrix(int dimensions) {
    vector<vector<double>> finalMatrix;

    for (int i = 0; i < dimensions; i++) {
        vector<double> temp;
        for (int j = 0; j < dimensions; j++) {
            temp.push_back(0);
        }
        finalMatrix.push_back(temp);
    }

    return finalMatrix;
}
