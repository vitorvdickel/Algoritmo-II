#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

using namespace std;

/*
Alterar uma variável usando ponteiro
Faça um programa que:
Leia um número inteiro do usuário.
Armazene o endereço desse número em um ponteiro.
Some 5 ao valor usando apenas o ponteiro.
Mostre o valor antes e depois da alteração.
Objetivo: modificar variáveis indiretamente com ponteiros.
*/
main(){
    system("chcp 65001 > nul");

    int numero;

    cout << "\nInforme um número inteiro: " << endl;
    cin >> numero;
    
    int *pont = &numero; //armazenando o endereço de "numero" dentro de "*pont"

    cout << "\nANTES DA ALTERAÇÃO" << endl;
    cout << "Valor inicial do número é: " << numero << endl;
    cout << "Valor apontado pelo ponteiro é: " << *pont << endl;

    *pont += 5;

    cout << "\nDEPOIS DA ALTERAÇÃO" << endl;
    cout << "Valor final do número é: " << numero << endl;
    cout << "Valor apontado pelo ponteiro é: " << *pont << endl; 
}