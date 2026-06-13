#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

using namespace std;

/*
Troca de valores sem função
Crie duas variáveis inteiras a e b. Usando ponteiros, troque os valores entre elas e exiba
o resultado final.Objetivo: praticar acesso e escrita via ponteiros.
*/
main(){
    int a, b, aux;
    int *pa, *pb;

    cout << "\nDigite o valor de A: " << endl;
    cin >> a;
    cout << "Digite o valor de B: " << endl;
    cin >> b;

    pa = &a; //guarde dentro de pa o endereço de memória da variável a
    pb = &b; //guarde dentro de pb o endereço de memória da variável b

    cout << "Valor de A antes da troca: " << a << endl;
    cout << "Valor de B antes da troca: " << b << endl;

    aux = *pa;
    *pa = *pb;
    *pb = aux;
    
    cout << "Valor de A depois da troca: " << a << endl;
    cout << "Valor de B depois da troca: " << b << endl;
    
    cout << a << endl; //valor da variável
    cout << &a << endl; //endereço da variável
    cout << pa << endl; //aponta o endereço da variável
    cout << *pa << endl; //aponta o valor da variável
}