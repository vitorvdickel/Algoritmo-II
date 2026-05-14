/*Escreva uma função que receba como parâmetro um array de inteiros com N valores, e determina o maior elemento do array e o número de vezes que 
este elemento ocorreu no array. Por exemplo, para um array com os seguintes elementos:
5, 2, 15, 3, 7, 15, 8, 6, 15,
A função deve fornecer para o programa que a chamou o valor 15 e o número 3 (indicando que o número 15 é o maior e aparece 3 vezes no vetor).
A função deve ser do tipo void, utilize ponteiros para resolver este exercício, não é permitido o uso de nenhuma variável.*/

#include <iostream>

using namespace std;
void analisarMaior(int *arr, int *ptr_n, int *ptr_maior, int *ptr_qtd, int *ptr_i) {
    *ptr_maior = *arr;
    *ptr_qtd = 0;

    for (*ptr_i = 0; *ptr_i < *ptr_n; (*ptr_i)++) {
        if (*(arr + *ptr_i) > *ptr_maior) {
            *ptr_maior = *(arr + *ptr_i); 
            *ptr_qtd = 1;
        } 
        else if (*(arr + *ptr_i) == *ptr_maior) {
            (*ptr_qtd)++;
        }
    }
}

int main() {
    int dados[9] = {5, 2, 15, 3, 7, 15, 8, 6, 15};

    int controle[4] = {9, 0, 0, 0};

    analisarMaior(dados, controle, (controle + 2), (controle + 3), (controle + 1));

    cout << "Array analisado: ";
    for (*(controle + 1) = 0; *(controle + 1) < *controle; (*(controle + 1))++) {
        cout << *(dados + *(controle + 1)) << " ";
    }
    cout << "Valor fornecido pela funcao: " << *(controle + 2) << "\n";
    cout << "Numero de ocorrencias: " << *(controle + 3) << "\n";

    return 0;
}