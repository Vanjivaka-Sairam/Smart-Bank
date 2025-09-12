#include "../include/Bank.h"
#include <ctime>
using namespace std;

void Bank::addAccount(shared_ptr<Account> acc) {
    accounts.push_back(acc);
}

shared_ptr<Account> Bank::findAccount(int accNo) {
    for (auto &acc : accounts)
        if (acc->getAccountNumber() == accNo) return acc;
    return nullptr;
}

void Bank::deposit(int accNo, double amount) {
    auto acc = findAccount(accNo);
    if (acc) {
        acc->deposit(amount);
        logTransaction(accNo, "Deposit", amount);
    } else {
        cout << "Account not found!" << endl;
    }
}

void Bank::withdraw(int accNo, double amount) {
    auto acc = findAccount(accNo);
    if (acc && acc->withdraw(amount)) {
        logTransaction(accNo, "Withdraw", amount);
    } else {
        cout << "Insufficient funds or account not found!" << endl;
    }
}

void Bank::displayAccounts() const {
    for (auto &acc : accounts) acc->display();
}

void Bank::logTransaction(int accNo, string type, double amount) {
    Transaction t{accNo, type, amount, to_string(time(nullptr))};
    transactions.push_back(t);
}

void Bank::showTransactions() const {
    for (auto &t : transactions)
        cout << "AccNo: " << t.accountNumber << " | " << t.type
             << " | Amount: " << t.amount << " | Time: " << t.timestamp << endl;
}
