#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>

using namespace std;

main(){
    system("chcp 1252 > nul");
    
    ofstream escreve;
    escreve.open("teste.txt", ios::out);
    string nome;

    if (escreve.is_open()){
        cout << "Arquivo aberto com sucesso." << endl;
        cout << "Informe um nome:" << endl;
        getline(cin, nome);
        cin.ignore();
        escreve << nome << endl;
        cout << "Nome informado: " << nome  << endl;
    } else {
        cout << "Erro ao executar o arquivo" << endl;
    }
    escreve.close();
}