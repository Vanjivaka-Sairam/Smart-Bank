#include "../include/Bank.h"
#include "../include/SavingsAccount.h"
#include "../include/CheckingAccount.h"
#include <iostream>
using namespace std;

int main() {
    Bank bank;

    SavingsAccount* acc1 = new SavingsAccount(101, "Sai", 5000, 0.03);
    CheckingAccount* acc2 = new CheckingAccount(102, "Ram", 3000, 1000);

    bank.addAccount(acc1);
    bank.addAccount(acc2);

    int choice;
    do {
        cout << "\n--- SmartBank Menu ---\n";
        cout << "1. Display Accounts\n2. Deposit\n3. Withdraw\n4. Transactions\n5. Add Interest to Savings\n0. Exit\nChoice: ";
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
        } else if (choice == 5) {
            bank.addInterestToSavings();
            cout << "Interest added to all savings accounts!" << endl;
        }
    } while (choice != 0);

    return 0;
}
