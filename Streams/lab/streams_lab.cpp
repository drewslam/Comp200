#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

char ComputeGrade(double a) {
   if (a >= 90) {
      return 'A';
   } else if (a >= 80) {
      return 'B';
   } else if (a >= 70) {
      return 'C';
   } else if (a >= 60) {
      return 'D';
   } else {
      return 'F';
   }
}

int main() {
   ifstream in;
   ofstream out;
   string fileName;
   string studentLastName;
   string studentFirstName;
   int midterm1Score;
   int midterm2Score;
   int finalScore;
   double avg;
   double midterm1Avg = 0;
   double midterm2Avg = 0;
   double finalAvg = 0;
   int numStudents = 0;

   cin >> fileName;
   in.open(fileName);
   out.open("report.txt");
   if (!in.fail()) {
      while (in >> studentLastName >> studentFirstName >> midterm1Score >> midterm2Score >> finalScore) {
        avg = midterm1Score + midterm2Score + finalScore;
        avg = avg / 3;
        out << studentLastName << "\t" << studentFirstName << "\t";
        out << midterm1Score << "\t" << midterm2Score << "\t" << finalScore;
        out << "\t" << ComputeGrade(avg) << endl;
        midterm1Avg += midterm1Score;
        midterm2Avg += midterm2Score;
        finalAvg += finalScore;
        numStudents++;
      }
   }

   out << endl;

   out << "Averages: midterm1 " << fixed << setprecision(2) << midterm1Avg / numStudents << ", ";
   out << "midterm2 " << midterm2Avg / numStudents << ", ";
   out << "final " << finalAvg / numStudents << endl;

   out.close();

   return 0;
}
