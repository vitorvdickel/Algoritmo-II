/*5 - Em um jogo, um jogador avança em um tabuleiro seguindo as instruções representadas por um
vetor de inteiros. Cada elemento do vetor indica o número de casas que o jogador deve avançar
naquele momento. O jogador pode avançar para frente (se o valor for positivo) ou para trás (se o
valor for negativo podendo voltar no máximo a posição inicial). Escreva um programa que simule
esse jogo. O programa deve ler um vetor de inteiros de 20 posições representando as instruções e,
em seguida, inicial o jogo. Ao final de cada jogada, o programa deve exibir a posição atual do
jogador no tabuleiro. Para definir quantos movimentos o jogador dará em cada jogada, você deve
“criar” um dado de 1 a 6, ou seja, sortear um número randômico. Veja o exemplo:*/

#include <iostream>
#include <cstdlib> // Necessário para usar a função rand() do dado

using namespace std;

int main() {
    int tabuleiro[20];

    cout << "--- SIMULADOR DE JOGO DE TABULEIRO ---" << endl;
    cout << "Digite as 20 instrucoes do tabuleiro (valores inteiros separados por espaco):\n";
    
    // Lendo o vetor que representa o tabuleiro
    for(int i = 0; i < 20; i++) {
        cin >> tabuleiro[i];
    }

    int posicao = 0;
    int jogada = 1;

    cout << "\n--- INICIO DO JOGO ---\n";
    cout << "O jogador comeca na Posicao: 0\n";

    // O loop continua enquanto o jogador não chegar ou passar do índice 19 (final do tabuleiro)
    while (posicao < 19) {
        cout << "\n--- Jogada " << jogada << " ---" << endl;
        
        // Sorteando um número de 1 a 6
        int dado = (rand() % 6) + 1;
        cout << "Valor sorteado no dado: " << dado << endl;
        
        // Movendo o jogador com base no dado
        posicao = posicao + dado;
        
        // Verifica se só com o dado ele já venceu
        if (posicao >= 19) {
            posicao = 19;
            cout << "O jogador avancou para a casa 19." << endl;
            cout << "\nPARABENS! O jogador alcancou o final do tabuleiro e venceu!" << endl;
            break;
        }
        
        cout << "O jogador parou na casa " << posicao;
        
        // Lendo a instrução da casa onde ele caiu
        int instrucao = tabuleiro[posicao];
        
        if (instrucao > 0) {
            cout << " (Efeito: Avanca " << instrucao << " casas)" << endl;
        } else if (instrucao < 0) {
            cout << " (Efeito: Volta " << (instrucao * -1) << " casas)" << endl; // * -1 para imprimir o número positivo
        } else {
            cout << " (Efeito: Casa neutra, fica onde esta)" << endl;
        }
        
        // Aplicando a instrução da casa
        posicao = posicao + instrucao;
        
        // Regra do enunciado: não pode voltar antes da posição inicial
        if (posicao < 0) {
            posicao = 0;
            cout << "O jogador tentou voltar demais e bateu no inicio do tabuleiro." << endl;
        }
        
        // Regra de vitória: se a instrução jogar ele além do fim
        if (posicao >= 19) {
            posicao = 19;
            cout << "Posicao atual do jogador: " << posicao << endl;
            cout << "\nPARABENS! O jogador alcancou o final do tabuleiro e venceu!" << endl;
            break;
        }
        
        // Exibindo a posição final após o dado e o efeito da casa
        cout << "Posicao atual do jogador: " << posicao << endl;
        
        jogada++;
    }

    return 0;
}