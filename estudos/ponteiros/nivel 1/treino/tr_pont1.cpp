#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <iomanip>

using namespace std;

/*
Material auxiliar: 
&variavel = pega o endereço
int *ptr = cria um ponteiro
*ptr = acessa ou muda o valor armazenado naquele ponteiro
*/

/*
Crie um programa que:
Declare uma variável int x = 10.
Crie um ponteiro int *p apontando para x.
Exiba na tela:
o valor de x
o endereço de x
o valor armazenado em p (endereço)
o valor apontado por p usando *p
Objetivo: entender a diferença entre variável, endereço e conteúdo apontado.
*/

main(){
    system("chcp 65001 > nul");

    int x = 10;

    int *ptr = &x; //assim, o ponteiro guarda o endereço de memória do X

    cout << "Valor de x igual a: " << x << endl; //valor de x
    cout << "O endereço de x igual a: " << &x << endl; //endereço de x
    cout << "O valor apontado pelo ponteiro é: " << *ptr << endl; //valor apontado pelo ponteiro
    cout << "O endereco do ponteiro igual a: " << ptr << endl; //mostra o endereço do ponteiro
}