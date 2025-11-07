#include "../include/Bank.h"
#include "../include/SavingsAccount.h"
#include <iostream>
#include <ctime>
#include <sstream>
#include <iomanip>
using namespace std;

Bank::Bank() {
}

Bank::~Bank() {
    for (int i = 0; i < accounts.size(); i++) {
        delete accounts[i];
    }
    accounts.clear();
}

void Bank::addAccount(Account* acc) {
    accounts.push_back(acc);
}

Account* Bank::findAccount(int accNo) {
    for (int i = 0; i < accounts.size(); i++) {
        if (accounts[i]->getAccountNumber() == accNo) {
            return accounts[i];
        }
    }
    return nullptr;
}

void Bank::deposit(int accNo, double amount) {
    if (amount <= 0) {
        cout << "Invalid amount! Amount must be positive." << endl;
        return;
    }
    Account* acc = findAccount(accNo);
    if (acc) {
        acc->deposit(amount);
        logTransaction(accNo, "Deposit", amount);
    } else {
        cout << "Account not found!" << endl;
    }
}

void Bank::withdraw(int accNo, double amount) {
    if (amount <= 0) {
        cout << "Invalid amount! Amount must be positive." << endl;
        return;
    }
    Account* acc = findAccount(accNo);
    if (acc && acc->withdraw(amount)) {
        logTransaction(accNo, "Withdraw", amount);
    } else {
        cout << "Insufficient funds or account not found!" << endl;
    }
}

void Bank::displayAccounts() const {
    for (int i = 0; i < accounts.size(); i++) {
        accounts[i]->display();
    }
}

void Bank::logTransaction(int accNo, string type, double amount) {
    time_t now = time(nullptr);
    tm* timeinfo = localtime(&now);
    stringstream ss;
    ss << put_time(timeinfo, "%Y-%m-%d %H:%M:%S");
    Transaction t;
    t.accountNumber = accNo;
    t.type = type;
    t.amount = amount;
    t.timestamp = ss.str();
    transactions.push_back(t);
}

void Bank::showTransactions() const {
    for (int i = 0; i < transactions.size(); i++) {
        cout << "AccNo: " << transactions[i].accountNumber << " | " << transactions[i].type
             << " | Amount: " << transactions[i].amount << " | Time: " << transactions[i].timestamp << endl;
    }
}

void Bank::addInterestToSavings() {
    for (int i = 0; i < accounts.size(); i++) {
        if (accounts[i]->getType() == "Savings") {
            SavingsAccount* savingsAcc = dynamic_cast<SavingsAccount*>(accounts[i]);
            if (savingsAcc) {
                double balanceBefore = accounts[i]->getBalance();
                savingsAcc->addInterest();
                double interestAmount = accounts[i]->getBalance() - balanceBefore;
                logTransaction(accounts[i]->getAccountNumber(), "Interest", interestAmount);
            }
        }
    }
}
