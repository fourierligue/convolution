#include <iostream>  // НОД
#include <cmath>

using namespace std;


int NOD(int, int);


// можно рекурсивоно return b == 0 ? a : NOD(b, r=a%b)
int main(){
    cout << NOD(2455, 12435) << endl;
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