/// Andrew Souza
/// Comp 200 -- Fall 2023
/// Pointers and Structs Lab

#include <iostream>
using namespace std;

/* Define a structure Student with a first name,
 * last name, and course grade (A, B, C, D, or F).
 * Write a program that reads input in which each line
 * has the first and last name and course grade, separated by spaces.
 * Upon reading the input, your program should print all students with grade A,
 * then all students with grade B, and so on.*/

// Define a struct Students with the properties firstName, lastName, and courseGrade
struct Student {
    string firstName;
    string lastName;
    char courseGrade;
};

// Determine if a grade is inputted correctly
bool isValidGrade(char grade) {
    bool isValid = false;
    if (grade == 'A' || grade == 'B' || grade == 'C' ||
        grade == 'D' || grade == 'F') {
        isValid = true;
    }
    return isValid;
}

int main() {
    // Determine the number of students in the class
    int size = -1;
    char tempGrade = 'A';
    while (size < 1) {
        cout << "Enter a number of students: " << endl;
        cin >> size;
    }

    // Dynamically allocate a Student array of students
    Student* students = new Student[size];

    // Fill array with names and grades of students
    cout << "Enter each student's first name, last name, and letter grade (Capital!): " << endl;
    for (int i = 0; i < size; i++) {
        cout << i + 1 << ") ";
        cin >> students[i].firstName;
        cin >> students[i].lastName;
        while (!isValidGrade(students[i].courseGrade)) {
            cin >> students[i].courseGrade;
            if (!isValidGrade(students[i].courseGrade)) {
                cout << "Enter a valid capital letter grade: ";
                cin >> students[i].courseGrade;
            }
        }
    }

    // Print out buffer between input and output
    cout << " *---------------------------*  " << endl;
    for (int i = 0; i < 4; i++) {
        cout << "       ------------------       " << endl;
    }
    cout << " *---------------------------*  " << endl;

    // Print out students in order of grades
    while (tempGrade <= 'F') {
        int numStudentsTemp = 0;
        cout << tempGrade << " students: ";
        for (int i = 0; i < size; i++) {
	        if (students[i].courseGrade == tempGrade) {
  	        cout << students[i].firstName << " ";
	        cout << students[i].lastName;
		cout << ", ";
		}
        }
	cout << endl;
	
        if (tempGrade == 'D') {
	        tempGrade += 2;
        } else {
	        tempGrade++;
        }
        cout << endl;
    }

    // Deallocate Students array from memory
    delete[] students;

    return 0;
}
