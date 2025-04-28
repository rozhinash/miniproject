#include "Professor.h"  
  
Professor::Professor(const std::string& n, int l, int id)   
    : Person(n, l), professorID(id) {}  
 
void Professor::createClass() {  
    std::string name, code;  
    int capacity;  
    
    std::cout << "Enter course name: ";  
    std::cin >> name;  
    
    std::cout << "Enter course code: ";  
    std::cin >> code;  
    
    std::cout << "Enter course capacity: ";  
    std::cin >> capacity;  

    Course newCourse(name, code, capacity);  
    CourseProfessor::createClass(newCourse);   
}  