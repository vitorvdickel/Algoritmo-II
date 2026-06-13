/*
4. Percorrer um vetor com ponteiros
Crie um vetor de 5 inteiros e preencha com valores digitados pelo usuário.
 Depois, use um ponteiro para percorrer o vetor e imprimir todos os elementos.
 Objetivo: 
 entender que o nome do vetor pode ser tratado como ponteiro para o primeiro elemento.
*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

using namespace std;

main(){
    system("chcp 65001 > nul");

    int vetor[5];
    int *pont = vetor;

    cout << "Insira os valores do vetor: " << endl;
    for (int i = 0; i < 5; i++){
        cin >> vetor[i];
    } //nesse laço ele recebe os valores do vetor inseridos pelo usuário

    cout << "Valores armazenados no vetor: " << endl;

    for (int i = 0; i < 5; i++){
        cout << (*pont + i) << " ";
    } //nesse laço o ponteiro busca os valores que foram inseridos no vetor

    cout << " ";
}