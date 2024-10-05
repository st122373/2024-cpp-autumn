// Bank.h
#ifndef BANK_H
#define BANK_H

#include <iostream>
#include <vector>
#include <string>

class BankAccount {
private:
    std::string accountNumber;
    double balance;
    std::string accountHolder;

public:
    BankAccount(const std::string& accountNumber, const std::string& accountHolder, double balance);
    BankAccount(const BankAccount& other);
    BankAccount(BankAccount&& other) noexcept;
    ~BankAccount();

    void Deposit(double amount);

    void Withdraw(double amount);

    double GetBalance() const;

    std::string GetAccountNumber() const;

    std::string GetAccountHolder() const;

    void PrintAccountInfo() const;
};

class Bank {
private:
    std::vector<BankAccount> accounts;

public:
    Bank() = default;
    Bank(const Bank& other) = default; // Конструктор копирования по умолчанию
    Bank(Bank&& other) noexcept = default; // Конструктор перемещения по умолчанию
    ~Bank() = default; // Деструктор

    void AddAccount(const BankAccount& account);

    double GetTotalBalance() const;

    void PrintAllAccounts() const;
};




#endif // BANK_H