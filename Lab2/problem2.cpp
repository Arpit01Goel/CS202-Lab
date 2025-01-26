/**
 * @file problem2.cpp
 * @author Arpit01Goel
 * @date 2025/01/16 17:55:19
 */

#include <bits/stdc++.h>
using namespace std;
class BankAccount {
    private:
    string Account_number;
    double balance;
    public:
    BankAccount(string no,double bal) {
        this->Account_number = no;
        this->balance = bal;
    }
    void display() {
        cout << "Account: " << Account_number << " Balance : " << balance<< endl;
        // cout << endl;
    }
    friend void transfer(BankAccount &from, BankAccount &to, double amount) ;
    
};
void transfer(BankAccount &from, BankAccount &to, double amount) {
        if (amount<0) {
            cout << "amount must be positive" << endl;
            return;
        }
        if (from.balance < amount) {
            cout << "insufficient balance" << endl;
            return;
        }
        from.balance -= amount;
        to.balance += amount;
        cout << "Transfer successful" << endl;
        from.display();
        to.display();
        cout << endl;
        return;
    }
int main() {
    BankAccount *person1 = new BankAccount("123",1000);
    BankAccount *person2 = new BankAccount("321",1000);

    person1->display();
    cout << endl;
    person2->display();
    cout << endl;

    // 1 give money to 2
    transfer(*person1,*person2,(double)500);

    //2 gives money to 1
    transfer(*person2 , *person1 , (double) 1000);

    // person1 have to give more than his account
    transfer(*person1 , *person2 , (double) 10000);
    
    //amount is -ve
    transfer(*person1 , *person2 , (double) -1000);

    
    return 0;
}

// GitHub: https://github.com/Arpit01Goel