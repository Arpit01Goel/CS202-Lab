/**
 * @file problem1.cpp
 * @author Arpit01Goel
 * @date 2025/01/16 17:13:40
 */

#include <bits/stdc++.h>
using namespace std;

class Employee {
    public: 
    string name;
    int salary;
    Employee(string nm,int sl) {
        this->name = nm;
        this->salary = sl;
    }
    virtual void displayDetails() {
        cout << "Name: " << this->name << endl;
        cout << "Salary: " << this->salary << endl;
        cout << endl;
    }
    virtual ~Employee() {};
};

class Manager:public Employee {
    public:
    int team_size;
    int bonus;
    Manager(string nm,int sl,int tm,int bn): Employee(nm,sl) {
        this->team_size = tm;
        this->bonus = bn;
    }
    void displayDetails() override {
        cout << "Name: " << this->name << endl;
        cout << "Salary: " << this->salary << endl;
        cout << "Team size: " << this->team_size << endl;
        cout << "Bonus: " << this->bonus << endl;
        cout << endl;
    }
};

int main() {
    //example of object slicing
    Manager Ladybug("Marinette",1700,14,300);
    Ladybug.displayDetails();

    Employee CatNoir ("Adrien",1000);
    CatNoir.displayDetails();

    Employee MisterBug = Ladybug;
    MisterBug.displayDetails();

    Employee* hero = &Ladybug;
    hero->displayDetails();

    // Manager* villain = &CatNoir;

    return 0;
}

// GitHub: https://github.com/Arpit01Goel