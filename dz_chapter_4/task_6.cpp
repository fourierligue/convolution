#include <iostream> // структуры 
#include <string>
using namespace std;

struct CandyBar {
    string name;
    double weight;
    int calories;

};


int main(){
    
    CandyBar * ptr_struct = new CandyBar[3];   // выделяем память под структуру типа CandyBar динамически
                                                // можно и просто CandyBar arr_struct[2];
    ptr_struct[0] = {"snack", 32.4, 354};
    ptr_struct[1] = {"marmalade", 12.4, 654};
    ptr_struct[2] = {"chocolate", 56.21, 874};
    


    cout << "CandyBar 1: \n";
    cout << "Name: " << ptr_struct[0].name << endl;
    cout << "Weight: " << ptr_struct[0].weight << endl;
    cout << "Calories: " << ptr_struct[0].calories << endl;

    cout << "\nCandyBar 2: \n";
    cout << "Name: " << ptr_struct[1].name << endl;
    cout << "Weight: " << ptr_struct[1].weight << endl;
    cout << "Calories: " << ptr_struct[1].calories << endl;

    cout << "\nCandyBar 3: \n";
    cout << "Name: " << ptr_struct[2].name << endl;
    cout << "Weight: " << ptr_struct[2].weight << endl;
    cout << "Calories: " << ptr_struct[2].calories << endl;

    delete [] ptr_struct;

    return 0;
}