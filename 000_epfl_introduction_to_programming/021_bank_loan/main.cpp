//
// Created by Florian Rey on 15/02/2023.
//

#include <iostream>

using namespace std;

int main() {
    double loan_amount;
    do {
        cout << "How much do you want to borrow from the bank? ";
        cin >> loan_amount;
    } while (loan_amount <= 0.);

    double monthly_repayment;
    do {
        cout << "How much do you want to pay back per month? ";
        cin >> monthly_repayment;
    } while (monthly_repayment <= 0.);

    double interest_rate;
    do {
        cout << "What is the interest rate in % ? ";
        cin >> interest_rate;
    } while (interest_rate <= 0. or interest_rate >= 100.);
    interest_rate /= 100;

    double remaining_amount(loan_amount), interest_sum(0.);
    int num_months(0);
    while (remaining_amount > 0) {
        interest_sum += remaining_amount * interest_rate;
        remaining_amount -= monthly_repayment;
        ++num_months;
    }

    cout << "The interest sum (collected on " << num_months << ") "
         << "is " << interest_sum
         << endl;

    return 0;
}