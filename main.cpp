#include <iostream>

#include "calc_3.h"
using namespace std;

//Napisz klasę -> kalkulator naukowy, która będzie realizowała operacje:
//+
//-
//*
// /
//^
//pierwiastkowanie dowolnego stopnia (zależne od argumentu po prawej stronie "p" np.  8p3 = 2)
//% procent z danej liczby np.   100%20 = 20;
//Liczyła zgodnie z zasadami matematyki czyli priorytetyzacją działań , przy czym priorytety punktów  7,6,5 > 3,4 > 1,2
//I przedstawiała wynik po wykonaniu działania: np.  2+2*2 =6
//
//Program ma działać dopóki z niego nie wyjdziemy. Wpisujemy całe działanie, potwierdzamy enterem i otrzymujemy poprawny wynik.

int main() {
    cout << "Welcome to brand new Calculator!" << endl;
    Calc_3 c1;

    do{
        cout << "Result: ";
        c1.printResult();
        cout << "Input your mathematical operation or [E] for exit" << endl;
        c1.getInput();

    }while(c1.working);

    cout << "Goodbye." << endl;
    return 0;
}
