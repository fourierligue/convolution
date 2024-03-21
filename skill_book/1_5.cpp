#include <iostream>
// -- Простые числа, отличающиеся на шесть1

using namespace std;

bool is_prime(unsigned int);

int main(){
    unsigned int n;
    cout << "Enter number: \n";
    cin >> n;
    for (unsigned int i = 2; i <= n; i++){
        if (is_prime(i) && is_prime(i+6)){
            cout << i << "  " << i+6 <<endl;
        }
    }
    return 0;
}




bool is_prime(unsigned int n){
    bool flag = true;
    for (int i = 2; i <= 10 ; i++){
        if ( n%i == 0 ){
            flag = false;
            break;
        }
    }
    return flag;
}