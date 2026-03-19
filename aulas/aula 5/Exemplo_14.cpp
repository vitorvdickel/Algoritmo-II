#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<fstream>
#include<ctime>

using namespace std;

//protótipo das funções
int leitura (char texto[]);
int soma(int a, int b);

main()
{
    int i, j;
    i = leitura("Informe o valor 1: ");
    j = leitura("Informe o valor 2: ");
    cout << "Soma de " << i << " + " << j << ": " << soma(i, j);

    cout << "\nValor de I: " << i << endl;
    cout << "Valor de J: " << j << endl;
}

int leitura (char texto[])
{
    int temp;
    cout << texto;
    cin >> temp;
    return temp;
}

int soma(int a, int b)
{
    a += 2;
    cout << "\nValor de A: " << a << endl;
    cout << "Valor de B: " << b << endl;
    return a + b;
}


