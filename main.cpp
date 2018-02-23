
#include "SampleCalculator.h"

int main() {

    int dimensions, iterations;
    bool isParallel = false;
    bool optimizedRun = false;
    string method;

    cout << "Enter dimensions of the matrix: " << endl;
    cin >> dimensions;
    cout << "Enter number of the iterations: " << endl;
    cin >> iterations;
    cout << "Method of execution[y=parallel,n=sequential]: " << endl;
    cin >> method;
    cout << endl;

    if (method == "y") {
        isParallel = true;
    } else if (method == "n") {
        isParallel = false;
    }

    SampleCalculator sampleCalculator;
    sampleCalculator.noOfSamplesCalc(iterations, dimensions, isParallel);

    return 0;
}