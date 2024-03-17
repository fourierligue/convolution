#include <iostream> 
#include <cstring>

using namespace std;

char * get_firstname(void);
char * get_lastname(void);
int main(){
    char * ptr_lastname;
    char * ptr_firstname;
    ptr_firstname = get_firstname();
    ptr_lastname = get_lastname();

    cout << ptr_firstname << "   " << ptr_lastname << endl;

    delete [] ptr_firstname;
    delete [] ptr_lastname;
    return 0;
}

char * get_firstname(){
    char temp[40];
    cout << "Enter your first name: ";
    cin >> temp;

    char * pn = new char[strlen(temp)+1];
    strcpy(pn, temp);   // копируем в меньший размер
                        // temp удалиться автом по завершении программы 
    return pn;          // вернули адресс на начало строки 
}

char * get_lastname(){
    char temp[40];
    cout << "Enter your last name: ";
    cin >> temp;

    char * pl = new char[strlen(temp)+1];
    strcpy(pl, temp);   // копируем в меньший размер
                        // temp удалиться автом по завершении программы 
    return pl;          // вернули указатель на начало строки 
}