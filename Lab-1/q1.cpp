#include "iostream"
using namespace std;

class BankAccount // creating class
{
    double balance; // private var balance

public:
    BankAccount() : balance(0.0) {}                          // default contructor
    BankAccount(double balance) { this->balance = balance; } // param constructor
    BankAccount(const BankAccount &other)                    // copy constructor
    {
        this->balance = other.balance;
    }
    void displayBalance() // method to display balance
    {
        cout << "Balance: $" << balance << endl;
    }
    double deposit(int cash) // method to deposite cash
    {
        balance += cash; // cash increment to balance
        return balance;
    }
    double withdraw(int cash) // method to withdraw cash
    {
        if (balance >= cash) // if balance is less than cash req thean a warning instead of withdrawal
        {
            balance -= cash;
        }
        else
        {
            cout << "Insufficient Balance" << endl; // warning
        }
        return balance; // returns remaining balance
    }
};

int main()
{

    // demonstration of deep copy below

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