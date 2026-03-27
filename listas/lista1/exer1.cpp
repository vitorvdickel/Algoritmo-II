/*1 – Escreva um programa que receba do usuário a ordem N de uma matriz quadrada de
números inteiros, sendo que 3 < N < 11, a seguir o programa deverá preencher com números
pseudoaleatórios a matriz e apresentar na tela os seguintes dados:
- Elementos na matriz
- Elementos da diagonal principal
- Elementos da diagonal secundária
- Elementos acima e abaixo da diagonal principal
- Elementos acima e abaixo da diagonal secundária*/

#include <iostream>
#include <cstdlib>
#include <iomanip> // Necessário para o setw()

using namespace std;

int main() {
    int N = 0;

    // Validação da entrada: garantindo que 3 < N < 11
    while (N <= 3 || N >= 11) {
        cout << "Digite a ordem N da matriz quadrada (deve ser maior que 3 e menor que 11): ";
        cin >> N;
        if (N <= 3 || N >= 11) {
            cout << "Valor invalido! Tente novamente.\n" << endl;
        }
    }

    // Como N < 11, o tamanho máximo da matriz será 10x10.
    // Declarar uma matriz estática de 10x10 é a forma mais segura sem usar ponteiros.
    int matriz[10][10];

    // Preenchendo a matriz com números pseudoaleatórios (limitados de 0 a 99 para formatar melhor)
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            matriz[i][j] = rand() % 100; 
        }
    }

    // 1. Elementos na matriz
    cout << "\n--- Matriz Completa ---" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << setw(3) << matriz[i][j] << " ";
        }
        cout << endl;
    }

    // 2. Elementos da diagonal principal (índice da linha igual ao da coluna: i == j)
    cout << "\n--- Diagonal Principal ---" << endl;
    for (int i = 0; i < N; i++) {
        cout << matriz[i][i] << " ";
    }
    cout << endl;

    // 3. Elementos da diagonal secundária (soma dos índices: i + j == N - 1)
    cout << "\n--- Diagonal Secundaria ---" << endl;
    for (int i = 0; i < N; i++) {
        cout << matriz[i][N - 1 - i] << " ";
    }
    cout << endl;

    // 4. Elementos acima da diagonal principal (coluna maior que a linha: j > i)
    cout << "\n--- Acima da Diagonal Principal ---" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (j > i) {
                cout << setw(3) << matriz[i][j] << " ";
            } else {
                cout << "    "; // Espaços vazios para manter o formato de triângulo
            }
        }
        cout << endl;
    }

    // 5. Elementos abaixo da diagonal principal (linha maior que a coluna: i > j)
    cout << "\n--- Abaixo da Diagonal Principal ---" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i > j) {
                cout << setw(3) << matriz[i][j] << " ";
            } else {
                cout << "    ";
            }
        }
        cout << endl;
    }

    // 6. Elementos acima da diagonal secundária (soma dos índices: i + j < N - 1)
    cout << "\n--- Acima da Diagonal Secundaria ---" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i + j < N - 1) {
                cout << setw(3) << matriz[i][j] << " ";
            } else {
                cout << "    ";
            }
        }
        cout << endl;
    }

    // 7. Elementos abaixo da diagonal secundária (soma dos índices: i + j > N - 1)
    cout << "\n--- Abaixo da Diagonal Secundaria ---" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i + j > N - 1) {
                cout << setw(3) << matriz[i][j] << " ";
            } else {
                cout << "    ";
            }
        }
        cout << endl;
    }

    return 0;
}