#include <iostream>
#include <cstring>
#include <cmath>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <fstream>

using namespace std;

main(){
    int *vetor = new int [5];

    cout << "\nInforme os valores do vetor: " << endl;
    for (int i = 0; i < 5; i++){ //loop for
        cout << "Vetor " << i + 1 << ": "; //para aparecer ao usuário qual o vetor que ele está colocando o valor
        cin >> *(vetor + i); //para o valor sempre ser agragado ao próximo vetor
    }

    for (int i = 0; i < 5; i++){ //loop for
        cout << *(vetor + i) << " "; //apresentação dos valores do vetor com espaçamento
    }

    delete[] vetor; //limpar memória alocada ao vetor
}