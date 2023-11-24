#ifndef OFFERED_COURSEH
#define OFFERED_COURSEH

#include "Course.h"

class OfferedCourse : public Course {
private:
    string instructorName;
    string location;
    string classTime;

public:
	void SetInstructorName(string name);
    void SetLocation(string loc);
    void SetClassTime(string time);

	string GetInstructorName() const;
    string GetLocation() const;
    string GetClassTime() const;
};

#endif
