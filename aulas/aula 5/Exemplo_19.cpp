#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<fstream>
#include<ctime>

using namespace std;

//protótipo das funções
void gerar_matriz(int m[][5], int l, int c);
void mostrar_matriz(int m[][5], int l, int c);
void mostrar_acima_dp(int m[][5], int l, int c);

main()
{
    int mat[5][5];
    int mat2[10][5];

    gerar_matriz(mat, 5, 5);
    cout << "Valores da Matriz: " << endl;
    mostrar_matriz(mat, 5, 5);

    cout << "\nValores acima da diagonal principal da Matriz: " << endl;
    mostrar_acima_dp(mat, 5, 5);

    gerar_matriz(mat2, 10, 5);
    cout << "\n\nValores da Matriz 2: " << endl;
    mostrar_matriz(mat2, 10, 5);

}

void gerar_matriz(int m[][5], int l, int c)
{
    srand(time(NULL));
    for(int i = 0; i < l; i++)
    {
        for(int j = 0; j < c; j++)
        {
            m[i][j] = rand() % 100;
        }
    }
}

void mostrar_matriz(int m[][5], int l, int c)
{
    for(int i = 0; i < l; i++)
    {
        for(int j = 0; j < c; j++)
        {
            cout << m[i][j] << "\t";
        }
        cout << endl;
    }
}

void mostrar_acima_dp(int m[][5], int l, int c)
{
    for(int i = 0; i < l; i++)
    {
        for(int j = 0; j < c; j++)
        {
            if(j > i)
            {
                cout << m[i][j] << "\t";
            }
        }
    }
}

