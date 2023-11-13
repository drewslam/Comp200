/// Andrew Souza
/// Comp 200 - Fall 2023
/// Inheritence Assignment
/// Problem 1
#include <iostream>
#include <sstream>
#include <string>
#include <cctype>
using namespace std;

/* Implement a base class Appointment and derived classes Onetime, Daily, Weekly, and Monthly.
 * An appointment has a description (for example, “see the dentist”) and a date and time.
 * Write a virtual function occurs on (int year, int month, int day)
 *   that checks whether the appointment occurs on that date.
 * For example, for a monthly appointment, you must check whether the day of the month matches.
 * Then fill a vector of Appointment* with a mixture of appointments.
 * Have the user enter a date and print out all appointments that happen on that
 * date. *

int Month_stoi(string month) {
    int monthInt = -1;
    if (month == "Jan") {
        monthInt = 1;
    } else if (month == "Feb") {
        monthInt = 2;
    } else if (month == "Mar") {
        monthInt = 3;
    } else if (month == "Apr") {
        monthInt = 4;
    } else if (month == "May") {
        monthInt = 5;
    } else if (month == "Jun") {
        monthInt = 6;
    } else if (month == "Jul") {
        monthInt = 7;
    } else if (month == "Aug") {
        monthInt = 8;
    } else if (month == "Sep") {
        monthInt = 9;
    } else if (month == "Oct") {
        monthInt = 10;
    } else if (month == "Nov") {
        monthInt = 11;
    } else if (month == "Dec") {
        monthInt = 12;
    } else {
        monthInt = -1;
    }

    return monthInt;
}

class Appointment {
public:
    Appointment() {
        this->description = "none";
        this->date = "Jan 1, 2023";
        this->time = "12:01AM";
    }
    Appointment(string description, string date, string time) {
        this->description = description;
        this->date = date;
        this->time = time;
    }
    void SetDescription(string input) {
        this->description = input;
    }
    void SetDate(string input) {
        this->date = input;
    }
    void SetTime(string input) {
        this->time = input;
    }
    string GetDescription() const {
        return this->description;
    }
    string GetDate() const {
        return this->date;
    }
    string GetTime() const {
        return this->time;
    }
    virtual bool checkDate(int year, int month, int day) {
        istringstream in(GetDate());
        int apptYear;
        string monthStr;
        int apptMonth;
        int apptDay;
        char hold;
        bool isMatch = false;

        in >> monthStr >> apptDay >> hold >> apptYear;
        apptMonth = Month_stoi(monthStr);

        if (apptYear == year && apptMonth == month && apptDay == day) {
            isMatch = true;
        }

        return isMatch;
    }
protected:
    string description;
    string date;
    string time;
};

class Onetime : public Appointment {};

class Daily : public Appointment {};

class Weekly : public Appointment {};

class Monthly : public Appointment {};

int main() {
    Appointment myAppt;
    string date;

    myAppt.SetDate("Nov 8, 2023");
    myAppt.SetDescription("Today");
    cout << myAppt.checkDate(2023, 11, 8) << endl;

    return 0;
}
