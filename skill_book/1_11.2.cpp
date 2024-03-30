#include <iostream> 
#include <string> // -- перевод из римских в обычные числа 
#include <unordered_map>    // контейнеры которые не сортируются (просто map сортируются)

using namespace std;

unordered_map<string, int> dict_roman = {{"I", 1}, {"V", 5}, {"X", 10}, {"L", 50},{"C", 100}, {"D", 500}, {"M", 1000}};


int roman_to_decimal(string);

int main(){
    string roman_num;
    cout << "Enter roman number: ";
    cin >> roman_num;
    cout << roman_to_decimal(roman_num)<< endl;

    return 0;
}

int roman_to_decimal(string roman_num){
    int result = 0;

    for(int i = 0; i < roman_num.size(); ++i){          // проходимся по каждому введенному символу
        char cur_symbol = roman_num[i];
        
        if (dict_roman.count(string(1, cur_symbol))>0){   // проверяем на сущетсвования встреченного символа в словаре 
            if (i != roman_num.size()-1){                 // исключаем последний элемент
                char next_symbol = roman_num[i+1];        // следующий символ
                if (dict_roman.at(string(1, cur_symbol)) >= dict_roman.at(string(1, next_symbol))){   
                    result +=dict_roman.at(string(1, cur_symbol));
                } else {
                    result += (dict_roman.at(string(1, next_symbol)) - dict_roman.at(string(1, cur_symbol)));    // учитываем символы IV, IX и т д
                    i++;   // так как следующий символ уже был учтен
                }
            }else{
                result += dict_roman.at(string(1, cur_symbol));
            }
        }else{
            cout << "Error element: " << cur_symbol << endl;
            break;
        }
    }
    return result;
}