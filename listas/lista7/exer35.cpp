#include <iostream>
#include <cstdlib> 

using namespace std;

void gerarValores(int *ponteiro_vetor) {
    for (int i = 0; i < 6; i++) {
        *(ponteiro_vetor + i) = (rand() % 50) + 1;
    }
}

int main() {
    int vetor[6];
    int soma_pares = 0;
    int qtd_impares = 0;

    gerarValores(vetor); 

    cout << "Vetor\n";
    
    for (int i = 0; i < 6; i++) {
        cout << *(vetor + i) << "\t";
    }
    cout << "\n";
    
    for (int i = 0; i < 6; i++) {
        cout << i << "\t";
    }
    cout << "\n\n";

    cout << "Relatorio\n";
    
    cout << "Os numeros pares sao:\n";
    for (int i = 0; i < 6; i++) {
        if (*(vetor + i) % 2 == 0) {
            cout << "numero " << *(vetor + i) << " na posicao " << i << "\n";
            soma_pares += *(vetor + i);
        }
    }
    cout << "Soma dos pares = " << soma_pares << "\n\n";

    cout << "Os numeros impares sao:\n";
    for (int i = 0; i < 6; i++) {
        if (*(vetor + i) % 2 != 0) {
            cout << "numero " << *(vetor + i) << " na posicao " << i << "\n";
            qtd_impares++;
        }
    }
    cout << "Quantidade de impares = " << qtd_impares << "\n";

    return 0;
}