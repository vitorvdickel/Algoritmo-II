#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<fstream>
#include<ctime>

using namespace std;

//protótipo das funções
void leitura (int &a, int &b);
int soma(int &a, int &b);

main()
{
    int i, j, s = 0;
    leitura(i, j);
    s = soma(i, j);
    cout << "Soma de " << i << " + " << j << ": " << s;
    cout << "\nValor atualizado de i: " << i << endl;
    cout << "\nValor atualizado de j: " << j << endl;
}

void leitura (int &a, int &b)
{
    cout << "Informe um valor 1: ";
    cin >> a;
    cout << "Informe um valor 2: ";
    cin >> b;
}

int soma(int &a, int &b)
{
    a += 5;
    b -= 2;
    return a + b;
}


