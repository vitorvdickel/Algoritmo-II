//ALOCAÇÃO DINÂMICA DE MEMÓRIA 1:
//aplicação super importante
//às vezes não saberemos quantos elementos teremos, então podemos criar a memória durante a execução
#include <iostream>
using namespace std;

main(){
    int *ptr = new int; //cria um inteiro na memória
    *ptr = 50; //agora o valor armazenado é 50

    delete ptr; //liberação. É necessário para não haver vazamento de memória

    int n;
    cin >> n;
    int *vetor = new int[n]; //agora o tamanho é definido em tempo de execução
    
    //PREENCHENDO
    for (int i = 0; i < n; i++){
        cin >> vetor[i];
    }

    //LIBERANDO
    delete[] vetor;
}


/*
PURO SUCO DO ENTENDIMENTO:
&variavel -> pega o endereço
int *ptr -> cria um ponteiro
*ptr -> acessa ou altera o valor armazenado naquele endereço
*/