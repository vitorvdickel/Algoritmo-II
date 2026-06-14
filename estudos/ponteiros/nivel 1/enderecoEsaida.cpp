#include <iostream>
#include <cstring>
#include <cmath>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <fstream>

using namespace std;

/*
Exercício 1
Declare um inteiro dinamicamente e:

Armazene o valor 10 nele.
Exiba o valor armazenado.
Exiba o endereço de memória.
*/

main(){
    system("chcp 65001 > nul");

    int *pont = new int; //aloca memória para um inteiro
    *pont = 10; //armazena o valor 10

    cout << "\nValor do ponteiro é: " << *pont << endl;
    cout << "O endereço de memória do ponteiro é: " << pont << endl;

    delete pont; //libera a memória
}