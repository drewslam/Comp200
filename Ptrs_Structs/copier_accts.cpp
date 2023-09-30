#include <iostream>
using namespace std;

// Problem Statement: We will illustrate the steps with the task of simulating a portion of the control logic for a departmental photocopier.
// A person making a copy enters a user number.
// There are 100 different users, with numbers 0 to 99.
// Each user is linked to a copy account, either the master account or one of ten project accounts.
// That linkage is maintained by the administrator, and it can change as users work on different projects.
// When copies are made, the appropriate account should be incremented.

// Main menu
// U)ser A)dministrator Q)uit
void Main_Menu(int& id, int& copies) {
    char userSelect;
    cout << "Select an option" << endl;
    cout << "U)ser A)dministrator Q)uit: ";
    cin >> userSelect;
    while (userSelect != 'U' && userSelect != 'u' &&
        userSelect != 'A' && userSelect != 'a' &&
        userSelect != 'Q' && userSelect != 'q') {
        cout << "Select an option" << endl;
        cout << "U)ser A)dministrator Q)uit: ";
        cin >> userSelect;
    }
    cout << "Enter an id number (0 - 99) and the number of copies: " << endl;
    cin >> id >> copies;
}

// Admin Menu
// B)alance M)aster P)roject
void Admin_Menu() {}

int main() {
    int* users[100];
    int id, copies;
    int master_account;
    int project_accounts[10];

    for (int i = 0; i < 100; i++) {
        users[i] = &master_account;
    }

    Main_Menu(id, copies);

    cout << id << " " << copies << endl;

    return 0;
}
