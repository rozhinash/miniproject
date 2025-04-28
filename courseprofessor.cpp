#include "CourseProfessor.h"  

void CourseProfessor::createClass(const Course& course) {  
    classrooms.emplace_back(course.getCourseName());
    std::cout << "Class for " << course.getCourseName() << " created." << std::endl;  
}  

const std::vector<Classroom>& CourseProfessor::getClassrooms() const {  
    return classrooms;  
}  
