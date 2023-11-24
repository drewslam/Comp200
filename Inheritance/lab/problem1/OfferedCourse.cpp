#include "OfferedCourse.h"

void OfferedCourse::SetInstructorName(string name) {
    this->instructorName = name; 
}

void OfferedCourse::SetLocation(string loc) {
    this->location = loc;
}

void OfferedCourse::SetClassTime(string time) {
    this->classTime = time;
}

string OfferedCourse::GetInstructorName() const {
    return this->instructorName;
}

string OfferedCourse::GetLocation() const {
    return this->location;   
}

string OfferedCourse::GetClassTime() const {
    return this->classTime;
}
