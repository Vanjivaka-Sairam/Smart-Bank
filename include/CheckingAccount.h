#ifndef CHECKINGACCOUNT_H
#define CHECKINGACCOUNT_H

#include "Account.h"
using namespace std;

class CheckingAccount : public Account {
    double overdraftLimit;

public:
    CheckingAccount(int accNo, string name, double bal, double overdraft);

    bool withdraw(double amount) override;
    string getType() const override;
};

#endif
