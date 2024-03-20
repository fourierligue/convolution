#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int n;
    cout << "Enter a number:__\b\b";
    cin >> n;
    int sum = 0;

    for (int i = 0; i<=n; ++i){

        if( fmod(i, 3) == 0 || i%5 == 0){   // также при делении на 5 можно проверять равна ли последняя цифра 5 или 0 (%10)
            cout << i << endl;
            sum += i;
        };

    }
    cout << "Sum: " << sum << endl;

    return 0;
}