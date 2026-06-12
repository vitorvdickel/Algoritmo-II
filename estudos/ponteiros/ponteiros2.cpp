//4) Ponteiros e Funções
// aplicação mais importante em algoritmo II

//sem ponteiro
#include <iostream>
using namespace std;

/*void alterar (int x){
    x = 100;
}

int main(){
    int numero = 10;
    alterar(numero);
    cout << numero;

    return 0;
} */
// saida = 10 (nada mudou, pois a função recebe uma cópia da variável)

//agora usando ponteiros

void alterar (int *x){
    *x = 100;
}

main(){
    int numero = 10;
    alterar (&numero);
    cout << numero;
} 
//saida 100