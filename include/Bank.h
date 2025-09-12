#ifndef BANK_H
#define BANK_H

#include <vector>
#include <memory>
#include "Account.h"
#include "Transaction.h"
using namespace std;

class Bank {
    vector<shared_ptr<Account>> accounts;
    vector<Transaction> transactions;

public:
    void addAccount(shared_ptr<Account> acc);
    shared_ptr<Account> findAccount(int accNo);
    void deposit(int accNo, double amount);
    void withdraw(int accNo, double amount);
    void displayAccounts() const;

    void logTransaction(int accNo, string type, double amount);
    void showTransactions() const;
};

#endif
