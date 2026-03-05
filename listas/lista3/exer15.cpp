/*15 – Escreva um programa que manipule um cardápio de um restaurante, com as seguintes
estruturas:
struct prato
{
 string ingredientes;
 string preparo;
 int calorias;
};
struct cardapio
{
 int codigo;
 string nome;
 prato x;
 float valor;
}
O sistema deverá permitir o cadastro de no máximo 20 itens no cardápio e deverá apresentar o
seguinte menu:
0 - Sair
1 – Incluir
2 – Mostrar cardápio (utilize um linha pontilhada entre um item e outro)
3 – Detalhar cardápio (recebe o código do cardápio e mostra os dados do referido cardápio)
4 – Mostrar cardápio mais caro;
5 – Mostrar cardápio com a menor quantidade de calorias;*/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>

using namespace std;

struct prato{
    string ingredientes;
    string preparo;
    int calorias;
};

struct cardapio{
    int codigo;
    string nome;
    prato x;
    float valor;
};

int main(){
    system("chcp 1252 > nul");

    int menu;
    char continuar;
    int buscarItem;
    int contador = 0;
    int maisCaro =  0;
    int menosCal = 0;
    bool achou = false;

    cardapio itens[20];

    do {
        cout << "\n ==== CARDÁPIO DO RESTAURANTE ====" << endl;
        cout << "0 - Sair" << endl;
        cout << "1 - Incluir" << endl;
        cout << "2 - Mostrar cardapio" << endl;
        cout << "3 - Detalhar cardapio" << endl;
        cout << "4 - Mostrar cardapio mais caro" << endl;
        cout << "5 - Mostrar cardapio com menor quantidade de calorias" << endl;
        cin >> menu;
        
        switch (menu){
            case 0: //sair
                cout << "Encerrando programa..." << endl;
                break;
            case 1: //incluir pedidos
            system("cls");
                if (contador >= 20){
                    cout << "Não é possivel adicionar mais itens ao seu cardapio!" << endl;
                } else {
                    do {
                        cout << "Adicionando itens ao seu cardapio" << contador +1 << endl;
                        fflush (stdin);
                        cout << "Codigo: " << endl;
                        cin >> itens[contador].codigo;
                        cin.ignore();
                        cout << "Nome do prato: " << endl;
                        getline (cin, itens[contador].nome);
                        fflush (stdin);
                        cout << "Igredientes: " << endl;
                        getline(cin, itens[contador].x.ingredientes);
                        fflush (stdin);
                        cout << "Modo de preparo: " << endl;
                        getline(cin, itens[contador].x.preparo);
                        fflush (stdin);
                        cout << "Calorias: " << endl;
                        cin >> itens[contador].x.calorias;
                        fflush (stdin);
                        cout << "Valor: " << endl;
                        cin >> itens[contador].valor;
                        contador++;
                        
                        if (contador < 20){
                        cout << "Gostaria de adicionar mais itens ao cardapio? S/N" << endl;
                        cin >> continuar;
                        } else {
                            continuar = 'n';
                        } if (continuar != 'S' && continuar != 's' && continuar != 'N' && continuar != 'n'){
                            cout << "Resposta incoerente, tente novamente: " << endl;
                            return 1;
                        }
                    } while (continuar == 'S' || continuar == 's');
                break;
                }
            case 2:
            system("cls");
                if (contador == 0){
                    cout << "Favor, primeiro incluir um item no cardapio" << endl;
                    break;
                } else {
                    cout << "Itens do cardapio: " << endl;
                    for (int i; i < contador; i++){
                        cout << "Código: " << itens[i].codigo << endl;
                        cout << "Nome do prato: " << itens[i].nome << endl;
                        cout << "Valor: R$" << itens[i].valor;
                        cout << "===================================" << endl;
                    }
                }
            case 3:
            system("cls");
                if (contador == 0){
                    cout << "Favor, primeiro incluir um item no cardapio" << endl;
                    break;
                } else {
                    cout << "Informe o código do item: " << endl;
                    cin >> buscarItem;
                    for (int i=0; i < contador; i++){
                        if (itens[i].codigo == buscarItem){
                            cout << "Código: " << itens[i].codigo << endl;
                            cout << "Nome do prato: " << itens[i].nome << endl;
                            cout << "Igredientes: " << itens[i].x.ingredientes << endl;
                            cout << "Modo de preparo: " << itens[i].x.preparo << endl;
                            cout << "Quantidade de calorias: " << itens[i].x.calorias << endl;
                            cout << "Valor: R$" << itens[i].valor;
                            achou = true;
                            break;
                        }
                    }
                    if (achou == false){
                        cout << "Item não encontrado no cardapio" << endl;
                        break;
                    }
                }
                break;
            case 4:
            system("cls");
                if (contador == 0){
                    cout << "Favor, primeiro incluir um item no cardapio" << endl;
                    break;
                } else {
                    cout << "Calculando cardapio mais caro..." << endl;
                    for (int i = 0; i < contador; i++){
                        if (itens[i].valor > itens[maisCaro].valor){
                            maisCaro = i;
                        }
                        cout << "Código: " << itens[maisCaro].codigo << endl;
                        cout << "Nome do prato: " << itens[maisCaro].nome << endl;
                        cout << "Igredientes: " << itens[maisCaro].x.ingredientes << endl;
                        cout << "Modo de preparo: " << itens[maisCaro].x.preparo << endl;
                        cout << "Quantidade de calorias: " << itens[maisCaro].x.calorias << endl;
                        cout << "Valor: R$" << itens[maisCaro].valor;
                    }
                    break;
                }
            case 5:
            system("cls");
                if (contador == 0){
                    cout << "Favor, primeiro incluir um item no cardapio" << endl;
                    break;
                } else {
                    cout << "Verificando cardapio com menor quantidade de calorias..." << endl;
                    for (int i =0; i < contador; i++){
                        if (itens[i].x.calorias < itens[menosCal].x.calorias){
                            menosCal = i;
                        }
                        cout << "Código: " << itens[menosCal].codigo << endl;
                        cout << "Nome do prato: " << itens[menosCal].nome << endl;
                        cout << "Igredientes: " << itens[menosCal].x.ingredientes << endl;
                        cout << "Modo de preparo: " << itens[menosCal].x.preparo << endl;
                        cout << "Quantidade de calorias: " << itens[menosCal].x.calorias << endl;
                        cout << "Valor: R$" << itens[menosCal].valor;
                    }
                }
        }
    } while (menu != 0);
        
}