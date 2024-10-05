// main.cpp
#include "Bank.h"

int main() {
    
    Bank myBank;

    BankAccount account1("123456", "BORIS", 500.0);
    BankAccount account2("654321", "IVAN", 1500.0);
    BankAccount account3("987654", "KATYA", 1000.0);

    
    myBank.AddAccount(account1);
    myBank.AddAccount(account2);
    myBank.AddAccount(account3);

    account1.Deposit(200);
    account2.Withdraw(8000);

    myBank.PrintAllAccounts();
    std::cout << "OBSHIY BALANCE: " << myBank.GetTotalBalance() << std::endl;

    return 0;
}