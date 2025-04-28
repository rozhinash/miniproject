#ifndef PERSON_H  
#define PERSON_H  

#include <string>  
#include <fstream>  

using namespace std;  

class Person {  
protected:  
    string name;  
    int lastname;  
public:  
    Person(const string& n = "", int l = 0) : name(n), lastname(l) {}  

    virtual void saveToFile(ofstream& file) const = 0;  
    virtual void loadFromFile(ifstream& file) = 0;  
};  

#endif 