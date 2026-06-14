#include <iostream>
#include <cstring>
#include <cmath>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <fstream>

using namespace std;

//Crie dois inteiros dinamicamente e troque seus valores.

main(){
    system("chcp 65001 > nul");

    int *a = new int;
    int *b = new int;
    int *aux = new int;

    cout << "\nInforme o valor de A: " << endl;
    cin >> *a;
    cout << "Informe o valor de B: " << endl;
    cin >> *b;

    //fazendo a troca
    *aux = *a;
    *a = *b;
    *b = *aux;

    cout << "Valor de A depois da troca é: " << *a << endl;
    cout << "Valor de B depois da troca é: " << *b << endl;

    delete a;
    delete b;
    delete aux;
}   