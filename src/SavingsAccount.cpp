#include "../include/SavingsAccount.h"
using namespace std;

SavingsAccount::SavingsAccount(int accNo, string name, double bal, double rate)
    : Account(accNo, name, bal), interestRate(rate) {}

void SavingsAccount::addInterest() {
    balance += balance * interestRate;
}

bool SavingsAccount::withdraw(double amount) {
    if (amount > balance) return false;
    balance -= amount;
    return true;
}

string SavingsAccount::getType() const {
    return "Savings";
}
