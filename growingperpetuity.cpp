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
    FIXED_INTEREST_RATE = 2,
    FIXED_GROWTH_RATE = 3,
};

class GrowingPerpetuity {
    public:
        double fixed_amount;
        double fixed_interest_rate;
        double fixed_growth_rate;
};

void printPerpetuityDetails(GrowingPerpetuity p) {
    cout << setfill(' ') << fixed << setprecision(4);
    cout << "                 =========================================" << endl;
    cout << "                 ||  GROWING PERPETUITY (IN CONTRACTS)  ||" << endl;
    cout << "                 =========================================" << endl;
    cout << "                  [INTEREST AND GROWTH RATE IN PERCENTILE]" << endl;
    cout << "\n";
    cout << setw(28) << "FIXED AMOUNT" << setw(25) << "FIXED INTEREST RATE" << setw(25) << "FIXED GROWTH RATE" << endl;
    cout << setw(28) << p.fixed_amount << setw(25) << p.fixed_interest_rate << setw(25) << p.fixed_growth_rate << endl;
}

void closedFormGrowthPerpetuity(GrowingPerpetuity p) {
    double cfgp = 0.0;
    cfgp = (p.fixed_amount / (p.fixed_interest_rate - p.fixed_growth_rate));
    cout << "\nCLOSED FORM INFINITE GROWTH PERPETUITY: " << cfgp << endl;
    cout << "\n";
}

void infiniteFormGrowthPerpetuity(GrowingPerpetuity p, int iterations) {
    auto begin = chrono::high_resolution_clock::now();

    cout << "[OVER " << iterations << " ITERATIONS]: ";

    double ifgp = 0.0;
    for(int i = 1; i <= iterations; i++) {
        ifgp += (p.fixed_amount * pow(1 + p.fixed_growth_rate, i - 1)) / pow(1 + p.fixed_interest_rate, i);
    }
    cout << ifgp << endl;

    auto end = chrono::high_resolution_clock::now();
    auto elapsed = chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cout << "EXECUTED IN: " << elapsed.count() * (1e-6) << " ms" << endl;

    cout << "\n";
}

int main(int argc, char* argv[]) {
    GrowingPerpetuity p;
    p.fixed_amount = atof(argv[FIXED_AMOUNT]);
    p.fixed_interest_rate = atof(argv[FIXED_INTEREST_RATE]);
    p.fixed_interest_rate /= PERCENTILE;
    p.fixed_growth_rate = atof(argv[FIXED_GROWTH_RATE]);
    p.fixed_growth_rate /= PERCENTILE;

    printPerpetuityDetails(p);

    closedFormGrowthPerpetuity(p);

    cout << "INFINITE FORM GROWTH PERPETUITY SIMULATIONS\n" << endl;

    Sleep(1000);
    infiniteFormGrowthPerpetuity(p, 10);
    Sleep(1000);
    infiniteFormGrowthPerpetuity(p, 15);
    Sleep(1000);
    infiniteFormGrowthPerpetuity(p, 20);
    Sleep(1000);
    infiniteFormGrowthPerpetuity(p, 25);
    Sleep(1000);
    infiniteFormGrowthPerpetuity(p, 30);
    Sleep(1000);
    infiniteFormGrowthPerpetuity(p, 35);
    Sleep(1000);
    infiniteFormGrowthPerpetuity(p, 40);
    Sleep(1000);
    infiniteFormGrowthPerpetuity(p, 45);
    Sleep(1000);
    infiniteFormGrowthPerpetuity(p, 50);
    Sleep(1000);
    infiniteFormGrowthPerpetuity(p, 75);
    Sleep(1000);
    infiniteFormGrowthPerpetuity(p, 150);
    Sleep(1000);
    infiniteFormGrowthPerpetuity(p, 300);
    Sleep(1000);
    infiniteFormGrowthPerpetuity(p, 500);
    Sleep(1000);
    infiniteFormGrowthPerpetuity(p, 1000);
    Sleep(1000);
    infiniteFormGrowthPerpetuity(p, 10000);
    Sleep(1000);

    cout << "We have reached the end..." << endl;
}