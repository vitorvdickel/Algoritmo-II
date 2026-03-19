#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<fstream>
#include<ctime>

using namespace std;

//protótipo das funções
int leitura(string texto);
void gerar(int i = 0, int j = 10);

main()
{
    int v1, v2;
    v1 = leitura("Informe o valor 1: ");
    v2 = leitura("Informe o valor 2: ");
    cout << "\nUsando valores default: " << endl;
    gerar();

    cout << "\nUsando somente um valor informado: " << endl;
    gerar(v1);

    cout << "\nUsando os dois valores informados: " << endl;
    gerar(v1, v2);

}

int leitura(string texto)
{
    int temp;
    cout << texto;
    cin >> temp;
    return temp;
}

void gerar(int i, int j)
{
    if(i > j)
    {
        cout << "O valor 1 deve ser menor que o valor 2";
        return;
    }

    if(i == j)
    {
        cout << "Os valores são iguais não existem número entre eles.";
        return;
    }


    while(i <= j)
    {
        cout << i << ", ";
        i++;
    }
}



