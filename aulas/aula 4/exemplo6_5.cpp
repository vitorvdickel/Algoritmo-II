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
    ler.open("texto.txt", ios::in);
    string texto;

    if (ler.is_open()){
        
        cout << "Arquivo aberto com sucesso" << endl;

        while(ler >> texto){
            cout << texto << endl;
        }
    } else {
        cout << "Impossível abrir o arquivo" << endl;
    }
}