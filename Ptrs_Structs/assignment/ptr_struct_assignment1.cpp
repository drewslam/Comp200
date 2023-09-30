/// Andrew Souza
/// Comp 200 -- Fall 2023
/// Pointers & Structs Assignment -- Part 1 

#include <iostream>
using namespace std;

/* Enhance the program in The Lab so that each student has ten quiz scores. 
 * The input contains the student names and quiz scores but no course grades. 
 * The program should compute the course grade. 
 * If the sum of the quiz scores is at least 90, the grade is an A. 
 * If the sum is at least 80, the grade is a B, and so on. 
 * Then print all students with grade A together with their individual quiz scores, 
 * followed by all students with grade B, and so on. */

// Define a struct Students with the properties firstName, lastName, an array of 10 quiz grades, and courseGrade
struct Student {
    string firstName;
    string lastName;
    int quizGrades[10];
    char courseGrade;
};

// Add up the scores from each quiz to determine the course grade
char getCourseGrade(int* quizGrades) {
    char courseGrade;
    int courseScore = 0;
    for (int i = 0; i < 10; i++) {
        courseScore += *(quizGrades + i);
    }
    if (courseScore >= 90) {
        courseGrade = 'A';
    } else if (courseScore >= 80) {
        courseGrade = 'B';
    } else if (courseScore >= 70) {
        courseGrade = 'C';
    } else if (courseScore >= 60) {
        courseGrade = 'D';
    } else {
        courseGrade = 'F';
    }

    return courseGrade;
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
    for (int i = 0; i < size; i++) {
        cout << "Enter your student's first and last name: " << endl;
        cout << i + 1 << ") ";
        cin >> students[i].firstName;
        cin >> students[i].lastName;
        cout << "Enter grades for each quiz: " << endl;
        for (int j = 0; j < 10; j++) {
            cout << j + 1 << ") ";
            cin >> students[i].quizGrades[j];
            if (students[i].quizGrades[j] > 10) {
                students[i].quizGrades[j] = 10;
            } else if (students[i].quizGrades[j] < 0) {
                students[i].quizGrades[j] = 0;
            }
        }
        students[i].courseGrade = getCourseGrade(students[i].quizGrades);
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

