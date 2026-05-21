#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    int *n = new int;
    int *limite = new int;

    cout << "Quantos numeros deseja manipular? ";
    cin >> *n;

    cout << "Informe o limite maximo dos numeros aleatorios: ";
    cin >> *limite;

    int *vetor = new int[*n];

    srand(time(0));

    int *positivos = new int(0);
    int *negativos = new int(0);
    int *pares = new int(0);
    int *impares = new int(0);

    for (int i = 0; i < *n; i++) {
        *(vetor + i) = rand() % (*limite + 11) - 10;

        if (*(vetor + i) >= 0)
            (*positivos)++;
        else
            (*negativos)++;

        if (*(vetor + i) % 2 == 0)
            (*pares)++;
        else
            (*impares)++;
    }

    int *menor = new int(*vetor);
    int *maior = new int(*vetor);

    int *posMenor = new int(0);
    int *posMaior = new int(0);

    for (int i = 1; i < *n; i++) {

        if (*(vetor + i) < *menor) {
            *menor = *(vetor + i);
            *posMenor = i;
        }

        if (*(vetor + i) > *maior) {
            *maior = *(vetor + i);
            *posMaior = i;
        }
    }

    cout << "\nVetor gerado:\n";

    for (int i = 0; i < *n; i++) {
        cout << *(vetor + i) << " ";
    }

    float *percPares = new float;
    float *percImpares = new float;

    *percPares = (*pares * 100.0) / (*n);
    *percImpares = (*impares * 100.0) / (*n);

    cout << "\n\nTotal de numeros positivos: " << *positivos;
    cout << "\nTotal de numeros negativos: " << *negativos;

    cout << "\nPercentual de numeros pares: " << *percPares << "%";
    cout << "\nPercentual de numeros impares: " << *percImpares << "%";

    cout << "\nMenor numero do vetor: " << *menor
         << " na posicao " << *posMenor;

    cout << "\nMaior numero do vetor: " << *maior
         << " na posicao " << *posMaior << endl;

    delete n;
    delete limite;
    delete[] vetor;
    delete positivos;
    delete negativos;
    delete pares;
    delete impares;
    delete menor;
    delete maior;
    delete posMenor;
    delete posMaior;
    delete percPares;
    delete percImpares;

    return 0;
}