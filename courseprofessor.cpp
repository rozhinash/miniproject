#include "CourseProfessor.h"  

void CourseProfessor::createClass(const Course& course) {  
    classrooms.emplace_back(course.getCourseName());
    std::cout << "Class for " << course.getCourseName() << " created." << std::endl;  
}  
