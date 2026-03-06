#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <cmath>

using namespace std;

main(){
    system("chcp 1252 > nul");

    cout << fixed;
    cout.precision(2);

    ifstream ler;
    ler.open("numeros2.txt", ios::in);
    //char texto[80];
    float num, soma = 0;

    if (ler.is_open()){
        cout << "Arquivo aberto com sucesso" << endl;

        while(ler >> num){
            cout << num << endl;
            soma += num;
        }
        cout << "Soma dos valores: " << soma << endl;

    } else {
        cout << "Impossível abrir o arquivo" << endl;
    }
}