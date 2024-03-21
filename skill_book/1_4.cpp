#include <iostream>  // Наибольшее простое число меньше заданного


bool is_prime(unsigned int );


using namespace std;

int main(){
    unsigned int n;
    cout << "Enter number:___\b\b\b";
    cin >> n;
    for (int i = n; i > 0; i--){
        if (is_prime(i)){
            cout << i << endl;
            break;
        }
    }

    return 0;
}

bool is_prime(unsigned int n){
    bool flag = true;
    for (int i=2; i < n / 2; i++){
        if (n%i==0){
            flag = false;
            break;
        }
    }
    return flag;
}