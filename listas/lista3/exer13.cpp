#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>

/*Faça um programa que realize o cadastro de uma conta bancária com as seguintes
informações: número da conta, nome do cliente e saldo. O sistema deverá apresentar um menu
com as seguintes opções:
0 – Sair;
1 – Cadastrar contas;
2 – Visualizar dados da conta; (deve ser informado o número da conta)
3 – Depositar; (deve ser informado o número da conta e o valor a ser depositado)
4 – Sacar; (deve ser informado o número da conta e o valor a ser sacado, validar se o saque
pode ser realizado ou não)
5 – Realizar pix; (deve ser informado a conta de origem e a conta de destino, validar se o pix
pode ser realizado ou não, sendo possível deve diminuir o valor do pix do saldo da conta de
origem e adicionar ao saldo da conta de destino)*/

using namespace std;

struct cadastro{
    int nConta;
    string nome;
    float saldo;
};

main(){
    system("chcp 1252 > nul");

    cadastro v[3];
    int menu, i = 0, buscarConta;
    bool achou = false;
    float deposito, saque;

    do{
        cout << "=====MENU DO BRADESCO=====" << endl;
        cout << "0 - Sair" << endl;
        cout << "1 - Cadastrar contas" << endl;
        cout << "2 - Visualizar dados da conta" << endl;
        cout << "3 - Depositar" << endl;
        cout << "4 - Sacar" << endl;
        cout << "5 - Realizar pix" << endl;
        cin >> menu;

        switch (menu){
            case 0: //sair
                cout << "Encerrando programa..." << endl;
                break;
            case 1: //cadastro de conta
                system("cls"); //limpa a tela
                cout << "Cadastro de conta: " <<endl;
                cout << "Informe o número de sua conta: " <<endl; //informa o nome
                cin >> v[i].nConta;
                fflush (stdin);
                cout << "Infome o Nome das contas: " << endl; //informa o nome das contas
                getline (cin, v[i].nome);
                fflush (stdin);
                cout << "Informe o saldo nas contas: " << endl; //informa o saldo nas contas
                cin >> v[i].saldo;
                i++;
                break;
            case 2: //visualizar dados
                system("cls");
                if (i == 0){
                    cout << "Nenhuma conta encontrada!" << endl; // verifica a existencia de contas
                } else {
                    cout << "Informe o número da conta para visualiza-la: " << endl; //busca a conta já cadastrada
                    cin >> buscarConta;
                    for (int j=0; j < i; j++){
                        if (v[j].nConta == buscarConta) {
                            cout << "Número das contas: " << v[j].nConta << endl;
                            cout << "Nomes das contas: " << v[j].nome << endl;
                            cout << "Saldos em contas: " << v[j].saldo << endl;
                            cout << "==================" << endl;
                            achou == true;
                            break;
                    }
                }
                if (achou == false){
                    cout << "Conta não encontrada"; //caso digite errado
                }
            }
            break;
            case 3: //depositar
                system("cls");
                if (i == 0){
                    cout << "Nenhuma conta encontrada!" << endl; // verifica a existencia de contas
                } else {
                    bool achou = false;
                    cout << "DEPOSITO" << endl;
                    cout << "Informe o numero da conta: " << endl;
                    cin >> buscarConta;

                    for (int j; j < i; j++){
                        if (v[j].nConta == buscarConta){
                            cout << "Conta encontrada (Titular: " << v[j].nome << ")" << endl;
                            cout << "Valor do depósito: " << endl;
                            cin >> deposito;

                            v[j].saldo = v[j].saldo + deposito; //soma do novo saldo

                            cout << "Valor em conta: " << v[j].saldo;
                            achou = true;
                            break;
                        }
                    }
                if (achou == false){
                    cout << "Conta não encontrada"; //caso digite errado
                }    
            }
            case 4:
                system("cls");
                if (i == 0){
                    cout << "Nenhuma conta encontrada!" << endl; // verfica a existencia de contas
                } else {
                    bool achou = false;
                    cout << "SAQUE" << endl;
                    cout << "Informe o numero da conta: " <<endl;
                    cin >> buscarConta;

                    for (int j; j < i; j++){
                        if (v[j].nConta == buscarConta){
                            cout << "Conta encontrada (Titular: " << v[j].nome << ")" << endl;
                            cin >> saque;

                            v[j].saldo = v[j].saldo - saque; //remove o valor do saque da conta

                            cout << "Valor em conta: " << v[j].saldo;
                            achou = true;
                            break;
                        }
                    }
                if (achou == false){
                    cout << "Conta não encontrada"; //caso digite errado
                }
            }
            case 5: // Realizar pix (Versão Simplificada)
            system("cls");
            
            if (i == 0) {
                cout << "Nenhuma conta cadastrada!" << endl;
            } else {
                int origem, destino;
                float valorPix;
                int indOrigem = -1;
                int indDestino = -1;

                cout << "Numero da SUA conta (Origem): ";
                cin >> origem;
                cout << "Numero da conta de DESTINO: ";
                cin >> destino;
                cout << "Valor do Pix: R$ ";
                cin >> valorPix;

                for (int j = 0; j < i; j++) {
                    if (v[j].nConta == origem) indOrigem = j;
                    if (v[j].nConta == destino) indDestino = j;
                }

                if (indOrigem != -1 && indDestino != -1 && v[indOrigem].saldo >= valorPix && valorPix > 0) {
                    
                    v[indOrigem].saldo = v[indOrigem].saldo - valorPix;
                    v[indDestino].saldo = v[indDestino].saldo + valorPix;
                    
                    cout << "Pix de R$ " << valorPix << " realizado com sucesso!" << endl;
                    
                } else {
                    cout << "Erro! Verifique se as contas existem e se ha saldo suficiente." << endl;
                }
            }
            break;
        }
    }
    while (menu != 0);
}