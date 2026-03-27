/*26 – Analise os dois arquivos em anexo Entrada.txt e Saída.txt, faça um programa que leia o
arquivo de entrada e gere o arquivo de saída, conforme esses dois modelos apresentados, abaixo
uma tabela da instrução de entrada e a respectiva saída:
Instrução Entrada Resultado da Saída
adiciona V1 10 O número 10 foi adicionado no vetor V1
adiciona V2 33 O número 33 foi adicionado no vetor V2
adiciona V2 5 O número 5 foi adicionado no vetor V2
mostra V1 C V1(C): 10
mostra V2 D V2(D): 33, 5
remove V2 33 O número 33 foi removido do vetor V2
remove V1 2 O número 2 não pode ser removido, pois não pertence ao vetor V1
adiciona V1 5 O número 5 foi adicionado no vetor V1
qtd V1 Total de elementos no vetor V1: 2
media V1 Media dos elementos do vetor V1: 7.5*/

#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int main() {
    // Vetores estáticos com um limite seguro (ex: 100 posições)
    int v1[100];
    int v2[100];
    int qtd1 = 0;
    int qtd2 = 0;

    ifstream entrada("Entrada.txt");
    ofstream saida("Saida.txt");

    if (!entrada.is_open() || !saida.is_open()) {
        cout << "Erro ao abrir os arquivos!" << endl;
        return 1;
    }

    char comando[20];

    // Lê a primeira palavra de cada linha
    while (entrada >> comando) {
        
        if (strcmp(comando, "adiciona") == 0) {
            char vetor[5];
            int valor;
            entrada >> vetor >> valor;

            if (strcmp(vetor, "V1") == 0) {
                v1[qtd1] = valor;
                qtd1++;
            } else if (strcmp(vetor, "V2") == 0) {
                v2[qtd2] = valor;
                qtd2++;
            }
            
            saida << "O número " << valor << " foi adicionado no vetor " << vetor << "\n";
        } 
        
        else if (strcmp(comando, "mostra") == 0) {
            char vetor[5];
            char ordem;
            entrada >> vetor >> ordem;

            int temp[100];
            int n = 0;

            // Copia os dados para um vetor temporário para podermos ordenar
            if (strcmp(vetor, "V1") == 0) {
                n = qtd1;
                for (int i = 0; i < n; i++) temp[i] = v1[i];
            } else if (strcmp(vetor, "V2") == 0) {
                n = qtd2;
                for (int i = 0; i < n; i++) temp[i] = v2[i];
            }

            // Ordenação Bolha (Bubble Sort)
            for (int i = 0; i < n - 1; i++) {
                for (int j = 0; j < n - i - 1; j++) {
                    if (ordem == 'C' && temp[j] > temp[j + 1]) {
                        int aux = temp[j];
                        temp[j] = temp[j + 1];
                        temp[j + 1] = aux;
                    } else if (ordem == 'D' && temp[j] < temp[j + 1]) {
                        int aux = temp[j];
                        temp[j] = temp[j + 1];
                        temp[j + 1] = aux;
                    }
                }
            }

            // Grava a saída no formato: V1(C): 10, 20
            saida << vetor << "(" << ordem << "): ";
            for (int i = 0; i < n; i++) {
                saida << temp[i];
                if (i < n - 1) saida << ", "; // Coloca vírgula menos no último
            }
            saida << "\n";
        } 
        
        else if (strcmp(comando, "remove") == 0) {
            char vetor[5];
            int valor;
            entrada >> vetor >> valor;

            bool achou = false;

            if (strcmp(vetor, "V1") == 0) {
                for (int i = 0; i < qtd1; i++) {
                    if (v1[i] == valor) {
                        achou = true;
                        // Puxa todos os elementos seguintes uma casa para a esquerda
                        for (int j = i; j < qtd1 - 1; j++) {
                            v1[j] = v1[j + 1];
                        }
                        qtd1--;
                        break; // Remove só a primeira ocorrência
                    }
                }
            } else if (strcmp(vetor, "V2") == 0) {
                for (int i = 0; i < qtd2; i++) {
                    if (v2[i] == valor) {
                        achou = true;
                        for (int j = i; j < qtd2 - 1; j++) {
                            v2[j] = v2[j + 1];
                        }
                        qtd2--;
                        break;
                    }
                }
            }

            if (achou) {
                saida << "O número " << valor << " foi removido do vetor " << vetor << "\n";
            } else {
                saida << "O número " << valor << " não pode ser removido, pois não pertence ao vetor " << vetor << "\n";
            }
        } 
        
        else if (strcmp(comando, "qtd") == 0) {
            char vetor[5];
            entrada >> vetor;

            if (strcmp(vetor, "V1") == 0) {
                saida << "Total de elementos no vetor V1: " << qtd1 << "\n";
            } else if (strcmp(vetor, "V2") == 0) {
                saida << "Total de elementos no vetor V2: " << qtd2 << "\n";
            }
        } 
        
        else if (strcmp(comando, "media") == 0) {
            char vetor[5];
            entrada >> vetor;

            float soma = 0;
            float media = 0;

            if (strcmp(vetor, "V1") == 0) {
                for (int i = 0; i < qtd1; i++) soma += v1[i];
                if (qtd1 > 0) media = soma / qtd1;
            } else if (strcmp(vetor, "V2") == 0) {
                for (int i = 0; i < qtd2; i++) soma += v2[i];
                if (qtd2 > 0) media = soma / qtd2;
            }

            saida << "Media dos elementos do vetor " << vetor << ": " << media << "\n";
        }
    }

    entrada.close();
    saida.close();

    cout << "Processamento concluido! Verifique o arquivo 'Saida.txt'." << endl;

    return 0;
}