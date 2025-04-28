#include "Classroom.h"  
#include  <fstream>

Classroom::Classroom(const Course& c) : course(c) {}  

void Classroom::enrollStudent(int studentID) {  
    if (EnrolledStudents.size() < course.getCapacity()) {  
        EnrolledStudents.push_back(studentID);  
        cout << "Student with ID " << studentID << " has been enrolled in " << course.getCourseName() << "." << endl;  
    }  
    else {  
        cout << "Class is full. Cannot enroll student." << endl;  
    }  
}  

void Classroom::listEnrolledStudents() const {  
    cout << "Enrolled students in " << course.getCourseName() << ":" << endl;  
    for (int id : EnrolledStudents) {  
        cout << "Student ID: " << id << endl;  
    }  
}  

int Classroom::getEnrolledStudentsCount() const {  
    return EnrolledStudents.size();  
} 

void Classroom::saveToFile() const {  
    ofstream file("yekestan.txt", ios::app); 
    if (file.is_open()) {
      file << course.getCourseCode() << endl; 
      int numStudents = EnrolledStudents.size();  
      file << numStudents << endl; 
      for (int id : EnrolledStudents) {  
        file << id << endl;
      }
      file.close();
    }  
    else{
        cout << "Unable to open file for writing." << endl; 
    }
}  
