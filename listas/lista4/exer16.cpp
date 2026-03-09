/* 16 – Escreva um programa que leia o nome completo de uma pessoa via entrada padrão
(teclado) a seguir o sistema deverá converter todos os caracteres para maiúsculo e escrever em
um arquivo texto chamado “nomes.txt” colocando cada nome em uma linha diferente, a seguir
solicitar se o usuário deseja incluir mais um nome, caso a resposta for “S” ou “s”, repetir o
processo, caso a resposta for qualquer outra deverá exibir o conteúdo do arquivo na tela.*/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <string>

using namespace std;

main(){
    system("chcp 1252 > nul");

    string nome;
    char continuar;

    do {
        ofstream escreve;
        escreve.open("nomes.txt", ios::app);

        if (escreve.is_open()) {
            cout << "Arquivo texto foi aberto com sucesso! " << endl;
            cout << "Informe um nome: " << endl;
            getline(cin, nome); 
            for (int x = 0; x < nome.size(); x++) {
                nome[x] = toupper(nome[x]);
            }
            escreve << nome << endl;
            escreve.close();

            cout << "Gostaria de acrescentar mais algum nome? S/N" << endl;
            cin >> continuar;

        } else {
            cout << "Erro ao abrir o arquivo." << endl;
            return 1;
        }

    } while (continuar == 's' || continuar == 'S');

    cout << "=== Conteúdo do arquivo texto ===" << endl;
    ifstream escreve("nomes.txt"); 
    string linha;

    if (escreve.is_open()) {
        while (getline(escreve, linha)) {
            cout << linha << endl;
        }
        escreve.close();
    } else {
        cout << "Não foi possivel abrir o arquivo" << endl;
    }
    return 0;
}
