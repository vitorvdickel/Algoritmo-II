#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

using namespace std;

/*
5. Somar elementos de um vetor com ponteiros
Faça um programa que:
Leia 6 números inteiros em um vetor.
Use um ponteiro para percorrer o vetor.
Calcule e exiba a soma de todos os elementos.
Objetivo: praticar aritmética de ponteiros (p++, *(p+i), etc.).
*/
main(){

    int *vetor[6];

    cout << "\nInforme 6 número inteiros para o vetor: " << endl;
    for (int i = 0; i < *vetor[6]; i++){
        cin >> *vetor[i];
    }

    for (int i = 0; i < 6; i++){
        cout << (*vetor + i);
        i++;
        cout << (*vetor + i) << " ";
    }

}