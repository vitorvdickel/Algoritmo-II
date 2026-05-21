#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

bool existe(int vetor[], int tamanho, int valor)
{
    for (int i = 0; i < tamanho; i++)
    {
        if (vetor[i] == valor)
        {
            return true;
        }
    }

    return false;
}

void ordenar(int vetor[], int tamanho)
{
    int aux;

    for (int i = 0; i < tamanho - 1; i++)
    {
        for (int j = 0; j < tamanho - 1 - i; j++)
        {
            if (vetor[j] > vetor[j + 1])
            {
                aux = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = aux;
            }
        }
    }
}

bool Primo(int numero)
{
    if (numero < 2)
    {
        return false;
    }

    for (int i = 2; i <= numero / 2; i++)
    {
        if (numero % i == 0)
        {
            return false;
        }
    }

    return true;
}

int* uniaoVetores(int x1[], int x2[], int &tamanhoX3)
{
    int *x3 = new int[20];

    tamanhoX3 = 0;

    for (int i = 0; i < 10; i++)
    {
        if (!existe(x3, tamanhoX3, x1[i]))
        {
            x3[tamanhoX3] = x1[i];
            tamanhoX3++;
        }
    }

    for (int i = 0; i < 10; i++)
    {
        if (!existe(x3, tamanhoX3, x2[i]))
        {
            x3[tamanhoX3] = x2[i];
            tamanhoX3++;
        }
    }

    return x3;
}

int main()
{
    srand(time(NULL));

    int x1[10];
    int x2[10];

    for (int i = 0; i < 10; i++)
    {
        x1[i] = 10 + rand() % 31;
        x2[i] = 10 + rand() % 31;
    }

    cout << "Vetor x1:" << endl;

    for (int i = 0; i < 10; i++)
    {
        cout << x1[i] << " ";
    }

    cout << endl << endl;

    cout << "Vetor x2:" << endl;

    for (int i = 0; i < 10; i++)
    {
        cout << x2[i] << " ";
    }

    cout << endl << endl;

    int tamanhoX3;

    int *x3 = uniaoVetores(x1, x2, tamanhoX3);

    ordenar(x3, tamanhoX3);

    cout << "Vetor x3 (uniao):" << endl;

    for (int i = 0; i < tamanhoX3; i++)
    {
        cout << x3[i] << " ";
    }

    cout << endl << endl;

    int menor = x3[0];
    int maior = x3[0];

    for (int i = 1; i < tamanhoX3; i++)
    {
        if (x3[i] < menor)
        {
            menor = x3[i];
        }

        if (x3[i] > maior)
        {
            maior = x3[i];
        }
    }

    cout << "Menor elemento de x3: " << menor << endl;
    cout << "Maior elemento de x3: " << maior << endl;

    cout << endl;

    int quantidadePrimos = 0;

    cout << "Numeros primos de x3:" << endl;

    for (int i = 0; i < tamanhoX3; i++)
    {
        if (Primo(x3[i]))
        {
            cout << x3[i] << " ";
            quantidadePrimos++;
        }
    }

    cout << endl << endl;

    cout << "Quantidade de numeros primos em x3: "
         << quantidadePrimos << endl;

    delete[] x3;