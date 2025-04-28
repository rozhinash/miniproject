#include "Course.h"  

void Course::saveToFile() const {  
  ofstream file("yekestan.txt", ios::app); 
  if (file.is_open()) { 
    file << courseName << endl;  
    file << courseCode << endl;  
    file << courseCapacity << endl;  
    file.close();
  }  
  else{
    cout << "Unable to open file for writing." << endl;
  }
}

void Course::loadFromFile() {  
  ifstream file("cyekestan.txt");  
  if (file.is_open()) {
    while (getline(file, courseName)) { 
      getline(file, courseName);  
      getline(file, courseCode);  
      file >> courseCapacity;  
      file.ignore();
  } 
  file.close();
    }
    else{
      cout << "Unable to open file for reading." << endl; 
    }
}