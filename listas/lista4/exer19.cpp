/*19 - Escreva um programa para manipular dois arquivos texto: vet1.txt e vet2.txt, ambos
contendo uma sequência não determinada de valores inteiros separados por ponto e vírgula. Ao
iniciar o programa os dados dos vetores devem ser carregados para a memória e o programa
deve apresentar um menu com as seguintes opções:
0 - Sair
1 – Incluir elemento no vetor 1 (insere um elemento no final do vetor e atualiza no respectivo
arquivo)
2 – Incluir elemento no vetor 2 (insere um elemento no final do vetor e atualiza no respectivo
arquivo)
3 – Intersecção (gerar um terceiro arquivo texto chamado vet3.txt que irá conter a intersecção
de vet1 e vet2, ou seja, os elementos que existem nos dois vetores.
Exemplo:
Sendo
vet1 = {41, 4, 37, 65, 63, 72, 39, 49, 82, 79}
vet2 = {71, 82, 39, 69, 62, 84, 53, 41, 77, 80, 18, 5}
vet3 irá conter {41, 39, 82}
4 – Mostrar Ordenado (mostrar os três vetores na tela, ordenado em ordem crescente e
separando cada elemento com uma vírgula).
OBS: as opções 3 e 4 só poderão ser acionadas se existir ao menos um elemento em cada um
dos vetores (vet1 e vet2), escolha de opção inválida no menu deverá mostra mensagem de
erro.*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <string>

using namespace std;

main(){
    system("chcp 1252 > nul");

    //incremento de vetores e contadores
    int menu;
    int vet1[100], vet2[100], vet3[100];
    int tam1 = 0, tam2 = 0, tam3 = 0;

    ifstream arq1("vet1.txt"); //criação de variavel para fluxo entre programa e arq txt
    if (arq1.is_open()){ // testa se o fluxo foi criado corretamente
        char temporario[10]; // vai pegar o "texto" e guardar temporariamente
        while(arq1.getline(temporario, 10, ';')){ //O laço while vai se repetir enquanto a função getline conseguir ler alguma coisa. 
            //A função getline lê o arquivo arq1 e guarda o que leu dentro da variável temporario
            //também le caractere por caractere até achar um ; (dps le de novo até achar outro ;)
            vet1[tam1] = atoi (temporario); //pega o "texto" e converte ele para número matemático 
            tam1++;
        }
        arq1.close();
    }

    ifstream arq2("vet2.txt");
    if (arq2.is_open()){
        char temporario[10];
        while(arq2.getline(temporario, 10, ';')){
            vet2[tam2] = atoi (temporario);
            tam2++;
        }
        arq2.close();
    }

    do{
        cout << "=== MENU ===";
        cout << "0 - Sair" << endl;
        cout << "1 - Incluir elemento no vetor 1" << endl;
        cout << "2 - Incluir elemento no vetor 2" << endl;
        cout << "3 - Intersecção" << endl;
        cout << "4 - Mostrar ordenado" << endl;
        cin >> menu;
        cin.ignore();

        switch (menu){
            case 0:{
                cout << "Encerrando programa... " << endl;
                break;
            }
            case 1:{
                cout << "Digite o número que queira acrescentar no vetor 1: " << endl;
                int novo;
                cin >> novo;
                cin.ignore();

                vet1[tam1] = novo;
                tam1++;

                ofstream escreve1("vet1.txt", ios::app);
                escreve1 << novo << ";";
                escreve1.close();

                cout << "Novo número adicionado ao seu vetor" << endl;
                break;
            }
            case 2:{
                cout << "Digite o número que queira acrescentar no vetor 2: " << endl;
                int novo;
                cin >> novo;
                cin.ignore();

                vet2[tam2] = novo;
                tam2++;

                ofstream escreve2 ("vet2.txt", ios::app);
                escreve2 << novo << ";";
                escreve2.close();

                cout << "Novo número adicionado ao seu vetor" << endl;
                break;
            }
            case 3:{
                if (tam1 == 0 || tam2 == 0){
                    cout << "Favor, cadastrar vetores antes" << endl;
                    break;
                } else {
                    tam3 = 0; //zerar para cada inicio de nova intersecção

                    for (int i = 0; i < tam1; i++){
                        for (int j = 0; j < tam2; j++){
                            if (vet1[i] == vet2[j]){
                                bool compativel = false;
                                for (int x; x < tam3; x++){
                                    if (vet3[x] == vet1[i]){
                                        compativel = true;
                                    }
                                }
                                if (!compativel){
                                    vet3[tam3] = vet1[i];
                                    tam3++;
                                }
                            }
                        }
                    }
                    ofstream escreve3("vet3.txt", ios::app);
                    for (int i = 0; i < tam3; i++){
                        escreve3 << vet3[i] << ";";
                    }
                    escreve3.close();

                    cout << "Arquivo com intersecção criado!" << endl;
                }
                break;
            }
            case 4:{
                if (tam1 == 0 || tam2 == 0){
                    cout << "Favor, preencher os vetores 1 e 2 primeiramanet" << endl;
                }
            }
        }

    } while (menu != 0);
}