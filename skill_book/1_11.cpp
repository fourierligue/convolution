#include <iostream> 
#include <string>
// -- Преобразование десятичных чисел в римские
//Напишите программу, которая для заданного десятичного значения выве­ 
//дет его эквивалент в виде римского числа.

using namespace std;

// структура для хранения числа разрядов и римское число соответсвующего разряда 
struct Roman_number{
    int digit_count;  //
    string digit_rom;
};

void check_digit(int num);


int main(){
    int number;
    cout << "Enter decimal number: ";
    cin >> number;
    cout << "Roman number: ";
    check_digit(number);

    return 0;
}

void check_digit(int number){
    // может это и не рационально, но что первое пришло в голову
    Roman_number struct_rom;
    int rem; 
    if (number >= 1000){
        struct_rom.digit_count = number / 1000;
        rem = number%1000;
        struct_rom.digit_rom = "M";
    }
    if (number >= 900 && number < 1000 ){
        struct_rom.digit_count = number / 900;
        rem = number%900;
        struct_rom.digit_rom = "CM";
    }
    if (number >= 500 && number < 900 ){
        struct_rom.digit_count = number / 500;
        rem = number%500;
        struct_rom.digit_rom = "D";
    }
    if (number >= 400 && number < 500 ){
        struct_rom.digit_count = number / 400;
        rem = number%400;
        struct_rom.digit_rom = "CD";
    }
    if (number >= 100 && number < 400 ){
        struct_rom.digit_count = number / 100;
        rem = number%100;
        struct_rom.digit_rom = "C";
    }
    if (number >= 90 && number < 100 ){
        struct_rom.digit_count = number / 90;
        rem = number%90;
        struct_rom.digit_rom = "XC";
    }
    if (number >= 50 && number < 90 ){
        struct_rom.digit_count = number / 50;
        rem = number%50;
        struct_rom.digit_rom = "L";
    }
    if (number >= 40 && number < 50 ){
        struct_rom.digit_count = number / 40;
        rem = number%40;
        struct_rom.digit_rom = "XL";
    }
    if (number >= 10 && number < 40){
        struct_rom.digit_count = number / 10;
        rem = number%10;
        struct_rom.digit_rom = "X";
    }
    if (number == 9 ){
        struct_rom.digit_count = number / 9;
        rem = number%9;
        struct_rom.digit_rom = "IX";
    }
    if (number >= 5 && number < 9){
        struct_rom.digit_count = number / 5;
        struct_rom.digit_rom = "V";
        rem = number%5;
    }
    if (number == 4){
        struct_rom.digit_count = number / 4;
        struct_rom.digit_rom = "IV";
        rem = number%4;
    }
    if (number >=1 && number < 4){
        struct_rom.digit_count = number / 1;
        struct_rom.digit_rom = "I";
        rem = number%1;        
    }
    //выводим римское число (столько раз, сколько разрядов)
    for (int i = 0; i<struct_rom.digit_count; i++){
        cout << struct_rom.digit_rom ;
    }
    // вызываем рекурсивно пока остаток не равен нулю
    if (rem !=0){
        check_digit(rem);
    }
}