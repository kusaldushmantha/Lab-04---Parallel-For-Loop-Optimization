//
// Created by kusal on 2/21/18.
//

#ifndef LAB4_OPTIMIZEDPARALLELMATRIXMULTIPLICATION_H
#define LAB4_OPTIMIZEDPARALLELMATRIXMULTIPLICATION_H

#include <iostream>
#include <vector>

using namespace std;

class OptimizedParallelMatrixMultiplication {
public:
     double optimizedMultiplication(vector<vector<double>> matA,vector<vector<double>> matB,vector<vector<double>> emptyMat,int dimension);

public:
    int threadCount =0;
public:
    vector<vector<double>> transposeMatrix(vector<vector<double>> matrix, int dimensions);

public:
    double computeDotProduct(vector<double> val1, vector<double> val2,int dimension);
};


#endif //LAB4_OPTIMIZEDPARALLELMATRIXMULTIPLICATION_H
