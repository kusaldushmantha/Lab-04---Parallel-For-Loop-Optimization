//
// Created by kusal on 2/21/18.
//

#include "SequentialMultiplication.h"

#include <utility>
#include <omp.h>

double
SequentialMultiplication::sequentialMultiply(vector<vector<double>> matA,
                                             vector<vector<double>> matB,
                                             vector<vector<double>> matC) {

    auto dimensions = (int)matA.size();

    double startTime = clock();
    for(int i=0 ; i<dimensions; i++){
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

    //cout<<"Time Elapsed: "+to_string(elapsedTime)<<endl;
    cout<<elapsedTime<<endl;
    return elapsedTime;
}
