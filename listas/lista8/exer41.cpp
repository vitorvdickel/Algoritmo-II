#include <iostream>
#include <fstream>

using namespace std;

int main() {

    int *vetor = new int[10];

    ifstream arquivo("exer_41.txt");

    for (int i = 0; i < 10; i++) {
        arquivo >> *(vetor + i);
    }

    arquivo.close();

    cout << "Vetor original:\n";

    for (int i = 0; i < 10; i++) {
        cout << *(vetor + i) << " ";
    }

    for (int i = 0; i < 5; i++) {

        int temp = *(vetor + i);

        *(vetor + i) = *(vetor + (9 - i));

        *(vetor + (9 - i)) = temp;
    }

    cout << "\n\nVetor apos as trocas:\n";

    for (int i = 0; i < 10; i++) {
        cout << *(vetor + i) << " ";
    }

    ofstream resultado("resultados.txt");

    for (int i = 0; i < 10; i++) {
        resultado << *(vetor + i) << " ";
    }

    resultado.close();

    delete[] vetor;

    return 0;
}