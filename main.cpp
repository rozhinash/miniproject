#include "Person.h" 
#include "course.h" 
#include "classroom.h" 
#include "courseprofessor.h" 
#include "professor.h" 
#include <iostream> 




int main() {  
    vector<Person*> users;  
    vector<Classroom*> classrooms;  

    Course math("Mathematics", "MTH101", 3);  
    Course science("Science", "SCI101", 2);  
    classrooms.push_back(new Classroom(math));  
    classrooms.push_back(new Classroom(science));  
 
    users.push_back(new Student("Alice", "alice123", "pass1", 1));  
    users.push_back(new Professor("Dr. Bob", "bob123", "password", 1001));                                
    cout << "Enter your user type (1 for Student, 2 for Professor): ";  
    int userType;  
    cin >> userType;  
    cout << "Enter username: ";  
    cin >> username;  
    cout << "Enter password: ";  
    cin >> password;  

    bool loggedIn = false;  
    for (const auto& user : users) {  
        if ((userType == 1 && dynamic_cast<Student*>(user) && user->login(username, password)) ||  
            (userType == 2 && dynamic_cast<Professor*>(user) && user->login(username, password))) {  
            cout << "Logged in successfully as " << user->getName() << endl;  
            loggedIn = true;  
            break;  
        }  
    }  

}