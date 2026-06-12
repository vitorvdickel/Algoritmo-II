//Ponteiros e vetores
//mais um uso comum em algoritmo

#include <iostream>
using namespace std;

main(){
int vetor[5] = {10, 20, 30, 40, 50};
cout << vetor << endl;
//saida 0x29ebfff9b0
int *ptr = vetor;
cout << *ptr << endl << endl;
//saida 10

//ARIRMÉTICA DE PONTERIOS
//se fizermos:
for (int i = 0; i < 5; i++){
    cout << *ptr << endl;
    ptr++;
}
/*
SAÍDA
10
20
30
40
50
*/
}