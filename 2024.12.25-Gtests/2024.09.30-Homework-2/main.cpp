// main.cpp
#include <gtest/gtest.h>
#include "Bank.h" // Assuming you have a BankAccount class

TEST(BankAccountTest, CreateAccount) {
    BankAccount account ("12345", "John Doe", 1000.0);
    EXPECT_EQ(account.GetAccountNumber(), "12345");
    EXPECT_EQ(account.GetAccountHolder(), "John Doe");
    EXPECT_EQ(account.GetBalance(), 1000.0);
}
/*
TEST(BankAccountTest, DepositAmount) {
    BankAccount account;
    account.createAccount(12345, "John Doe", 'S', 1000);
    account.deposit(500);
    EXPECT_EQ(account.getBalance(), 1500);
}

TEST(BankAccountTest, WithdrawAmount) {
    BankAccount account;
    account.createAccount(12345, "John Doe", 'S', 1000);
    account.withdraw(300);
    EXPECT_EQ(account.getBalance(), 700);
}

TEST(BankAccountTest, WithdrawMoreThanBalance) {
    BankAccount account;
    account.createAccount(12345, "John Doe", 'S', 1000);
    EXPECT_THROW(account.withdraw(1500), std::runtime_error);
}

TEST(BankAccountTest, BalanceInquiry) {
    BankAccount account;
    account.createAccount(12345, "John Doe", 'S', 1000);
    EXPECT_EQ(account.getBalance(), 1000);
}

TEST(BankAccountTest, ModifyAccountDetails) {
    BankAccount account;
    account.createAccount(12345, "John Doe", 'S', 1000);
    account.modifyAccountDetails("Jane Doe", 'C');
    EXPECT_EQ(account.getAccountHolderName(), "Jane Doe");
    EXPECT_EQ(account.getAccountType(), 'C');
}

TEST(BankAccountTest, CloseAccount) {
    BankAccount account;
    account.createAccount(12345, "John Doe", 'S', 1000);
    account.closeAccount();
    EXPECT_THROW(account.getBalance(), std::runtime_error);
}

TEST(BankAccountTest, InvalidAccountNumber) {
    BankAccount account;
    EXPECT_THROW(account.withdraw(100), std::runtime_error);
}

TEST(BankAccountTest, DepositNegativeAmount) {
    BankAccount account;
    account.createAccount(12345, "John Doe", 'S', 1000);
    EXPECT_THROW(account.deposit(-500), std::invalid_argument);
}
*/
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv); // Инициализация Google Test
    return RUN_ALL_TESTS(); // Запуск всех тестов
}