#include <iostream>
#include <cstring>
#include <cmath>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <fstream>

using namespace std;

/*
Crie dois inteiros dinamicamente.

Solicite dois valores ao usuário e exiba:
Soma
Subtração
Multiplicação
*/
main(){
    system("chcp 65001 > nul");

    int *n1 = new int;
    int *n2 = new int;

    int *soma = new int, *subt = new int, *mult = new int;

    cout << "\nCalculadora" << endl;
    cout << "Insira o valor de N1: " << endl;
    cin >> *n1;
    cout << "Insira o valor de N2: " << endl;
    cin >> *n2;

    *soma = *n1 + *n2;
    *subt = *n1 - *n2;
    *mult = *n1 * *n2;

    cout << "A soma dos valores é: " << *soma << endl;
    cout << "A subtração dos valores é: " << *subt << endl;
    cout << "A multiplicação dos valores é: " << *mult << endl;
    cout << "\n";
    
    //pode ser feito sem a criação de ponteiros:

    cout << "Soma: " << (*n1 + *n2) << endl;
    cout << "Subração: " << (*n1 - *n2) << endl;
    cout << "Multiplicação: " << (*n1 * *n2) << endl;
}