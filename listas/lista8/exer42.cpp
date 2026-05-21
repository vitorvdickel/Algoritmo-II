#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {

    int *vetor = new int[20];

    srand(time(0));

    for (int i = 0; i < 20; i++) {
        *(vetor + i) = rand() % 99 + 1;
    }

    cout << "Vetor original:\n";

    for (int i = 0; i < 20; i++) {
        cout << *(vetor + i) << " ";
    }

    int primeiro = *vetor;

    for (int i = 0; i < 19; i++) {
        *(vetor + i) = *(vetor + i + 1);
    }

    *(vetor + 19) = primeiro;

    cout << "\n\nVetor apos a troca:\n";

    for (int i = 0; i < 20; i++) {
        cout << *(vetor + i) << " ";
    }

    ofstream arquivo("exer_42.txt");

    for (int i = 0; i < 20; i++) {
        arquivo << *(vetor + i) << " ";
    }

    arquivo.close();

    delete[] vetor;

    return 0;
}