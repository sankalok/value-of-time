#include <iostream>
#include <iomanip>
#include <cmath>
#include <chrono>
#include <stdio.h>
#include <Windows.h>

using namespace std;

#define PERCENTILE 100

enum inputs {
    FIXED_AMOUNT = 1,
    FIXED_RATE = 2,
};

class Perpetuity {
    public:
        double fixed_amount;
        double fixed_interest_rate;
};

void printPerpetuityDetails(Perpetuity p) {
    cout << setfill(' ') << fixed << setprecision(2);
    cout << "                 =================================" << endl;
    cout << "                 ||  PERPETUITY (IN CONTRACTS)  ||" << endl;
    cout << "                 =================================" << endl;
    cout << "                   [INTEREST RATE IN PERCENTILE]" << endl;
    cout << "\n";
    cout << setw(28) << "FIXED AMOUNT" << setw(25) << "FIXED INTEREST RATE" << endl;
    cout << setw(28) << p.fixed_amount << setw(25) << p.fixed_interest_rate << endl;
}

void closedFormPerpetuity(Perpetuity p) {
    cout << "\nCLOSED FORM INFINITE PERPETUITY: " << (p.fixed_amount / p.fixed_interest_rate) << endl;
    cout << "\n";
}

void infiniteFormPerpetuity(Perpetuity p, int iterations) {
    auto begin = chrono::high_resolution_clock::now();

    cout << "[OVER " << iterations << " ITERATIONS]: ";

    double ifp = 0.0;
    for(int i = 1; i <= iterations; i++) {
        ifp += (p.fixed_amount / pow((1 + p.fixed_interest_rate), i));
    }
    cout << ifp << endl;

    auto end = chrono::high_resolution_clock::now();
    auto elapsed = chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cout << "EXECUTED IN: " << elapsed.count() * (1e-6) << " ms" << endl;

    cout << "\n";
}

int main(int argc, char* argv[]) {
    Perpetuity p;
    p.fixed_amount = atof(argv[FIXED_AMOUNT]);
    p.fixed_interest_rate = atof(argv[FIXED_RATE]);
    p.fixed_interest_rate /= PERCENTILE;

    printPerpetuityDetails(p);

    closedFormPerpetuity(p);

    cout << "INFINITE FORM PERPETUITY SIMULATIONS\n" << endl;

    Sleep(500);
    infiniteFormPerpetuity(p, 10);
    Sleep(500);
    infiniteFormPerpetuity(p, 15);
    Sleep(500);
    infiniteFormPerpetuity(p, 20);
    Sleep(500);
    infiniteFormPerpetuity(p, 25);
    Sleep(500);
    infiniteFormPerpetuity(p, 30);
    Sleep(500);
    infiniteFormPerpetuity(p, 35);
    Sleep(500);
    infiniteFormPerpetuity(p, 40);
    Sleep(500);
    infiniteFormPerpetuity(p, 45);
    Sleep(500);
    infiniteFormPerpetuity(p, 50);
    Sleep(500);
    infiniteFormPerpetuity(p, 75);
    Sleep(500);
    infiniteFormPerpetuity(p, 150);
    Sleep(500);
    infiniteFormPerpetuity(p, 300);
    Sleep(500);
    infiniteFormPerpetuity(p, 500);
    Sleep(500);
    infiniteFormPerpetuity(p, 1000);
    Sleep(500);
    infiniteFormPerpetuity(p, 10000);
    Sleep(500);

    cout << "We have reached the end..." << endl;
}