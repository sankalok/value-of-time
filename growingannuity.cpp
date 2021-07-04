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
    FIXED_TIME = 4,
};

class GrowingAnnuity {
    public:
        double fixed_amount;
        double fixed_interest_rate;
        double fixed_growth_rate;
        int fixed_time;
};

void printGrowingAnnuityDetails(GrowingAnnuity a) {
    cout << setfill(' ') << fixed << setprecision(2);
    cout << "                 ======================================" << endl;
    cout << "                 ||  GROWING ANNUITY (IN CONTRACTS)  ||" << endl;
    cout << "                 ======================================" << endl;
    cout << "                     [INTEREST RATE IN PERCENTILE]" << endl;
    cout << "\n";
    cout << setw(15) << "FIXED AMOUNT" << setw(25) << "FIXED INTEREST RATE" << setw(25) << "FIXED GROWTH RATE" << setw(25) << "FIXED TIME IN YEARS" << endl;
    cout << setw(15) << a.fixed_amount << setw(25) << a.fixed_interest_rate << setw(25) << a.fixed_growth_rate << setw(25) << a.fixed_time << endl;
}

void closedFormGrowingAnnuity(GrowingAnnuity a) {
    auto begin = chrono::high_resolution_clock::now();

    cout << "\nCLOSED FORM GROWING ANNUITY: ";
    double cfga = 0.0;
    a.fixed_interest_rate /= PERCENTILE;
    a.fixed_growth_rate /= PERCENTILE;
    cfga =  (a.fixed_amount / (a.fixed_interest_rate - a.fixed_growth_rate)) * (1 - pow(1 + a.fixed_growth_rate, a.fixed_time) / pow(1 + a.fixed_interest_rate, a.fixed_time));
    cout << cfga << endl;

    auto end = chrono::high_resolution_clock::now();
    auto elapsed = chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cout << "EXECUTED IN: " << elapsed.count() * (1e-6) << " ms" << endl;

    cout << "\n";
}

void loopFormGrowingAnnuity(GrowingAnnuity a) {
    auto begin = chrono::high_resolution_clock::now();

    cout << "LOOP FORM GROWING ANNUITY: ";
    double lfga = 0.0;
    a.fixed_interest_rate /= PERCENTILE;
    a.fixed_growth_rate /= PERCENTILE;
    for(int i = 1; i <= a.fixed_time; i++) {
        lfga += a.fixed_amount * pow(1 + a.fixed_growth_rate, i - 1) / pow(1 + a.fixed_interest_rate, i);
    }
    cout << lfga << endl;

    auto end = chrono::high_resolution_clock::now();
    auto elapsed = chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cout << "EXECUTED IN: " << elapsed.count() * (1e-6) << " ms" << endl;

    cout << "\n";
}

int main(int argc, char* argv[]) {
    GrowingAnnuity a;
    a.fixed_amount = atof(argv[FIXED_AMOUNT]);
    a.fixed_interest_rate = atof(argv[FIXED_INTEREST_RATE]);
    a.fixed_interest_rate /= PERCENTILE;
    a.fixed_growth_rate = atof(argv[FIXED_GROWTH_RATE]);
    a.fixed_growth_rate /= PERCENTILE;
    a.fixed_time = atoi(argv[FIXED_TIME]);

    printGrowingAnnuityDetails(a);

    closedFormGrowingAnnuity(a);

    loopFormGrowingAnnuity(a);

    cout << "We have reached the end..." << endl;
}