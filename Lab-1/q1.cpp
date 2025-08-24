/*
Q1. Suppose you are developing a bank account management system, and you have defined the
BankAccount class with the required constructors. You need to demonstrate the use of these
constructors in various scenarios.
1. Default Constructor Usage: Create a default-initialized BankAccount object named
account1. Print out the balance of account1.
2. Parameterized Constructor Usage: Create a BankAccount object named account2 with
an initial balance of $1000. Print out the balance of account2.
3. Copy Constructor Usage: Using the account2 you created earlier, create a new
BankAccount object named account3 using the copy constructor. Deduct $200 from
account3 and print out its balance. Also, print out the balance of account2 to ensure it
hasn't been affected by the transaction involving account3.
*/

#include "iostream"
using namespace std;

class BankAccount
{
protected:
    double balance;

public:
    BankAccount() : balance(0.0) {}
    BankAccount(double balance) { this->balance = balance; }
    BankAccount(const BankAccount &other)
    {
        this->balance = other.balance;
    }
    void displayBalance()
    {
        cout << "Balance: $" << balance << endl;
    }
    double deposit(int cash)
    {
        balance += cash;
        return balance;
    }
    double withdraw(int cash)
    {
        if (balance >= cash)
        {
            balance -= cash;
        }
        else
        {
            cout << "Insufficient Balance" << endl;
        }
        return balance;
    }
};

int main()
{

    BankAccount account1;

    cout << "Account #1 ";
    account1.displayBalance();

    BankAccount account2(1000);

    cout << "Account #2 ";
    account2.displayBalance();

    BankAccount account3 = account2;

    cout << "Account #3 ";
    account3.displayBalance();
    account3.withdraw(200);

    cout << "Account #3 ";
    account3.displayBalance();

    cout << "Account #2 ";
    account2.displayBalance();

    return 0;
}