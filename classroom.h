#ifndef CLASSROOM_H  
#define CLASSROOM_H  

#include "Course.h"  
#include <vector>  
#include <iostream>  

using namespace std;  

class Classroom {  
private:  
    Course course;  
    vector<int> EnrolledStudents;  
public:  
    Classroom(const Course& c);  
    void enrollStudent(int studentID);  
    void listEnrolledStudents() const;
    int getEnrolledStudentsCount() const;
    const Course& getCourse() const { return course; }  

    void saveToFile() const;  
    void loadFromFile();  
};  

#endif