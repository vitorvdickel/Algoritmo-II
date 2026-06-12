//toda variável ocupa um espaço na memória do computador
int idade = 20;
//quando o programa executa ele reserva um espaço na memória para armazenar o valor 20
//exemplo: Endereço: 1000 - Valor: 20

//1) O OPERADOR "&" (endereço de memória):
//Assim descobrimos onde uma variável está armazenada
#include <iostream>
using namespace std;

int main(){
    int idade = 20;

    cout << idade << endl;
    cout << &idade << endl;

/*
Saída:
20
0x61ff08
*/

//2) O que é um ponteiro?
//O ponteiro é uma variável que guarda um endereço de memória
//Em vez de armazenar um número, texto ou caractere, ele armazena o endereço de outra variável

//Ex:
//int idade = 20; (em texto pois já foi declarado na explicação)
int *ptr = &idade;
// assim, o ponteiro *ptr está guardando o endereço da variável idade

//Entendendo o símbolo *
//O símbolo * possui dois significados diferentes
//1. Declarar um ponteiro
//int *ptr (ptr é um ponteiro para int)
//2. Acessar o conteúdo apontado
//cout << *ptr (vá até o endereço de *ptr e mostre o que há armazenado)

cout << "\nSegunda etapa da explicação \n \n";
cout << ptr << endl; //mostra o endereço
cout << *ptr << endl; //mostra o valor armazenado naquele endereço

//3) Alterando uma variável através de ponteiro
//uma das maiores funcionalidades de um ponteiro

/*
int idade = 20;
int *ptr = &idade;
*/

cout << "\n Terceira parte da explicação \n";
*ptr = 30; //isso significa: ir até o endereço armazenado em ptr e coloque 30 lá
cout << idade;

return 0;
}