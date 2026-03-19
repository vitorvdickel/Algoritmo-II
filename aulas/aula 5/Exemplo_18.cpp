#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<fstream>
#include<ctime>

using namespace std;

//protótipo das funções
void gerar_vetor(int vet[], int t);
void mostrar_vetor(int vet[], int t);

main()
{
    int v[10];

    gerar_vetor(v, 10);
    cout << "Valores do vetor: " << endl;
    mostrar_vetor(v, 10);

}

void gerar_vetor(int vet[], int t)
{
    int i = -1;
    ifstream arq ("numeros3.txt");
    if(arq.is_open())
    {
        while(!arq.eof())
        {
            arq >> vet[++i];
            if(i == t)
            {
                break;
            }
        }
    }
    arq.close();
}

void mostrar_vetor(int vet[], int t)
{
    for(int i = 0; i < t; i++)
    {
        cout << vet[i] << ", ";
    }
}

