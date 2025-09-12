#include "../include/Bank.h"
#include "../include/SavingsAccount.h"
#include "../include/CheckingAccount.h"
#include <iostream>
#include <memory>
using namespace std;

int main() {
    Bank bank;

    auto acc1 = make_shared<SavingsAccount>(101, "Sai", 5000, 0.03);
    auto acc2 = make_shared<CheckingAccount>(102, "Ram", 3000, 1000);

    bank.addAccount(acc1);
    bank.addAccount(acc2);

    int choice;
    do {
        cout << "\n--- SmartBank Menu ---\n";
        cout << "1. Display Accounts\n2. Deposit\n3. Withdraw\n4. Transactions\n0. Exit\nChoice: ";
        cin >> choice;

        if (choice == 1) {
            bank.displayAccounts();
        } else if (choice == 2) {
            int acc; double amt;
            cout << "AccNo: "; cin >> acc;
            cout << "Amount: "; cin >> amt;
            bank.deposit(acc, amt);
        } else if (choice == 3) {
            int acc; double amt;
            cout << "AccNo: "; cin >> acc;
            cout << "Amount: "; cin >> amt;
            bank.withdraw(acc, amt);
        } else if (choice == 4) {
            bank.showTransactions();
        }
    } while (choice != 0);

    return 0;
}
