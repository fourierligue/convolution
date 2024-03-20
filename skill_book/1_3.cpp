#include <iostream>  // HOK
#include <cmath>


using namespace std;

int NOD(int, int);
int LCM(int, int);

//----------------------------
int main(){
    cout << LCM(6, 8) <<endl;
    return 0;
}
//-----------------------
int LCM(int a, int b){
    int q = a * b / NOD(a, b);
    return q;
};

//------------------------------
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

