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

## 4. Calculating Annuity (A sequence of Cash Flows for a given number of years, say T periods into the future, while considering an Annuity paying a Fixed Amount X each period with a Spot Fixed Rate r)

Execute using:

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; `g++ -pedantic-errors -std=c++11 annuity.cpp -o annuity`

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; `./annuity 10000 3.5 10`

## ... Sample Output ... ##

<img src="vot_6.png" alt="vot_6" width = "800"/>

## 5. Calculating Growing Annuity (A sequence of Cash Flows for a given number of years, say T periods into the future, where each payment grows by a given factor each year) ##

Execute using:

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; `g++ -pedantic-errors -std=c++11 growingannuity.cpp -o growingannuity`

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; `./growingannuity 10000 6 3.5 10`

## ... Sample Output ... ##

<img src="vot_7.png" alt="vot_7" width = "1100"/>

## 6. Estimating the Internal Rate of Return for a series of inputted Cash Flows

Execute using:

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; `g++ -pedantic-errors -std=c++11 internalrateofreturn.cpp -o iror`

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; `./iror -110 10 100`

## ... Sample Output ... ##

<img src="vot_9.png" alt="vot_9" width = "800"/>

## ... ##

<img src="vot_10.png" alt="vot_10" width = "750"/>

## ... ##

<img src="vot_11.png" alt="vot_11" width = "750"/>

## ... ##

<img src="vot_12.png" alt="vot_12" width = "750"/>

### ~~ Sankalok Sen ~~ ###
