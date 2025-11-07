#ifndef BANK_H
#define BANK_H

#include <vector>
#include "Account.h"
#include "Transaction.h"
using namespace std;

class Bank {
    vector<Account*> accounts;
    vector<Transaction> transactions;

public:
    Bank();
    ~Bank();
    
    void addAccount(Account* acc);
    Account* findAccount(int accNo);
    void deposit(int accNo, double amount);
    void withdraw(int accNo, double amount);
    void displayAccounts() const;

    void logTransaction(int accNo, string type, double amount);
    void showTransactions() const;
    void addInterestToSavings();
};

#endif
