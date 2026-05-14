/*Crie um programa que receba um valor qualquer representando o tamanho dos lados de um quadrado, implemente uma função que receba esse valor
 e utilizando ponteiros escreva com o caracter “*” asterisco na tela, um quadrado com as respectivas diagonais, conforme exemplo apresentado abaixo:
OBS:*/

#include <iostream>

using namespace std;

void desenharQuadrado(int *ptr) {

    for (*(ptr + 1) = 0; *(ptr + 1) < *ptr; (*(ptr + 1))++) {
        
        for (*(ptr + 2) = 0; *(ptr + 2) < *ptr; (*(ptr + 2))++) {
            
            if (*(ptr + 1) == 0 || *(ptr + 1) == *ptr - 1 || 
                *(ptr + 2) == 0 || *(ptr + 2) == *ptr - 1 || 
                *(ptr + 1) == *(ptr + 2) || 
                *(ptr + 1) + *(ptr + 2) == *ptr - 1) {
                
                cout << "* ";
            } else {
                cout << "  ";
            }
        }
        cout << "\n";
    }
}

int main() {

    int mem[3];

    cout << "Informe um valor: ";
    cin >> *(mem);

    desenharQuadrado(mem);

    return 0;
}