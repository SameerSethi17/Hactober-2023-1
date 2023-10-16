#include <iostream>
#include <vector>
#include <string>

// Class to represent a bank account
class BankAccount {
private:
    int accountNumber;
    std::string accountHolder;
    double balance;

public:
    BankAccount(int accNum, std::string holder, double initialBalance)
        : accountNumber(accNum), accountHolder(holder), balance(initialBalance) {}

    void showAccountDetails() {
        std::cout << "Account Number: " << accountNumber << std::endl;
        std::cout << "Account Holder: " << accountHolder << std::endl;
        std::cout << "Balance: $" << balance << std::endl;
    }

    void deposit(double amount) {
        balance += amount;
        std::cout << "Deposited $" << amount << " successfully." << std::endl;
    }

    void withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
            std::cout << "Withdrawn $" << amount << " successfully." << std::endl;
        } else {
            std::cout << "Insufficient balance." << std::endl;
        }
    }

    int getAccountNumber() {
        return accountNumber;
    }

    std::string getAccountHolder() {
        return accountHolder;
    }

    double getBalance() {
        return balance;
    }
};

// Function to search for an account by account number
BankAccount* searchAccount(int accNum, std::vector<BankAccount>& accounts) {
    for (BankAccount& account : accounts) {
        if (account.getAccountNumber() == accNum) {
            return &account;
        }
    }
    return nullptr;
}

int main() {
    std::vector<BankAccount> accounts;
    int choice;

    while (true) {
        std::cout << "\nBank Management System Menu" << std::endl;
        std::cout << "1. Open Account" << std::endl;
        std::cout << "2. Show Account Details" << std::endl;
        std::cout << "3. Deposit" << std::endl;
        std::cout << "4. Withdraw" << std::endl;
        std::cout << "5. Search Account" << std::endl;
        std::cout << "6. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                int accNum;
                std::string holder;
                double initialBalance;
                std::cout << "Enter Account Number: ";
                std::cin >> accNum;
                std::cout << "Enter Account Holder's Name: ";
                std::cin >> holder;
                std::cout << "Enter Initial Balance: ";
                std::cin >> initialBalance;
                accounts.push_back(BankAccount(accNum, holder, initialBalance));
                std::cout << "Account opened successfully." << std::endl;
                break;

            case 2:
                int searchAccNum;
                std::cout << "Enter Account Number to show details: ";
                std::cin >> searchAccNum;
                BankAccount* account = searchAccount(searchAccNum, accounts);
                if (account != nullptr) {
                    account->showAccountDetails();
                } else {
                    std::cout << "Account not found." << std::endl;
                }
                break;

            case 3:
                int depositAccNum;
                double depositAmount;
                std::cout << "Enter Account Number to deposit into: ";
                std::cin >> depositAccNum;
                account = searchAccount(depositAccNum, accounts);
                if (account != nullptr) {
                    std::cout << "Enter Deposit Amount: ";
                    std::cin >> depositAmount;
                    account->deposit(depositAmount);
                } else {
                    std::cout << "Account not found." << std::endl;
                }
                break;

            case 4:
                int withdrawAccNum;
                double withdrawAmount;
                std::cout << "Enter Account Number to withdraw from: ";
                std::cin >> withdrawAccNum;
                account = searchAccount(withdrawAccNum, accounts);
                if (account != nullptr) {
                    std::cout << "Enter Withdraw Amount: ";
                    std::cin >> withdrawAmount;
                    account->withdraw(withdrawAmount);
                } else {
                    std::cout << "Account not found." << std::endl;
                }
                break;

            case 5:
                int searchAccNum2;
                std::cout << "Enter Account Number to search: ";
                std::cin >> searchAccNum2;
                account = searchAccount(searchAccNum2, accounts);
                if (account != nullptr) {
                    account->showAccountDetails();
                } else {
                    std::cout << "Account not found." << std::endl;
                }
                break;

            case 6:
                std::cout << "Exiting the Bank Management System." << std::endl;
                return 0;

            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }

    return 0;
}
