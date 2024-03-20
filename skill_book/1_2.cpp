#include <iostream>  // НОД
#include <cmath>

using namespace std;


int NOD(int, int);

int main(){

    cout << NOD(111, 111) << endl;

    return 0;
}

int NOD(int a, int b){
    
    int r;
    if (a >= b){
        do {
            r = a % b;
            a = b;
            b = r;

        } while(r != 0);  // до тех пор пока остаток не ноль

        return a;   // последний шаг будет a = b * r -> b это НОД
    }
    else{
        do {
            r = b % a;
            b = a;
            a = r;
        } while(r != 0);  

        return b;   
    }
};