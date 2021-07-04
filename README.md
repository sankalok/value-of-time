# Value of Time

We calculate multiple scenarios **ignoring the Risk** while just considering the **Discrete Value of Time** for the following scenarios.

## 1. Calculating the Net Present Value with Discrete Compounding considering a Fixed Spot Rate

Execute using:

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; `g++ -pedantic-errors -std=c++11 pv_riskless_fcf_ft.cpp -o npv`

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; `./npv`

## ... Sample Output ... ##

<img src="vot_1.png" alt="vot_1" width = "600"/>

## 2. Calculating Perpetuity (Promise of a payment of a Fixed Amount X each period for the indefinite future with a Fixed Spot Rate) ##

Execute using:

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; `g++ -pedantic-errors -std=c++11 perpetuity.cpp -o perpetuity`

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; `./perpetuity 10000 7.5`

## ... Sample Output ... ##

<img src="vot_2.png" alt="vot_2" width = "600"/>

## ... ##

<img src="vot_3.png" alt="vot_3" width = "425"/>
