#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>

using namespace std;

#define PERCENTILE 100

class FuturePayments {
    public:
        double cashflow;
        int time;
};

void printNetCashFlows(vector<FuturePayments> future_payments) {
    cout << setfill(' ') << fixed << setprecision(2);
    cout << "                 ======================" << endl;
    cout << "                 ||  NET CASH FLOWS  ||" << endl;
    cout << "                 ======================" << endl;
    cout << setw(15) << "YEAR" << setw(30) << "NET_CASH_FLOW_FOR_YEAR" << endl;
    for(int i = 0; i < future_payments.size(); i++) {
        cout << setw(15) << future_payments[i].time << setw(30) << future_payments[i].cashflow << endl;
    }
}

void calculateNetPresentValue(double investment_cost, double spot_rate, int number_of_year, vector<FuturePayments> future_payments) {
    double net_present_value = 0.0;

    net_present_value -= investment_cost;

    for(int i = 0; i < future_payments.size(); i++) {
        net_present_value += (future_payments[i].cashflow)/(pow(1 + (spot_rate / PERCENTILE), future_payments[i].time));
    }
    
    cout << "\nNET PRESENT VALUE: " << net_present_value;

    if(net_present_value >= 0) {
        cout << " (POSITIVE)\n" << endl;
    }
    else {
        cout << " (NEGATIVE)\n" << endl;
    }
}

int main(int argc, char* argv[]) {
    double investment_cost = 0.0;
    double spot_rate = 0.0;
    int number_of_years = 0;

    cout << "Enter Present Investment Cost: ";
    cin >> investment_cost;

    cout << "Enter the Spot Rate under the Flat Term Structure: ";
    cin >> spot_rate;

    cout << "Enter Number of Years: ";
    cin >> number_of_years;

    vector<FuturePayments> future_payments;
    cout << "Enter the Net Cash Flows: " << endl;
    for(int i = 1; i <= number_of_years; i++) {
        FuturePayments fp;
        cout << "Year " << i << ": ";
        cin >> fp.cashflow;
        fp.time = i;
        future_payments.push_back(fp);
    }

    printNetCashFlows(future_payments);

    calculateNetPresentValue(investment_cost, spot_rate, number_of_years, future_payments);

    cout << "We have reached the end..." << endl;
}