#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H

#include "Account.h"
using namespace std;

class SavingsAccount : public Account {
    double interestRate;

public:
    SavingsAccount(int accNo, string name, double bal, double rate);

    void addInterest();
    bool withdraw(double amount) override;
    string getType() const override;
};

#endif
