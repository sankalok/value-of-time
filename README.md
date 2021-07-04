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

## 3. Calculating Growing Perpetuity (An infinite sequence of cashflows, where the payment the first year is Fixed Amount X and each consequent payment grows by a constant rate) ##

Execute using:

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; `g++ -pedantic-errors -std=c++11 growingperpetuity.cpp -o growingperpetuity`

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; `./growingperpetuity 10000 5.5 2.5`

## ... Sample Output ... ##

<img src="vot_4.png" alt="vot_4" width = "800"/>

## ... ##

<img src="vot_5.png" alt="vot_5" width = "350"/>
