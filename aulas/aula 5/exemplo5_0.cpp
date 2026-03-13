#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>

using namespace std;

//protótipo de função
int leitura (char terto[]);
int soma (int a, int b);

main(){
    int i, j;
    i = leitura ("Infomre o valor 1: ");
    j = leitura ("Informe o valor 2: ");
    cout << "Soma de " << i << " + " << j << ": " << soma(i, j) << endl;

    cout << "Valor de I: " << i << endl;
    cout << "Valor de J: " << j << endl;
}

int leitura (char texto[]){
    int temp;
    cout << texto;
    cin >> temp;
    return temp;
}

int soma (int a, int b){
    return a + b;
}