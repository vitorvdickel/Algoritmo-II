#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>

using namespace std;

void preencher_vetor(int *pvet);

void mostrar_vetor(int *pvet);

main()
{
    system("chcp 1252 > nul");

    int vet[10];

    srand(time(NULL));
    preencher_vetor(vet);

    mostrar_vetor(&vet[0]);
}


void preencher_vetor(int *pvet)
{
    int i, *pi = &i;

    for(*pi = 0; *pi < 10; (*pi)++)
    {
        pvet[*pi] = rand() % 20;
    }
}

void mostrar_vetor(int *pvet)
{
    int i, *pi = &i;

    for(*pi = 0; *pi < 10; (*pi)++)
    {
        cout << *(pvet + *pi)<< ", ";
    }
}



