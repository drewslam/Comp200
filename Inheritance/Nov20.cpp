#include <iostream>

using namespace std;

// Athlete base class
class Athlete {
public:
    Athlete() {
        this->name = "none";
        this->number = 0;
    }
    void SetName(string name) {
        this->name = name;
    }
    void SetNumber(int number) {
        this->number = number;
    }
    string GetName() const {
        return this->name;
    }
    int GetNumber() const {
        return this->number;
    }
    // virtual print function
    virtual void PrintStats() const {
        cout << "Name: " << this->name << endl;
        cout << "Number: " << this->number << endl;
    }
private:
    string name;
    int number;
};

// Baseball player -- RBI, Homeruns, Struck Out
class BaseballPlayer : public Athlete {
public:
    BaseballPlayer() {
        this->RBIs = 0;
        this->homeRuns = 0;
        this->struckOut = 0;
    }
    void SetRBIs(int rbi) {
        this->RBIs = rbi;
    }
    void SetHomeRuns(int homeRuns) {
        this->homeRuns = homeRuns;
    }
    void SetStruckOut(int struckOut) {
        this->struckOut = struckOut;
    }
    int GetRBIs() const {
        return this->RBIs;
    }
    int GetHomeRuns() const {
        return this->homeRuns;
    }
    int GetStruckOut() const {
        return this->struckOut;
    }
    virtual void PrintStats() const override {
        Athlete::PrintStats();
        cout << "RBI: " << this->RBIs << endl;
        cout << "Home Runs: " << this->homeRuns << endl;
        cout << "Struck Out: " << this->struckOut << endl;
    }
private:
    int RBIs;
    int homeRuns;
    int struckOut;
};

// Football player -- Touchdowns, Yards, Interceptions
class FootballPlayer : public Athlete {
public:
    FootballPlayer() {
        this->touchdowns = 0;
        this->interceptions = 0;
        this->yards = 0;
    }
    void SetTouchdowns(int touchdowns) {
        this->touchdowns = touchdowns;
    }
    void SetInterceptions(int interceptions) {
        this->interceptions = interceptions;
    }
    void SetYards(int yards) {
        this->yards = yards;
    }
    int GetTouchdowns() const {
        return this->touchdowns;
    }
    int GetInterceptions() const {
        return this->interceptions;
    }
    int GetYards() const {
        return this->yards;
    }
    virtual void PrintStats() const override {
        Athlete::PrintStats();
        cout << "Touchdowns: " << this->touchdowns << endl;
        cout << "Interceptions: " << this->interceptions << endl;
        cout << "Yards Run: " << this->yards << endl;
    }
private:
    int touchdowns;
    int interceptions;
    int yards;
};

// Basketball player -- 2 pointers, 3 pointers
class BasketballPlayer : public Athlete {
public:
    BasketballPlayer() {
        this->twoPointers = 0;
        this->threePointers = 0;
    }
    void Set2Pointers(int scores) {
        this->twoPointers = scores;
    }
    void Set3Pointers(int scores) {
        this->threePointers = scores;
    }
    int Get2Pointers() const {
        return this->twoPointers;
    }
    int Get3Pointers() const {
        return this->threePointers;
    }
    virtual void PrintStats() const override {
        Athlete::PrintStats();
        cout << "2 Pointers: " << this->twoPointers << endl;
        cout << "3 Pointers: " << this->threePointers << endl;
    }
private:
    int twoPointers;
    int threePointers;
};

int main() {
    int numAthletes;
    char userSport = 'a';
    string playerName;
    int playerNum;
    int userNum;

    cout << "How many athletes would you like to add?" << endl;
    cin >> numAthletes;
    Athlete** roster = new Athlete*[numAthletes];

    for (int i = 0; i < numAthletes; i++) {
        while (userSport != 'f' && userSport != 'e' && userSport != 'k') {
            cout << "Enter f for football, e for baseball, or k for basketball: ";
            cin >> userSport;
        }
        cin.ignore();
        if (userSport == 'f') {
                FootballPlayer* fbp = new FootballPlayer;
                cout << "Name: ";
                getline(cin, playerName);
                fbp->SetName(playerName);
                cout << "Number: ";
                cin >> playerNum;
                fbp->SetNumber(playerNum);
                cout << "Touchdowns: ";
                cin >> userNum;
                fbp->SetTouchdowns(userNum);
                cout << "Interceptions: ";
                cin >>userNum;
                fbp->SetInterceptions(userNum);
                cout << "Yards Run: ";
                cin >>userNum;
                fbp->SetYards(userNum);
                roster[i] = fbp;
        } else if (userSport == 'e') {
                BaseballPlayer* bsp = new BaseballPlayer;
                cout << "Name: ";
                getline(cin, playerName);
                bsp->SetName(playerName);
                cout << "Number: ";
                cin >> playerNum;
                bsp->SetNumber(playerNum);
                cout << "RBIs: ";
                cin >> userNum;
                bsp->SetRBIs(userNum);
                cout << "Home Runs: ";
                cin >>userNum;
                bsp->SetHomeRuns(userNum);
                cout << "Struck Out: ";
                cin >>userNum;
                bsp->SetStruckOut(userNum);
                roster[i] = bsp;
        } else {
                BasketballPlayer* bkp = new BasketballPlayer;
                cout << "Name: ";
                getline(cin, playerName);
                bkp->SetName(playerName);
                cout << "Number: ";
                cin >> playerNum;
                bkp->SetNumber(playerNum);
                cout << "2 Pointers: ";
                cin >> userNum;
                bkp->Set2Pointers(userNum);
                cout << "3 Pointers: ";
                cin >>userNum;
                bkp->Set3Pointers(userNum);
                roster[i] = bkp;
        }
    }

    for (int i = 0; i < numAthletes; i++) {
        cout << "----------" << endl;
        roster[i]->PrintStats();
        cout << endl;
    }

    delete[] roster;

    return 0;
}
