#include "Course.h"

void Course::SetCourseNumber(string num) {
   this->courseNumber = num;
}

void Course::SetCourseTitle(string title) {
   this->courseTitle = title;
}

string Course::GetCourseNumber() const {
   return this->courseNumber;
}

string Course::GetCourseTitle() const {
   return this->courseTitle;   
}

void Course::PrintInfo() const {
   cout << "Course Information:" << endl;
   cout << "   Course Number: " << GetCourseNumber() << endl;
   cout << "   Course Title: " << GetCourseTitle() << endl;
}
