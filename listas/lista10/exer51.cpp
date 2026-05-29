#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
    int *vetor = new int[20];
    int *pos1 = new int;
    int *pos2 = new int;
    int *aux = new int;
    int *i = new int;

    srand(time(NULL));

    for (*i = 0; *i < 20; (*i)++)
    {
        *(vetor + *i) = rand() % 101;
    }

    ofstream arquivo("exer_51.txt");

    for (*i = 0; *i < 20; (*i)++)
    {
        arquivo << *(vetor + *i) << " ";
    }

    arquivo.close();

    cout << "Vetor gerado:" << endl;

    for (*i = 0; *i < 20; (*i)++)
    {
        cout << *(vetor + *i) << " ";
    }

    cout << "\n\nDigite a primeira posicao (0 a 19): ";
    cin >> *pos1;

    cout << "Digite a segunda posicao (0 a 19): ";
    cin >> *pos2;

    if (*pos1 < 0 || *pos1 > 19 || *pos2 < 0 || *pos2 > 19)
    {
        cout << "Posicao invalida!" << endl;

        delete[] vetor;
        delete pos1;
        delete pos2;
        delete aux;
        delete i;

        return 1;
    }

    cout << "\nEndereco da posicao " << *pos1 << ": ";
    cout << (vetor + *pos1) << endl;

    cout << "Endereco da posicao " << *pos2 << ": ";
    cout << (vetor + *pos2) << endl;

    *aux = *(vetor + *pos1);

    *(vetor + *pos1) = *(vetor + *pos2);

    *(vetor + *pos2) = *aux;

    cout << "\nVetor alterado:" << endl;

    for (*i = 0; *i < 20; (*i)++)
    {
        cout << *(vetor + *i) << " ";
    }

    ofstream arquivo2("exer_51.txt");

    for (*i = 0; *i < 20; (*i)++)
    {
        arquivo2 << *(vetor + *i) << " ";
    }

    arquivo2.close();

    // Liberando memória
    delete[] vetor;
    delete pos1;
    delete pos2;
    delete aux;
    delete i;

    return 0;
}