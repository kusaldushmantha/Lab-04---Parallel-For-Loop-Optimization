
#include "SampleCalculator.h"

int main() {

    int dimensions, iterations;
    int isParallel = 1;
    string method;

    cout << "Enter dimensions of the matrix: " << endl;
    cin >> dimensions;
    cout << "Enter number of the iterations: " << endl;
    cin >> iterations;
    cout << "Method of execution[p=parallel,s=sequential,o=optimized]: " << endl;
    cin >> method;
    cout << endl;

    if (method == "p") {
        isParallel = 0;
    } else if (method == "s") {
        isParallel = 1;
    }else if(method == "o"){
        isParallel = 2;
    }

    SampleCalculator sampleCalculator;
    sampleCalculator.noOfSamplesCalc(iterations, dimensions, isParallel);

    return 0;
}