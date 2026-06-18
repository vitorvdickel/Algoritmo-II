/*
60 – O Jogo do Bingo é um jogo muito popular entre grupos de amigos, consiste em uma
cartela contendo números em linhas e colunas e a cada jogada é sorteado um número, caso o
número sorteado esteja na cartela deve ser marcado, ganha quem conseguir completar
primeiro uma linha, ou uma coluna ou uma das diagonais.
Pensando neste conceito você foi desafiado a criar um programa que simule o jogo do bingo, o
qual deve seguir os seguintes critérios:
- Ao iniciar o programa deverá ser gerado 2 cartelas (A e B) contendo cada uma 5 linhas e 5 colunas. As
cartelas deverão ser preenchidas de forma pseudoaleatória com valores entre 1 e 75 (inclusive) não
podendo conter números repetidos. (0,4)
- As cartelas deverão ser exibidas na tela. (0,1)
- Deverá ser realizado o sorteio de um valor entre 1 e 75, este valor não pode ser repetido, caso ocorrer
deverá ser sorteado outro valor, quando for sorteado um número único, este deverá ser exibido na tela e
novamente exibido as duas cartelas, com os valores já sorteados sendo exibidos entre parênteses. (0,5)
- O jogo termina quando em uma das cartelas ou em ambas for preenchido toda uma linha, ou uma
coluna ou uma das diagonais, (exibir uma mensagem quando existir um ganhador) ou quando todos os
valores possíveis forem sorteados não havendo mais números únicos a serem sorteados, exibir uma
mensagem que todos os valores foram sorteados, indicando que não houve nenhum ganhador. (0,5)
*/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <iomanip>

using namespace std;

// Funcao para gerar os numeros da cartela (1 a 75, sem repeticao)
void gerarCartela(int* cartela) {
    int* i = new int(0); // Iterador para preencher a cartela usando aritmetica de ponteiros
    int* val = new int(0); // Variavel temporaria para armazenar o valor sorteado antes de ser colocado na cartela
    bool* repetido = new bool(false); // Flag para verificar se o valor sorteado ja existe na cartela, controlando o loop de sorteio
    int* j = new int(0); // Iterador para verificar a unicidade do valor sorteado, percorrendo a cartela usando aritmetica de ponteiros

    for (*i = 0; *i < 25; (*i)++) {
        *repetido = true; // Inicia como true para entrar no loop de sorteio, sera setado como false se o valor for unico
        while (*repetido) { // Loop para garantir que o valor sorteado seja unico na cartela
            *val = (rand() % 75) + 1; // Sorteia um valor entre 1 e 75
            *repetido = false; // Assume que o valor é unico, a seguir verificamos se ele realmente é
            
            // Verificacao de unicidade via aritmetica de ponteiro
            for (*j = 0; *j < *i; (*j)++) {
                if (*(cartela + *j) == *val) { // Se o valor ja existe na cartela, seta repetido como true para sortear outro valor
                    *repetido = true;
                    break;
                }
            }
        }
        *(cartela + *i) = *val; // Atribui o valor unico sorteado para a cartela usando aritmetica de ponteiros
    }

    delete i;
    delete val;
    delete repetido;
    delete j;
}

// Funcao para imprimir as cartelas e envelopar com parênteses as dezenas sorteadas
void imprimirCartelas(int* cA, bool* mA, int* cB, bool* mB) { // Recebe os vetores de cartela e marcacao para imprimir as cartelas formatadas
    int* i = new int(0);
    int* j = new int(0);
    
    cout << "--- CARTELA A ---\n";
    for (*i = 0; *i < 5; (*i)++) { // Loop para imprimir as linhas da cartela A
        for (*j = 0; *j < 5; (*j)++) { // Loop para imprimir as colunas da cartela A, acesso via expressao matematica e aritmetica de ponteiro
            // Acesso matriz via expressao matematica e aritmetica de ponteiro
            if (*(mA + (*i) * 5 + (*j))) { // Se a posicao estiver marcada, imprime o numero entre parenteses
                cout << "(" << setw(2) << *(cA + (*i) * 5 + (*j)) << ") "; // Imprime o numero formatado com parênteses e espaçamento para alinhamento
            } else {
                cout << " " << setw(2) << *(cA + (*i) * 5 + (*j)) << "  "; // Imprime o numero sem parênteses, mas com espaçamento para alinhamento
            }
        }
        cout << "\n";
    }
    
    cout << "\n--- CARTELA B ---\n";
    for (*i = 0; *i < 5; (*i)++) {
        for (*j = 0; *j < 5; (*j)++) {
            if (*(mB + (*i) * 5 + (*j))) {
                cout << "(" << setw(2) << *(cB + (*i) * 5 + (*j)) << ") ";
            } else {
                cout << " " << setw(2) << *(cB + (*i) * 5 + (*j)) << "  ";
            }
        }
        cout << "\n";
    }
    cout << "\n";

    delete i;
    delete j;
}

