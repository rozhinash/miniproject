#ifndef PROFESSOR_H  
#define PROFESSOR_H  

#include <iostream>  
#include "Person.h"  
#include "CourseProfessor.h"  
#include "Course.h"  

class Professor : public Person, public CourseProfessor {  
private:  
    int professorID;  

public:  
    Professor(const std::string& n, int l, int id);  
    void createClass();  
};  

#endif