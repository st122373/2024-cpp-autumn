// Bank.cpp
#include "Bank.h"

// BankAccount class

BankAccount::BankAccount(const std::string& accountNumber, const std::string& accountHolder, double balance)
    : accountNumber(accountNumber), accountHolder(accountHolder), balance(balance) {}

BankAccount::BankAccount(const BankAccount& other)
    : accountNumber(other.accountNumber), accountHolder(other.accountHolder), balance(other.balance) {}

BankAccount::BankAccount(BankAccount&& other) noexcept
    : accountNumber(std::move(other.accountNumber)), accountHolder(std::move(other.accountHolder)), balance(other.balance) {
}

BankAccount::~BankAccount() {}

void BankAccount::Deposit(double amount) 
{
    balance += amount;
}

void BankAccount::Withdraw(double amount) 
{
    if (amount <= balance) 
    {
        balance -= amount;
    } 
    else {
        std::cout << "Insufficient funds." << std::endl;
    }
}

double BankAccount::GetBalance() const {
    return balance;
}

std::string BankAccount::GetAccountNumber() const {
    return accountNumber;
}

std::string BankAccount::GetAccountHolder() const {
    return accountHolder;
}

void BankAccount::PrintAccountInfo() const {
    std::cout << "Account: " << accountNumber << ", Holder: " << accountHolder << ", Balance: " << balance << std::endl;
}

// Bank class

void Bank::AddAccount(const BankAccount& account) 
{
    accounts.push_back(account);
}

double Bank::GetTotalBalance() const {
    double total = 0;
    for (int i = 0; i < accounts.size(); ++i) {
        total += accounts[i].GetBalance();
    }
    return total;
}


void Bank::PrintAllAccounts() const
{
    for (int i = 0; i < accounts.size(); ++i) 
    {
        accounts[i].PrintAccountInfo(); 
    }
}
