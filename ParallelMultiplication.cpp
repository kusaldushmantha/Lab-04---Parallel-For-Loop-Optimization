//
// Created by kusal on 2/21/18.
//

#include <omp.h>
#include "ParallelMultiplication.h"

double
ParallelMultiplication::parallelMultiply(vector<vector<double>> matA,
                                             vector<vector<double>> matB,
                                             vector<vector<double>> matC) {
    auto dimensions = (int)matA.size();
    noThreadCount = 0;

    omp_set_num_threads(10);
    double startTime = clock();
    #pragma omp parallel for
        for(int i=0 ; i<dimensions; i++){
            noThreadCount = omp_get_num_threads();
            for(int j=0; j<dimensions; j++){
                for(int k=0; k<dimensions; k++){
                    matC[i][j] += matA[i][k] * matB[k][j];
                }
            }
        }

    double endTime = clock();

    //VALIDATING THE MULTIPLICATION
    /*for(int i=0;i<dimensions;i++){
        for(int j=0;j<dimensions;j++){
            cout<<to_string(result[i][j])+" ";
        }
        cout<<endl;
    }*/

    double elapsedTime = (endTime-startTime)/CLOCKS_PER_SEC;
    cout<<elapsedTime<<endl;
    return elapsedTime;
}
