//
//  main.cpp
//  unique-cornLab
//
//  Created by Gabriela Avila on 11/2/25.
//

#include <iostream>
#include <vector>
using namespace std;

class usedName : public exception{
public:
    virtual const char* what() const throw() {
        return "Another unicorn already has this name!";
    }
}un;

class Unicorn{
    
protected:
    string name;
    static vector<string> usedNames;
    
public:
    Unicorn(string n){
        for(int i = 0; i < usedNames.size(); i ++){
            if (usedNames[i] == n){
                throw un;
            }
        }
        name = n;
        usedNames.push_back(n);
        cout << "Unicorn " << name << endl;
    }
    
    ~Unicorn (){
        for(int i = 0; i < usedNames.size(); i ++){
            if (usedNames[i] == name){
                cout << "Unicorn " << name << " has died :(" << endl;
                usedNames.erase(usedNames.begin() + i);
                break;
            }
        }
    }
    
};

vector<string> Unicorn::usedNames;

int main() {
    
    try {
        
        Unicorn* u1 = new Unicorn("Uni");
        delete u1;
        Unicorn* u2 = new Unicorn("Sparkle");
        delete u2;
        Unicorn* u3 = new Unicorn("Sparkle");
        
    }catch(usedName& un){
        cout << un.what() << endl;
    }
    
    try {
        
        Unicorn* u1 = new Unicorn("U");
        delete u1;
        Unicorn* u2 = new Unicorn("Sprinkle");
        Unicorn* u3 = new Unicorn("Sprinkle");
        
    }catch(usedName& un){
        cout << un.what() << endl;
    }
    
   
}
