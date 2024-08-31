// in this approach i will try to solve the problem in the brute force way which is the way
// we use in our daily life which is simple to understand and implement
// so what we do here is that if a person A has given the money in place of some group of people 
// then he should get that amount from that group of people so the balance should be 
// (- amount paid) similarly the amount for each is added in their accounts as +ve value
#include <bits/stdc++.h>
using namespace std;

class Manager {
public:
    string name;
    double balance;

    Manager(string name_) {
        name = name_;
        balance = 0;
    }
    
    void addAmount(double amount) {
        balance += amount;
    }

    void subtractAmount(double amount) {
        balance -= amount;
    }

    double getBalance() const {
        return balance;
    }
};

int main() {
    cout << "Welcome to the program: " << endl << endl;
    cout << "How many people are there in your group whose expenses you want to manage: ";
    int number_of_people;
    cin >> number_of_people;
    cout << endl;

    vector<Manager> people;
    for (int i = 0; i < number_of_people; ++i) {
        cout << "Enter the name of person " << i + 1 << ": ";
        string name;
        cin >> name;
        people.push_back(Manager(name));
    }
    cout << endl;

    cout << "Accounts for " << number_of_people << " people have been created successfully!" << endl << endl;

    while (true) {
        cout << "Functionalities: " << endl;
        cout << "1. Add Transaction" << endl;
        cout << "2. Remove a Transaction" << endl;
        cout << "3. End Current Session" << endl;
        cout << "4. End and Settle Up" << endl;
        int options;
        cout << "Choose a functionality that you want to use: ";
        cin >> options;

        if (options == 1) {
            cout << "Enter the name of the person who paid: ";
            string payer;
            cin >> payer;

            cout << "Enter the amount paid: ";
            double amount;
            cin >> amount;

            cout << "Enter the number of people sharing this expense (including the payer): ";
            int share_count;
            cin >> share_count;

            vector<string> participants;
            cout << "Enter the names of the participants: ";
            for (int i = 0; i < share_count; i++) {
                string participant;
                cin >> participant;
                participants.push_back(participant);
            }

            double individual_share = amount / share_count;
            for (Manager &person : people) {
                if (person.name == payer) {
                    person.subtractAmount(amount);
                }
                for (const string &participant : participants) {
                    if (person.name == participant) {
                        person.addAmount(individual_share);
                    }
                }
            }

            cout << "Transaction added successfully!" << endl << endl;

        } 
        else if (options == 2) {
            // will make it
            cout << "Remove Transaction functionality is not implemented in this example." << endl << endl;

        } 
        else if (options == 3) {
            // will make it
            cout << "Ending current session. All data will be preserved for future use." << endl;
            break;

        } 
        else if (options == 4) {
            // End and settle up
            cout << "Settling up..." << endl;

            for (Manager &person : people) {
                if (person.getBalance() > 0) {
                    cout << person.name << " should receive " << person.getBalance() << " units." << endl;
                } 
                else if (person.getBalance() < 0) {
                    cout << person.name << " owes " << -person.getBalance() << " units." << endl;
                } 
                else {
                    cout << person.name << " is settled up." << endl;
                }
            }

            cout << "All transactions settled. Ending session." << endl;
            break;

        } 
        else {
            cout << "Invalid option. Please try again." << endl << endl;
        }
    }

    return 0;
}
