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

main(){
    system("chcp 1252 > nul");
    int menu;
    ofstream agendaEntrada ("agenda.txt", ios::app);

    if(agendaEntrada.is_open()){
        cout << "Arquivo aberto com sucesso..." << endl;
        cout << "=== AGENDA TELEFONICA ===" << endl;
        cout << "0 - Sair" << endl;
        cout << "1 - Cadastrar contato" << endl;
        cout << "2 - Mostrar contatos" << endl;
        cout << "3 - Consultar" << endl;
        cout << "4 - Excluir" << endl;

        switch (menu){
            case 0:
            cout << "Encerrando programa..." << endl;
            break;
        }
    } else {
        cout << "Impossivel abrir o arquivo..." << endl;
        return 1;
    }
}