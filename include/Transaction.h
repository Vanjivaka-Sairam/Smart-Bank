#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>
using namespace std;

struct Transaction {
    int accountNumber;
    string type;
    double amount;
    string timestamp;
};

#endif
