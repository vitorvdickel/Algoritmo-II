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
    char texto[80];

    if (ler.is_open()){
        cout << "Arquivo aberto com sucesso" << endl;
        ler.getline(texto, 6); //nunca colocar um número maior que a capacidade alocada na variável
        cout << texto << endl;
    } else {
        cout << "Impossível abrir o arquivo" << endl;
    }
}