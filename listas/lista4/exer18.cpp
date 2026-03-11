/*18 – Escreva um programa para controlar uma agenda telefônica, os dados da agenda devem
ser carregados e atualizados em um arquivo texto chamado “agenda.txt”, onde em cada linha
deve estar o nome e o número do telefone separados por um ponto e vírgula. O programa
deverá apresentar um menu com as seguintes informações:
0 – Sair
1 – Cadastrar contato (não deve permitir números de telefone repetido)
2 – Mostrar contatos
3 – Consultar (informa o nome e apresenta os contatos do referido nome, pode haver mais de
um)
4 – Excluir (informa o número do telefone, caso exista, exclui do cadastro, caso contrário exibe
mensagem de contato inexistente)*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <string>

using namespace std;

struct contato{
    char nome[100];
    char numero [15];
};

main(){
    system("chcp 1252 > nul");
    int menu;
    contato agenda[100];
    int total = 0;

    ifstream ler ("agenda.txt");
    if (ler.is_open()){
        while (ler.getline(agenda[total].nome, 100, ';')){
            ler.getline(agenda[total].numero, 15);
            total++;
        }
        ler.close();
    }

    do{
        cout << "Arquivo aberto com sucesso..." << endl;
        cout << "=== AGENDA TELEFONICA ===" << endl;
        cout << "0 - Sair" << endl;
        cout << "1 - Cadastrar contato" << endl;
        cout << "2 - Mostrar contatos" << endl;
        cout << "3 - Consultar" << endl;
        cout << "4 - Excluir" << endl;
        cin >> menu;
        cin.ignore();

        switch (menu){
            //fechar tudo
            case 0:
            cout << "Encerrando programa..." << endl;
            break;
            //cadastrar ctt
            case 1: {
                cout << "Insira o nome do contato: " << endl;
                cin.getline(agenda[total].nome, 100);
                cout << "Insira o número de telefone: " << endl;
                cin.getline(agenda[total].numero, 15);
                //verificar repetição do número
                bool repetido = false;
                for (int i = 0; i < total; i++){
                    if (strcmp(agenda[i].numero, agenda[total].numero) == 0){
                        repetido = true;
                        break;
                    }
                }
                if (repetido){
                    cout << "Esse número de telefone já existe" << endl;
                } else {
                    total++;

                    ofstream arquivoEscrita("agenda.txt", ios::app);
                    if (arquivoEscrita.is_open()){
                        arquivoEscrita << agenda[total - 1].nome << ' - ' << agenda[total - 1].numero << endl;
                        arquivoEscrita.close();
                        cout << "Contato salvo com sucesso" << endl;
                    } else {
                        cout << "Erro ao abrir o arquivo" << endl;
                    }
                }
                break;
            }
            //mostrar contatos
            case 2:{
                if (agenda == 0){
                    cout << "Favor, cadastrar um número primeiro" << endl;
                    break;
                } else {
                for (int i = 0; i < total; i++){
                cout << agenda[i].nome << ';' << agenda[i].numero << endl;
                }
                }
            break;
            }
            //consultar
            case 3:{
                if (agenda == 0){
                    cout << "Favor, cadastrar um número primeiro" << endl;
                    break;
                } else {
                cout << "Qual nome você gostaria de buscar?" << endl;
                char buscar[100];
                cin.getline(buscar, 100);

                bool achou = false;
                for (int i = 0; i < total; i++){
                    if (strcmp(agenda[i].nome, buscar) == 0){
                        cout << "O contato de " << agenda[i].nome << " é " << agenda[i].numero << endl;
                        achou = true;  
                    }
                }
                if (!achou){
                    cout << "Nenhum contato encontrado com esse nome" << endl;
                }
                }
                break;
            }
            //excluir contato
            case 4:{
                if (agenda == 0){
                    cout << "Favor, cadastrar um número primeiro" << endl;
                    break;
                }else{
                cout << "Qual número você deseja excluir?" << endl;
                char excluir [15];
                cin.getline(excluir, 15);

                int posicao = -1;

                for (int i = 0; i < total; i++){
                    if (strcmp(agenda[i].numero, excluir) == 0){
                        posicao = i;
                    }
                }
                if (posicao != -1){
                    
                }
                }
            }
        }
    } while (menu != 0);
}