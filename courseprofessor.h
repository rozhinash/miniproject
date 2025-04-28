
#ifndef COURSEPROFESSOR_H  
#define COURSEPROFESSOR_H  

#include <iostream>  
#include <vector>  
#include "Classroom.h"  
#include "Course.h"  

class CourseProfessor {  
private:  
    std::vector<Classroom> classrooms; 

public:  
    void createClass(const Course& course);  
    const std::vector<Classroom>& getClassrooms() const;  
};  

#endif