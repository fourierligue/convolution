#include <iostream> // -- William Wingate
#include <string>
using namespace std;


struct Pizza_struct {
    string name;
    float diameter;
    double weights;

};

int main(){
    
    // Pizza_struct pizza; 
    Pizza_struct * ptr_pizza = new Pizza_struct;
    cout << "Enter company name: ";
    cin >> ptr_pizza->name;        // если используем указатель то обращаться можно только через -> или (*ptr).name
    cout << "Enter diameter: ";
    cin >> (*ptr_pizza).diameter;
    cout << "Enter weights: ";
    cin >> ptr_pizza->weights;

    cout << "Company name: " << ptr_pizza->name << endl;
    cout << "Diameter: " << ptr_pizza->diameter << endl;
    cout << "Weights: " << ptr_pizza->weights << endl;

    delete ptr_pizza;               // не забываем очистить память, используемая структурой 

    return 0;
}