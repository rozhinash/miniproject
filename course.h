#ifndef COURSE_H
#define COURSE_H

#include <iostream>  
#include <string>
#include <vector> 
#include <fstream>


using namespace std;

class Course {
protected :
    string courseName;
    string courseCode;
    int courseCapacity;
public :
    Course(const string& name = "", const string& code = "", const int& capacity = 0) 
    : courseName(name), courseCode(code), courseCapacity(capacity) {}

    string getCourseName() const { return courseName; }  
    string getCourseCode() const { return courseCode; }  
    int getCapacity() const { return courseCapacity; } 

    void saveToFile() const;  
    void loadFromFile();
};

class Classroom {
private :
    Course course;
    vector<int> EnrolledStudents;
public :
    Classroom(const Course& c) : course(c){}

    void enrollStudent(int studentID) {  
        if (EnrolledStudents.size() < course.getCapacity()) {  
            EnrolledStudents.push_back(studentID);  
            cout << "Student with ID " << studentID << " has been enrolled in " << course.getCourseName() << "." << endl;  
        } else {  
            cout << "Class is full. Cannot enroll student." << endl;  
        }  
    }  

    void listEnrolledStudents() const {  
        cout << "Enrolled students in " << course.getCourseName() << ":" << endl;  
        for (int id : EnrolledStudents) {  
            cout << "Student ID: " << id << endl;  
        }  
    }

};

class CourseProfessor {
private :
    vector<Classroom> classrooms;
public :
    void createClass(const Course& course) {  
        classrooms.emplace_back(course);  
        cout << "Class for " << course.getCourseName() << " created." << endl;  
    }  

const vector<Classroom>& getClassrooms() const { return classrooms; }  

};

class Person {
protected :
    string name;
    int lastname;
public :
    Person( const string& n, int l) : name(n),lastname(l) {}
};

class Student : public Person{
private :
    int studentID;
public :
    Student(const string& n, int l, int id) : Person(n, l), studentID(id) {}

    void enrollInClass(Classroom& classroom) {  
        classroom.enrollStudent(studentID);  
    } 
};

class Professor : public Person, public CourseProfessor{
private :
    int professorID;
public :
    Professor(const string& n, int l, int id) : Person(n, l), professorID(id) {}

    void createClass(){
        string name;
        string code;
        int capacity;
        cout << "Enter course name: ";  
        cin >> name;  
        cout << "Enter course code: ";  
        cin >> code;  
        cout << "Enter course capacity: ";  
        cin >> capacity;  

        Course newCourse(name, code, capacity);  
        CourseProfessor::createClass(newCourse); 

    }
};

#endif