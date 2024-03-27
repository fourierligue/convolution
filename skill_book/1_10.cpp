#include <iostream> 
#include <vector>
#include <bitset>
#include <climits>

// Код Грея
// Напишите программу, которая для всех 5-битных чисел выведет их обычное 
// двоичное представление, представление в виде кода Грея и декодированный 
// код Грея.
// Алгоритм кодирования 
// if b[i-1] = 1 then g[i] = not b[i] ---> 
// else g[i] = b[i]                   ---> g = b xor (b логический сдвиг вправо на 1)
// Алгоритм декодирования 
// b[0] = g[0]
// b[i] = g[i] xor b[i-1]


using namespace std;
const int numBits = 3;
unsigned int decodeGray(int num);

int main(){
    //cout << (1 << numBits) << endl;  // сдвинули 1 на numBits разрядов влево и получили макс число


    // Перебор всех 5-битных чисел
    for (unsigned int i = 0; i < (1 << numBits); ++i) {
        // Обычное двоичное представление
        bitset<numBits> binary(i);                          // bitset<размер> имя_переменной(инициализация);
        
        // Код Грея
        unsigned int gray = i ^ (i >> 1);               // XOR(искл ИЛИ) т е сдвигаем вправо на один бит
        bitset<numBits> grayBits(gray);                 //  код грея для заданного числа i в двоичном виде 
        
        // Декодированный код Грея
        unsigned int decodedGray = decodeGray(gray);   // декодированное число 
        bitset<numBits> decodedGrayBits(decodedGray);  // декодированное  число в двоичном виде 

        // Вывод результатов
        cout << " " << i << " Binary-> " << binary << ", Gray-> " << grayBits << ", Decoded Gray: " << decodedGrayBits << endl;
    }

    return 0;
}


 unsigned int  decodeGray(int num){
    /**
    *@brief декодирование кода Грея (b[i] = g[i] xor b[i-1])
    * 
    *@param - число которое необходимо декодировать по правило кода Грея
    *@return - декодированное число
    **/
    unsigned int mask;
    for (mask = num >> 1; mask != 0; mask = mask >> 1)    // битовый сдвиг вправо, так как g[i] xor b[i-1] , а предыдущий элемент отличается на 1 бит 
        num = num ^ mask;    // побитовое ИЛИ XOR
    return num;
}