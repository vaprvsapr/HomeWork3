#include <iostream>
#include <set>
#include <memory>


using namespace std;

class BankCell {
public:
    ~BankCell() {
        cout << "Bank cell has been deleted.";
    }
};

class Human {
private:
    string name;
    int age;
    shared_ptr<BankCell> bank_cell = nullptr;

public:
    Human(const string& n, const int& a) {
        name = n;
        age = a;
    }

    shared_ptr<BankCell> GetBankCellPointer() {
        return bank_cell;
    }

    void OpenBankCell() {
        bank_cell = make_shared<BankCell>();
        cout << name << " opens a new bank cell" << endl;
    }

    void JoinToBankCell(Human& h) {
        if(h.GetBankCellPointer() == nullptr) {
            cout << h.name << " doesn't have a bank cell." << endl;
        } else {
            this->bank_cell = h.GetBankCellPointer();
            cout << this->name << " joins to " << h.name << "'s bank cell" << endl;
        }
    }

    ~Human() {
        cout << "Human with name: " << name << " has died at the age of " << age << endl;
    }
};



int main() {
    {
        unique_ptr<Human> h1 = make_unique<Human>("Egor", 19);
        h1->OpenBankCell();

        {
            unique_ptr<Human> h2 = make_unique<Human>("Elena", 20);
            h2->JoinToBankCell(*h1);
        }
    }

}
