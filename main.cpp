#include "include/MonteCarloApproximation.h"
#include "include/MachinsFormulaPiApproximation.h"
#include <chrono>
#include <iostream>

using namespace std;
void testMonteCarloApproximation();
void testMachinsFormulaApproximation();

int main() {
    testMonteCarloApproximation();
    testMachinsFormulaApproximation();
    return 0;
}

void testMonteCarloApproximation() {
    //Run monte carlo with 10 million iterations
    //2000 bits of precision would be about 600 decimals in base10
    MonteCarloApproximation monteCarloPiApproximator(2000);
    auto start = chrono::high_resolution_clock::now();

    monteCarloPiApproximator.calculate(10000000, 4);
    auto end = chrono::high_resolution_clock::now();

    // Calculate the duration
    chrono::duration<double> duration = end - start;
    // Output the time in seconds
    cout << "Execution time monte carlo: " << duration.count() << " seconds.\n";
    cout << "Monte carlo amount of correct digits: " << monteCarloPiApproximator.findAmountCorrectDigitsOfPi() <<endl;
}

void testMachinsFormulaApproximation() {
    MachinsFormulaPiApproximation machinsFormulaPiApproximator(2000);
    auto start = chrono::high_resolution_clock::now();
    machinsFormulaPiApproximator.calculate(10);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;
    cout << "Execution time machins formula: " << duration.count() << " seconds.\n";
    cout << "Machins formula amount of correct digits: " << machinsFormulaPiApproximator.findAmountCorrectDigitsOfPi() << endl;
}
