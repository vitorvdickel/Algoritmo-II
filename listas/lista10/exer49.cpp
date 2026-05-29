#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int contarElementos(char nomeArquivo[])
{
    ifstream arquivo(nomeArquivo);

    if (!arquivo)
    {
        return 0;
    }

    int contador = 0;
    int numero;
    char separador;

    while (arquivo >> numero)
    {
        contador++;

        arquivo >> separador;
    }

    arquivo.close();

    return contador;
}

void carregarVetor(char nomeArquivo[], int *vetor, int tamanho)
{
    ifstream arquivo(nomeArquivo);

    int *p = vetor;
    char separador;

    for (int i = 0; i < tamanho; i++)
    {
        arquivo >> *p;

        if (i < tamanho - 1)
        {
            arquivo >> separador;
        }

        p++;
    }

    arquivo.close();
}

void salvarVetor(char nomeArquivo[], int *vetor, int tamanho)
{
    ofstream arquivo(nomeArquivo);

    int *p = vetor;

    for (int i = 0; i < tamanho; i++)
    {
        arquivo << *p;

        if (i < tamanho - 1)
        {
            arquivo << ",";
        }

        p++;
    }

    arquivo.close();
}

void ordenar(int *vetor, int tamanho)
{
    int i, j, aux;

    for (i = 0; i < tamanho - 1; i++)
    {
        for (j = i + 1; j < tamanho; j++)
        {
            if (*(vetor + i) > *(vetor + j))
            {
                aux = *(vetor + i);
                *(vetor + i) = *(vetor + j);
                *(vetor + j) = aux;
            }
        }
    }
}

void mostrar(int *vetor, int tamanho)
{
    int *p = vetor;

    for (int i = 0; i < tamanho; i++)
    {
        cout << *p;

        if (i < tamanho - 1)
        {
            cout << ",";
        }

        p++;
    }

    cout << endl;
}

int main()
{
    char vet1Arquivo[] = "vet1.txt";
    char vet2Arquivo[] = "vet2.txt";
    char vet3Arquivo[] = "vet3.txt";

    int tam1 = contarElementos(vet1Arquivo);
    int tam2 = contarElementos(vet2Arquivo);

    int *vet1 = new int[tam1 + 100];
    int *vet2 = new int[tam2 + 100];

    carregarVetor(vet1Arquivo, vet1, tam1);
    carregarVetor(vet2Arquivo, vet2, tam2);

    int opcao;

    do
    {
        cout << "\n0 - Sair" << endl;
        cout << "1 - Incluir elemento no vetor 1" << endl;
        cout << "2 - Incluir elemento no vetor 2" << endl;
        cout << "3 - Interseccao" << endl;
        cout << "4 - Mostrar ordenado" << endl;

        cout << "\nOpcao: ";
        cin >> opcao;

        if (opcao == 1)
        {
            int valor;

            cout << "Digite o valor: ";
            cin >> valor;

            *(vet1 + tam1) = valor;
            tam1++;

            salvarVetor(vet1Arquivo, vet1, tam1);
        }
        else if (opcao == 2)
        {
            int valor;

            cout << "Digite o valor: ";
            cin >> valor;

            *(vet2 + tam2) = valor;
            tam2++;

            salvarVetor(vet2Arquivo, vet2, tam2);
        }
        else if (opcao == 3)
        {
            if (tam1 == 0 || tam2 == 0)
            {
                cout << "Os vetores precisam ter elementos!" << endl;
            }
            else
            {
                int *vet3 = new int[tam1];
                int tam3 = 0;

                for (int i = 0; i < tam1; i++)
                {
                    for (int j = 0; j < tam2; j++)
                    {
                        if (*(vet1 + i) == *(vet2 + j))
                        {
                            *(vet3 + tam3) = *(vet1 + i);
                            tam3++;
                        }
                    }
                }

                salvarVetor(vet3Arquivo, vet3, tam3);

                cout << "Interseccao criada em vet3.txt" << endl;

                delete[] vet3;
            }
        }
        else if (opcao == 4)
        {
            if (tam1 == 0 || tam2 == 0)
            {
                cout << "Os vetores precisam ter elementos!" << endl;
            }
            else
            {
                ordenar(vet1, tam1);
                ordenar(vet2, tam2);

                int tam3 = contarElementos(vet3Arquivo);

                int *vet3 = new int[tam3];

                carregarVetor(vet3Arquivo, vet3, tam3);

                ordenar(vet3, tam3);

                cout << "\nvet1 = ";
                mostrar(vet1, tam1);

                cout << "vet2 = ";
                mostrar(vet2, tam2);

                cout << "vet3 = ";
                mostrar(vet3, tam3);

                delete[] vet3;
            }
        }
        else if (opcao != 0)
        {
            cout << "Opcao invalida!" << endl;
        }

    } while (opcao != 0);

    delete[] vet1;
    delete[] vet2;

    return 0;
}