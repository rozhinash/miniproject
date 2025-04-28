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

    if (!loggedIn) {  
        cout << "Invalid username or password." << endl;  
    }  
  
    ofstream outFile("yekestan.txt");  
    if (outFile.is_open()) {  
        for (const auto& user : users) {  
            user->saveToFile(outFile);  
        }  
        for (const auto& classroom : classrooms) {  
            classroom->saveToFile(outFile);  
        }  
        outFile.close();  
    } else {  
        cout << "Error opening file!" << endl;  
    }                                                         
     if (userType == 1) {
            Student *student = dynamic_cast<Student *>(users.back()); 
            int choice;  
            do {  
                cout << "1. List Enrolled Classes" << endl;  
                cout << "2. Show Available Courses" << endl;  
                cout << "3. Enroll in a Course" << endl;  
                cout << "4. Exit" << endl;  
                cout << "Enter your choice: ";  
                cin >> choice;  

                switch (choice) {  
                    case 1:  
                        student->listEnrolledClasses();  
                        break;  
                    case 2:  
                        student->showAvailableCourses(classrooms);
                        break;  
                    case 3:   
                        int courseIndex;  
                        cout << "Choose a course to enroll (0 for Math, 1 for Science): ";  
                        cin >> courseIndex; 
                        if (courseIndex >= 0 && courseIndex < classrooms.size()) {  
                            student->enrollInClass(*classrooms[courseIndex]);  
                        } else {  
                            cout << "Invalid course selection!" << endl;  
                        }  
                        break;  
                    case 4:  
                        cout << "Exiting..." << endl;  
                        break;  
                    default:  
                        cout << "Invalid choice. Please try again." << endl;  
                        break;  
                }  
            } while (choice != 4);  
        } 

}