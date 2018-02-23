//
// Created by kusal on 2/21/18.
//

#include <cmath>
#include "SampleCalculator.h"
#include "SequentialMultiplication.h"
#include "InitializationMatrix.h"
#include "ParallelMultiplication.h"
#include "OptimizedParallelMatrixMultiplication.h"

void SampleCalculator::noOfSamplesCalc(int iterations, int dimensions, int isParallel) {
    InitializationMatrix init;
    SequentialMultiplication seqMul;
    ParallelMultiplication parallelMul;
    OptimizedParallelMatrixMultiplication optimised;

    vector<double> timeCollection;;
    int threads = 1;
    for (int i = 0; i < iterations; i++) {

        auto matrixA = init.generateSquareMatrix(dimensions);
        auto matrixB = init.generateSquareMatrix(dimensions);
        auto matrixC = init.generateEmptyMatrix(dimensions);

        if (isParallel==0) {
            timeCollection.push_back(parallelMul.parallelMultiply(matrixA, matrixB, matrixC));
            threads = parallelMul.noThreadCount;
        }else if(isParallel==1){
            timeCollection.push_back(seqMul.sequentialMultiply(matrixA, matrixB, matrixC));
        }else {
            timeCollection.push_back(optimised.optimizedMultiplication(matrixA, matrixB, matrixC, dimensions));
            threads = optimised.threadCount;
        }

    }

    double mean = meanCalculator(timeCollection);
    double stdDev = standardDevCalc(timeCollection, mean);

    double samples = ((100 * 1.96 * stdDev) / (5 * mean));
    if(samples<=1){
        samples = 10;
    }

    cout << "Dimensions:" + to_string(dimensions) << endl;
    cout << "Iterations:" + to_string(iterations) << endl;
    cout << "Thread count:" + to_string(threads) << endl;
    cout << "Mean:" + to_string(mean) << endl;
    cout << "Standard Deviation:" + to_string(stdDev) << endl;
    cout << "No Samples:" + to_string(int(samples) + 1) << endl;
}

double SampleCalculator::meanCalculator(vector<double> timeCollection) {
    double sum = 0;
    for (double i : timeCollection) {
        sum += i;
    }
    return (sum / timeCollection.size());
}

double SampleCalculator::standardDevCalc(vector<double> timeCollection, double mean) {
    double std = 0;
    for (double i : timeCollection) {
        std += pow((i - mean), 2);
    }
    return (std / timeCollection.size());
}
