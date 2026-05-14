/*Faça um programa que utilizando ponteiros preencha dois vetores, A e B, com dez caracteres cada. A seguir, troque o 1º elemento de A com o 10º
 de B, o 2º de A com o 9º de B, e assim por diante, até trocar o 10º de A com o 1º de B. Mostre os vetores antes e depois da troca.*/

#include <iostream>

using namespace std;

void preencherVetores(char *ptrA, char *ptrB) {
    cout << "--- Preenchendo o Vetor A ---\n";
    for (int i = 0; i < 10; i++) {
        cout << "Digite o caractere para a posicao " << i + 1 << " de A: ";
        cin >> *(ptrA + i); 
    }

    cout << "\n--- Preenchendo o Vetor B ---\n";
    for (int i = 0; i < 10; i++) {
        cout << "Digite o caractere para a posicao " << i + 1 << " de B: ";
        cin >> *(ptrB + i);
    }
}

void exibirVetor(const char *nome, char *ptr) {
    cout << "Vetor " << nome << ": [ ";
    for (int i = 0; i < 10; i++) {
        cout << *(ptr + i) << " ";
    }
    cout << "]\n";
}

void trocarElementos(char *ptrA, char *ptrB) {
    for (int i = 0; i < 10; i++) {
        char temp = *(ptrA + i);
        
        *(ptrA + i) = *(ptrB + (9 - i));
        
        *(ptrB + (9 - i)) = temp;
    }
}

int main() {
    char A[10];
    char B[10];

    preencherVetores(A, B);

    cout << "   VETORES ANTES DA TROCA";
    exibirVetor("A", A);
    exibirVetor("B", B);

    trocarElementos(A, B);

    cout << "   VETORES DEPOIS DA TROCA";
    exibirVetor("A", A);
    exibirVetor("B", B);

    return 0;
}