// Funcao que checa vitoria analisando linhas, colunas e diagonais
void verificarGanhador(bool* m, bool* ganhou) {
    *ganhou = false;
    int* i = new int(0);
    int* j = new int(0);
    bool* linha = new bool(true);
    bool* coluna = new bool(true);

    // 1. Verificacao de Linhas
    for (*i = 0; *i < 5; (*i)++) {
        *linha = true;
        for (*j = 0; *j < 5; (*j)++) {
            if (!(*(m + (*i) * 5 + (*j)))) {
                *linha = false;
                break;
            }
        }
        if (*linha) { *ganhou = true; break; }
    }

    // 2. Verificacao de Colunas
    if (!(*ganhou)) {
        for (*i = 0; *i < 5; (*i)++) {
            *coluna = true;
            for (*j = 0; *j < 5; (*j)++) {
                // Inversao na expressao: j avanca linhas mantendo a coluna i fixa
                if (!(*(m + (*j) * 5 + (*i)))) {
                    *coluna = false;
                    break;
                }
            }
            if (*coluna) { *ganhou = true; break; }
        }
    }

    // 3. Verificacao de Diagonais (Acesso direto por deslocamento no ponteiro)
    if (!(*ganhou)) {
        // Diagonal Principal (Indices: 0, 6, 12, 18, 24)
        if (*(m + 0) && *(m + 6) && *(m + 12) && *(m + 18) && *(m + 24)) {
            *ganhou = true;
        }
        // Diagonal Secundaria (Indices: 4, 8, 12, 16, 20)
        if (*(m + 4) && *(m + 8) && *(m + 12) && *(m + 16) && *(m + 20)) {
            *ganhou = true;
        }
    }

    delete i;
    delete j;
    delete linha;
    delete coluna;
}

// Funcao central que organiza a partida
void jogarBingo() {
    // Alocacao de toda a infraestrutura dinamica na memoria
    int* cartelaA = new int[25];
    int* cartelaB = new int[25];
    bool* marcadosA = new bool[25];
    bool* marcadosB = new bool[25];
    
    int* sorteados = new int[75];
    int* qtd_sorteados = new int(0);
    int* num_atual = new int(0);
    
    int* i = new int(0);
    bool* repetido = new bool(false);
    bool* fim_jogo = new bool(false);
    bool* ganhouA = new bool(false);
    bool* ganhouB = new bool(false);

    // Zerando matriz de marcadores
    for (*i = 0; *i < 25; (*i)++) {
        *(marcadosA + *i) = false;
        *(marcadosB + *i) = false;
    }

    gerarCartela(cartelaA);
    gerarCartela(cartelaB);

    cout << "=== BINGO INICIADO ===\n\n";
    cout << "Cartelas Iniciais:\n";
    imprimirCartelas(cartelaA, marcadosA, cartelaB, marcadosB);
    
    cout << "Pressione Enter para iniciar o sorteio continuo...\n";
    getchar();

    // Loop do sorteio
    while (!(*fim_jogo)) {
        // Garantir que a bola sorteada seja unica
        *repetido = true;
        while (*repetido) {
            *num_atual = (rand() % 75) + 1;
            *repetido = false;
            for (*i = 0; *i < *qtd_sorteados; (*i)++) {
                if (*(sorteados + *i) == *num_atual) {
                    *repetido = true;
                    break;
                }
            }
        }
        
        *(sorteados + *qtd_sorteados) = *num_atual;
        (*qtd_sorteados)++;

        cout << "--------------------------------\n";
        cout << "NUMERO SORTEADO: " << *num_atual << "\n\n";

        // Procura a pedra sorteada em ambas as cartelas
        for (*i = 0; *i < 25; (*i)++) {
            if (*(cartelaA + *i) == *num_atual) *(marcadosA + *i) = true;
            if (*(cartelaB + *i) == *num_atual) *(marcadosB + *i) = true;
        }

        // Reexibe as cartelas marcadas
        imprimirCartelas(cartelaA, marcadosA, cartelaB, marcadosB);

        // Verifica os criteiros de vitoria
        verificarGanhador(marcadosA, ganhouA);
        verificarGanhador(marcadosB, ganhouB);

        // Exibe as mensagens estritas de fim de jogo exigidas pela avaliacao
        if (*ganhouA && *ganhouB) {
            cout << "O jogo terminou! Houve um EMPATE, ambas as cartelas completaram uma linha, coluna ou diagonal simultaneamente.\n";
            *fim_jogo = true;
        } else if (*ganhouA) {
            cout << "O jogo terminou! A Cartela A completou uma linha, coluna ou diagonal e e a vencedora.\n";
            *fim_jogo = true;
        } else if (*ganhouB) {
            cout << "O jogo terminou! A Cartela B completou uma linha, coluna ou diagonal e e a vencedora.\n";
            *fim_jogo = true;
        } else if (*qtd_sorteados == 75) {
            cout << "O jogo terminou! Todos os valores possiveis foram sorteados e nao houve nenhum ganhador.\n";
            *fim_jogo = true;
        }
        
        // Pausa simulada para que o usuario possa ler a tela a cada rodada sorteada
        if (!(*fim_jogo)) {
            cout << "Pressione Enter para sacar a proxima pedra...\n";
            getchar();
        }
    }

    // Libera a memoria previnindo Memory Leak 
    delete[] cartelaA;
    delete[] cartelaB;
    delete[] marcadosA;
    delete[] marcadosB;
    delete[] sorteados;
    delete qtd_sorteados;
    delete num_atual;
    delete i;
    delete repetido;
    delete fim_jogo;
    delete ganhouA;
    delete ganhouB;
}

int main() {
    jogarBingo();
    return 0;
}