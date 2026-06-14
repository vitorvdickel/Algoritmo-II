#include <iostream>
#include <cstring>
#include <cmath>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <fstream>

using namespace std;

/*
Crie um inteiro dinamicamente.
Solicite um número ao usuário.

Informe:
Dobro
Triplo
Quadrado
Utilizando apenas o conteúdo apontado.
*/

main(){
    system("chcp 65001 > nul");

    int *valor;

    cout << "\nInforme um número: " << endl;
    cin >> *valor;

    cout << "O dobro do número inserido é: " << (*valor * 2) << endl;
    cout << "O triplo do número inserido é: " << (*valor * 3) << endl;
    cout << "O quadruplo do número inserido é: " << (*valor * 4) << endl;
}