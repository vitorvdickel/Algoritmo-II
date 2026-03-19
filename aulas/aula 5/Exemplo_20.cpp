#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<fstream>
#include<ctime>

using namespace std;

//inclusão do repositório das funções no arquivo.
#include "repositorio.hpp";



main()
{
    int d;
    d = ler_inteiro("Informe a ordem da matriz: ");
    int mat[d][50];

    gera_matriz(mat, d);
    cout << "Matriz gerada: " << endl;
    mostra_matriz(mat, d);
}


