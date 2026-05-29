#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    int *vetor;
    int i, j, aux;

    vetor = new int[10];

    ifstream arquivo("exer_48.txt");

    if (!arquivo)
    {
        cout << "Erro ao abrir o arquivo!" << endl;
        return 1;
    }

    int *p = vetor;

    for (i = 0; i < 10; i++)
    {
        arquivo >> *p;
        p++;
    }

    arquivo.close();

    for (i = 0; i < 9; i++)
    {
        for (j = i + 1; j < 10; j++)
        {
            if (*(vetor + i) > *(vetor + j))
            {
                aux = *(vetor + i);
                *(vetor + i) = *(vetor + j);
                *(vetor + j) = aux;
            }
        }
    }

    ofstream saida("exer_48.txt");

    if (!saida)
    {
        cout << "Erro ao gravar no arquivo!" << endl;
        return 1;
    }

    p = vetor;

    for (i = 0; i < 10; i++)
    {
        saida << *p << " ";
        p++;
    }

    saida.close();

    cout << "Valores ordenados:" << endl;

    p = vetor;

    for (i = 0; i < 10; i++)
    {
        cout << *p << " ";
        p++;
    }

    delete[] vetor;

    return 0;
}