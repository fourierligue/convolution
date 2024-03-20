#include <iostream>
#include <vector>
#include <array> 
#include <cstring>

using namespace std;


int main(){
    double avarage;
    array<double, 3> res;
    cout << "Enter three race results: \n";
    cin >> res[0];
    cin >> res[1];
    cin >> res[2];
    avarage = (res[0] + res[1] + res[2]) / 3.0 ; 

    cout << "Avarage value: " << avarage << endl; 
    
    return 0;
}