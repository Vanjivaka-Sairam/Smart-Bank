# Smart Bank System

A simple banking system implemented in C++ using object-oriented programming principles.

## 📋 Features

- **Account Management**
  - Create Savings and Checking accounts
  - Display all accounts with account type information
  - Account number, holder name, and balance tracking

- **Transactions**
  - Deposit money (with input validation)
  - Withdraw money (with overdraft support for checking accounts)
  - View complete transaction history with timestamps

- **Interest Calculation**
  - Add interest to all savings accounts
  - Interest rate: 3% (0.03) for savings accounts

- **Account Types**
  - **SavingsAccount**: No overdraft allowed, earns interest
  - **CheckingAccount**: Allows overdraft up to specified limit


## 🔧 Requirements

- C++ compiler (g++, clang++, or MSVC)
- Standard C++ library support

## 🚀 Compilation

### Linux/Mac (using g++)
```bash
g++ -o bank src/*.cpp -I include
```

### Windows (using MinGW)
```bash
g++ -o bank.exe src/*.cpp -I include
```

### Windows (using Visual Studio)
```bash
cl /EHsc src\*.cpp /I include /Fe:bank.exe
```

## ▶️ Running the Program

### Linux/Mac
```bash
./bank
```

### Windows
```bash
bank.exe
```

## 🎮 Usage

When you run the program, you'll see a menu with the following options:

```
--- SmartBank Menu ---
1. Display Accounts
2. Deposit
3. Withdraw
4. Transactions
5. Add Interest to Savings
0. Exit
Choice:
```

### Menu Options

1. **Display Accounts** - Shows all accounts with their details (account number, type, name, balance)

2. **Deposit** - Deposit money into an account
   - Enter account number
   - Enter amount (must be positive)

3. **Withdraw** - Withdraw money from an account
   - Enter account number
   - Enter amount (must be positive)
   - Checking accounts can withdraw up to balance + overdraft limit

4. **Transactions** - View all transaction history with timestamps

5. **Add Interest to Savings** - Applies interest to all savings accounts

0. **Exit** - Exit the program
