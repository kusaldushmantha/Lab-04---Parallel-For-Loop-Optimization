//
// Created by kusal on 2/21/18.
//

#ifndef LAB4_INITIALIZATIONMATRIX_H
#define LAB4_INITIALIZATIONMATRIX_H

#include <string>
#include <vector>

using namespace std;

class InitializationMatrix {
public:
    vector<vector<double>> generateSquareMatrix(int dimensions);

public:
    vector<vector<double>> generateEmptyMatrix(int dimensions);
};


#endif //LAB4_INITIALIZATIONMATRIX_H
