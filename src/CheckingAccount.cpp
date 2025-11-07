#include "../include/CheckingAccount.h"
using namespace std;

CheckingAccount::CheckingAccount(int accNo, string name, double bal, double overdraft)
    : Account(accNo, name, bal), overdraftLimit(overdraft) {
}

bool CheckingAccount::withdraw(double amount) {
    if (amount > balance + overdraftLimit) return false;
    balance -= amount;
    return true;
}

string CheckingAccount::getType() const {
    return "Checking";
}
