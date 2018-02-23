//
// Created by kusal on 2/21/18.
//

#include "OptimizedParallelMatrixMultiplication.h"
#include "InitializationMatrix.h"
#include <omp.h>

double
OptimizedParallelMatrixMultiplication::optimizedMultiplication(vector<vector<double>> matA, vector<vector<double>> matB,
                                                               vector<vector<double>> emptyMat, int dimension) {

    vector<vector<double>> transposedMat = transposeMatrix(matB, dimension);
omp_set_num_threads(10);
#pragma parallel for
    for (int i = 0; i < dimension; i++) {
        threadCount = omp_get_num_threads();
        for (int j = 0; j < dimension; ++j) {
            emptyMat[i][j] = computeDotProduct(matA[i], transposedMat[j], dimension);
        }
    }
}

vector<vector<double>>
OptimizedParallelMatrixMultiplication::transposeMatrix(vector<vector<double>> matrix, int dimensions) {
    InitializationMatrix initializationMatrix;
    vector<vector<double>> matTranspose = initializationMatrix.generateEmptyMatrix(dimensions);

#pragma parallel for
    for (int i = 0; i < dimensions; i++) {
        for (int j = 0; j < dimensions; ++j) {
            matTranspose[j][i] = matrix[i][j];
        }
    }
    return matTranspose;
}

double
OptimizedParallelMatrixMultiplication::computeDotProduct(vector<double> val1, vector<double> val2, int dimension) {
    double temp = 0.0;
    for (int i = 0; i < dimension; i++) {
        temp += val1[i] * val2[i];
    }
    return temp;
}
