#include <iostream>        // - избыточные числа 
//Избыточное число — это положительное целое число n, сумма положительных собственны
//х делителей (отличных от n) которого превышает n.

using namespace std;

struct Redun{
    bool flag = false;
    unsigned int sum = 0;
};

Redun is_redundancy(int);

int main(){
    int n;
    cout << "Enter number: " <<endl;
    cin >> n;
    for(int i = 0; i < n; i++){
        if (is_redundancy(i).flag)
        cout << "Redundancy number is " << i << " Value redundancy: "<< is_redundancy(i).sum << endl;

    }
    return 0;
}


Redun is_redundancy(int n){
    Redun is_redun_struct;
    for (int i = 1; i < n; i++){
        if (n%i == 0){
            is_redun_struct.sum +=i;
            if (is_redun_struct.sum > n){
                is_redun_struct.flag = true;
            }
        }
    }
    return is_redun_struct;   // возвращаем струтуру с флагом (избыточно ли число) и суммой избыточности
}

