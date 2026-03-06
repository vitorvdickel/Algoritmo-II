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
    ler.open("numeros.txt", ios::in);
    char texto[80];
    float num, soma = 0;

    if (ler.is_open()){
        cout << "Arquivo aberto com sucesso" << endl;

        while(ler.getline(texto, 6, ';'));
        {
            cout << texto << endl;
            num = atof(texto);
            soma += num;
        }
        cout << "Soma dos valores: " << soma << endl;

    } else {
        cout << "Impossível abrir o arquivo" << endl;
    }
}