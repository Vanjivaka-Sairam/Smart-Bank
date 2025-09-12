#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>
#include <iostream>
using namespace std;

class Account {
protected:
    int accountNumber;
    string holderName;
    double balance;

public:
    Account(int accNo, string name, double bal);
    virtual ~Account() {}

    int getAccountNumber() const;
    string getHolderName() const;
    double getBalance() const;

    virtual void deposit(double amount);
    virtual bool withdraw(double amount);
    virtual void display() const;

    virtual string getType() const = 0;
};

#endif
