#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<fstream>
#include<ctime>

using namespace std;

//protótipo das funções
int leitura(string texto);
void gerar_vetor(int vet[], int t, int menor, int maior);
void mostrar_vetor(int vet[], int t);
int somar_pares_vetor(int vet[], int t);

main()
{
    int tam;
    tam = leitura ("Informe o tamanho do vetor: ");
    int v[tam];

    gerar_vetor(v, tam, 20, 30);
    cout << "Valores do vetor: " << endl;
    mostrar_vetor(v, tam);
    cout << "\nSoma dos valores pares do vetor: " << somar_pares_vetor(v, tam) << endl;

}

int leitura(string texto)
{
    int temp;
    cout << texto;
    cin >> temp;
    return temp;
}

void gerar_vetor(int vet[], int t, int menor, int maior)
{
    srand(time(NULL));
    for(int i = 0; i < t; i++)
    {
        vet[i] = rand() % (maior - menor) + menor;
    }
}

void mostrar_vetor(int vet[], int t)
{
    for(int i = 0; i < t; i++)
    {
        cout << vet[i] << ", ";
    }
}

int somar_pares_vetor(int vet[], int t)
{
    int soma = 0;
    for(int i = 0; i < t; i++)
    {
        if(vet[i] % 2 == 0)
        {
            soma += vet[i];
        }
    }
    return soma;
}



