#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>

using namespace std;

main(){
    system("chcp 1252 > nul");

    ifstream ler;
    ler.open("teste2.txt", ios::in);
    char letra;

    if (ler.is_open()){
        cout << "Arquivo aberto com sucesso" << endl;
        while (ler.get(letra)){
            cout << toupper(letra) << endl;
        }
    } else {
        cout << "Impossível abrir o arquivo" << endl;
    }
}