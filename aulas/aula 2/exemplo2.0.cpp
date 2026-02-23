#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>

using namespace std;

main(){
    system ("chcp 1252 > nul");

    string texto;

    cout << "\n Informe um texto qualquer" << endl;
    getline (cin, texto); //utiliza-se getline para captar toda a linha

    cout << texto;
}