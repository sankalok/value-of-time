#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <chrono>
#include <stdio.h>
#include <Windows.h>

using namespace std;

#define PERCENTILE 100

class IRR {
    public:
        double cashflow;
        int time;
};

void estimateInternalRateOfReturn(vector<IRR> irr_vector) {
    double internal_rate = 0.00;
    double absolute_difference = 0.00;
    double minimal_val = 0.0;
    
    cout << "\nEXECUTING SIMULATIONS ... FROM 0.0001 to 10.0000\n" << endl;

    auto begin = chrono::high_resolution_clock::now();

    for(double i = 0.0001; i <= 10.0000; i += 0.0001) {
        cout << "SIMULATION FOR " << i << " BEING RUN ..." << endl;
        minimal_val = irr_vector[0].cashflow;
        for(int j = 1; j < irr_vector.size(); j++) {
            minimal_val += (irr_vector[j].cashflow / pow(1 + i, irr_vector[j].time));
        }
        cout << "ABSOLUTE VALUE FOR THE SIMULATION CALCULATED AS: " << abs(minimal_val) << "\n" << endl;
        if(i == 0.0001) {
            absolute_difference = minimal_val;
        }
        else {
            if(abs(minimal_val) < absolute_difference) {
                absolute_difference = minimal_val;
                internal_rate = i;
            }
        }
    }

    cout << "NUMERICALLY ESTIMATED INTERNAL RATE OF RETURN: " << fixed << setprecision(4) << internal_rate << endl;

    auto end = chrono::high_resolution_clock::now();
    auto elapsed = chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cout << "EXECUTED IN: " << elapsed.count() * (1e-9) << " seconds" << endl;

    cout << "\n";
}

int main(int argc, char* argv[]) {
    vector<IRR> irr_vector;

    for(int i = 1; i <= argc - 1; i++) {
        IRR irr;
        irr.cashflow = atof(argv[i]);
        irr.time = (i - 1);
        irr_vector.push_back(irr);
    }

    estimateInternalRateOfReturn(irr_vector);

    cout << "We have reached the end..." << endl;
}