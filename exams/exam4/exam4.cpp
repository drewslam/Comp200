/// Andrew Souza
/// Comp 200 -- Fall 2023
/// Exam 4
#include <iostream>

using namespace std;

// Implement a base class Person.
class Person {
private:
    // A person has a name and a birthday.
    string name;
    string birthday;
public:
    Person() {
        this->name = "none";
        this->birthday = "none";
    }
    Person(string name, string date) {
        this->name = name;
        this->birthday = date;
    }
    void SetName(string name) {
        this->name = name;
    }
    string GetName() const {
        return this->name;
    }
    void SetBirthday(string date) {
        this->birthday = date;
    }
    string GetBirthday() const {
        return this->birthday;
    }
    virtual void Print() const {
        cout << "--------------" << endl;
        cout << "Name: " << GetName() << endl;
        cout << "Birthday: " << GetBirthday() << endl;
    }
};

// Derive classes Student and Instructor from Person.
class Student : public Person {
private:
    // A student has a major
    string major;
public:
    Student() {
        SetName("none");
        SetBirthday("none");
        this->major = "none";
    }
    Student(string name, string date, string major) {
        SetName(name);
        SetBirthday(date);
        this->major = major;
    }
    void SetMajor(string major) {
        this->major = major;
    }
    string GetMajor() const {
        return this->major;
    }
    virtual void Print() const override {
        Person::Print();
        cout << "Occupation: Student" << endl;
        cout << "Major: " << GetMajor() << endl;
    }
};

class Instructor : public Person {
private:
    // An instructor has a salary
    int salary;
public:
    Instructor() {
        SetName("none");
        SetBirthday("none");
        this->salary = 0;
    }
    Instructor(string name, string date, int salary) {
        SetName(name);
        SetBirthday(date);
        this->salary = salary;
    }
    void SetSalary(int salary) {
        this->salary = salary;
    }
    int GetSalary() const {
        return this->salary;
    }
    virtual void Print() const override {
        Person::Print();
        cout << "Occupation: Instructor" << endl;
        cout << "Salary: " << GetSalary() << endl;
    }
};

int main() {
    // Also store in a dynamically allocated array of pointers a Person (in this case, it will be the Dean),
    // an instructor and multiple students.
    // Be sure to ask the user how many students are in the class when making the array of pointers. */
    int inputNumStudents = -1;
    string name;
    string date;
    int salary = -1;

    cout << "How many students are in the course?" << endl;
    cin >> inputNumStudents;

    Person** Dean = new Person*[inputNumStudents + 1]; // Allocates an array of inputNumStudents students and 1 teacher

    cin.ignore();

    cout << "Enter Instructor's Name" << endl;
    getline(cin, name);
    cout << "Enter Instructor's Birthday (Month Year)" << endl;
    getline(cin, date);
    cout << "Enter Instructor's Salary" << endl;
    cin >> salary;

    Instructor* Teacher = new Instructor(name, date, salary);
    Dean[0] = Teacher;

    cin.ignore();
    for (int i = 1; i <= inputNumStudents; i++) {
        string major;
        cout << "Enter Student's Name" << endl;
        getline(cin, name);
        cout << "Enter Student's Birthday" << endl;
        getline(cin, date);
        cout << "Enter Student's Major" << endl;
        getline(cin, major);
        Student* student =  new Student(name, date, major);
        Dean[i] = student;
    }

    cout << endl;

    for (int i = 0; i <= inputNumStudents; i++) {
        Dean[i]->Print();
        cout << endl;
    }

    delete[] Dean;

    return 0;
}
