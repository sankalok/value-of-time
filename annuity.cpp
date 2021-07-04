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
    FIXED_TIME = 3,
};

class Annuity {
    public:
        double fixed_amount;
        double fixed_interest_rate;
        int fixed_time;
};

void printAnnuityDetails(Annuity a) {
    cout << setfill(' ') << fixed << setprecision(2);
    cout << "                 ==============================" << endl;
    cout << "                 ||  ANNUITY (IN CONTRACTS)  ||" << endl;
    cout << "                 ==============================" << endl;
    cout << "                 [INTEREST RATE IN PERCENTILE]" << endl;
    cout << "\n";
    cout << setw(20) << "FIXED AMOUNT" << setw(25) << "FIXED INTEREST RATE" << setw(25) << "FIXED TIME IN YEARS" << endl;
    cout << setw(20) << a.fixed_amount << setw(25) << a.fixed_interest_rate << setw(25) << a.fixed_time << endl;
}

void closedFormAnnuity(Annuity a) {
    auto begin = chrono::high_resolution_clock::now();

    cout << "\nCLOSED FORM ANNUITY: ";
    double cfa = 0.0;
    a.fixed_interest_rate /= PERCENTILE;
    cfa = (a.fixed_amount / a.fixed_interest_rate) * (1 - (1/pow(1 + a.fixed_interest_rate, a.fixed_time)));
    cout << cfa << endl;

    auto end = chrono::high_resolution_clock::now();
    auto elapsed = chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cout << "EXECUTED IN: " << elapsed.count() * (1e-6) << " ms" << endl;

    cout << "\n";
}

void loopFormAnnuity(Annuity a) {
    auto begin = chrono::high_resolution_clock::now();

    cout << "LOOP FORM ANNUITY: ";
    double lfa = 0.0;
    a.fixed_interest_rate /= PERCENTILE;
    for(int i = 1; i <= a.fixed_time; i++) {
        lfa += (a.fixed_amount / pow((1 + a.fixed_interest_rate), i));
    }
    cout << lfa << endl;

    auto end = chrono::high_resolution_clock::now();
    auto elapsed = chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cout << "EXECUTED IN: " << elapsed.count() * (1e-6) << " ms" << endl;

    cout << "\n";
}

int main(int argc, char* argv[]) {
    Annuity a;
    a.fixed_amount = atof(argv[FIXED_AMOUNT]);
    a.fixed_interest_rate = atof(argv[FIXED_RATE]);
    a.fixed_interest_rate /= PERCENTILE;
    a.fixed_time = atoi(argv[FIXED_TIME]);

    printAnnuityDetails(a);

    closedFormAnnuity(a);

    loopFormAnnuity(a);

    cout << "We have reached the end..." << endl;
}