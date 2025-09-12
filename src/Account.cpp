#include "../include/Account.h"
using namespace std;

Account::Account(int accNo, string name, double bal)
    : accountNumber(accNo), holderName(name), balance(bal) {}

int Account::getAccountNumber() const { return accountNumber; }
string Account::getHolderName() const { return holderName; }
double Account::getBalance() const { return balance; }

void Account::deposit(double amount) {
    balance += amount;
}

bool Account::withdraw(double amount) {
    if (amount > balance) return false;
    balance -= amount;
    return true;
}

void Account::display() const {
    cout << "Account: " << accountNumber << " | Name: " << holderName
         << " | Balance: " << balance << endl;
}
