/*
Os jogos de tabuleiro são aqueles que utilizam desenhos ou marcações feitas em uma
superfície, como quadros de madeira ou papelão. Além de ótimos passatempos, os jogos de
tabuleiro são muito importantes para o desenvolvimento cognitivo das pessoas, pensando
neste conceito você foi desafiado a implementar um programa na linguagem C++ que simule
um jogo de tabuleiro, com as seguintes regras:
- O jogo é composto de um peão (que representa o jogador) que será representado pela letra
“P”, um tabuleiro com 15 casas (espaços que o peão poderá percorrer durante o jogo) e um
dado com seis lados numerados de 1 à 6 (valores que poderão ser sorteados).
- Inicialmente as casas devem ser numeradas de forma aleatória com números entre 1 e 20
não sendo permitido números repetidos, exibindo o tabuleiro na tela e a letra P fora do
tabuleiro como demonstrado a seguir:
- Após pressionar uma tecla o jogo inicia com o sorteio de um número do dado (sorteio
aleatórios de um número entre 1 e 6) o número sorteado representa o número de casas que o
peão deve avançar. O valor contido onde o peão (P) parou deve ser acumulado e a casa deve
receber o valor zero, indicando que o valor já foi acumulado, ou seja, já é uma casa visitada.
- Após cada jogada o sistema deve exibir o número sorteado o valor acumulado até então e o
tabuleiro, na posição do peão deve ser exibido a letra “P”.
Número sorteado: 4
Acumulado: 19
Pressione qualquer tecla para continuar...
Número sorteado: 5
Acumulado: 39
Pressione qualquer tecla para continuar...
- Este processo deve se repetir até que o valor acumulado atinja 100 ou acima de 100 quando o
jogador é declarado vencedor e o sistema exibe a mensagem com o número de jogadas que
foram necessárias: “Parabéns você ganhou com X jogadas”.
- Caso o peão chegar ao final do tabuleiro deverá retornar ao início, por exemplo, se estiver na
penúltima casa e o número sorteado no dado foi o 3 o peão deverá ir para o início do tabuleiro
na segunda casa, conforme demonstra o exemplo a seguir:
Número sorteado: 3
- Caso o peão parar em uma casa que já foi visitada o programa deve exibir os dados já
descritos acima e também a seguinte mensagem: “Esta casa já foi visitada, você não acumulou
pontos” mas a jogada deverá ser contada.
*/
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <iomanip>

using namespace std;

// Função para inicializar o tabuleiro com valores únicos de 1 a 20
void inicializarTabuleiro(int* tabuleiro) {
    int* i = new int(0);
    int* j = new int(0);
    int* temp = new int(0);
    bool* unico = new bool(false);

    // Preenche as 15 casas usando aritmética de ponteiros
    for (*i = 0; *i < 15; (*i)++) {
        *unico = false;
        while (!(*unico)) {
            *temp = (rand() % 20) + 1; // Sorteia entre 1 e 20
            *unico = true;
            
            // Verifica se o número já existe no tabuleiro
            for (*j = 0; *j < *i; (*j)++) {
                if (*(tabuleiro + *j) == *temp) {
                    *unico = false;
                    break;
                }
            }
        }
        // Atribui o valor único à posição do tabuleiro
        *(tabuleiro + *i) = *temp;
    }

    // Liberação da memória
    delete i;
    delete j;
    delete temp;
    delete unico;
}

// Função para desenhar e exibir o tabuleiro e a posição do peão
void exibirTabuleiro(int* tabuleiro, int* pos_atual) {
    int* i = new int(0);

    // Verifica se o peão está fora do tabuleiro (início do jogo)
    if (*pos_atual == -1) {
        cout << "P ";
    } else {
        cout << "  ";
    }

    // Exibe as casas do tabuleiro usando aritmética de ponteiros
    for (*i = 0; *i < 15; (*i)++) {
        if (*pos_atual == *i) {
            cout << "|  P "; // Imprime o peão (P) se for a posição atual
        } else {
            // Imprime o valor da casa, formatado com espaço fixo para alinhamento
            cout << "| " << setw(2) << *(tabuleiro + *i) << " ";
        }
    }
    cout << "|\n";

    delete i; // Libera memória do iterador
}

// Função principal que controla o fluxo do jogo
void jogar() {
    // Alocação dinâmica para todo o estado do jogo (Nenhuma variável primitiva tradicional)
    int* tabuleiro = new int[15];
    int* pos_atual = new int(-1); // -1 indica que o peão está fora
    int* acumulado = new int(0);
    int* jogadas = new int(0);
    int* dado = new int(0);

    inicializarTabuleiro(tabuleiro);
    exibirTabuleiro(tabuleiro, pos_atual);

    cout << "Pressione qualquer tecla para continuar...\n";
    getchar(); // Pausa o sistema aguardando tecla

    // Loop de jogo enquanto não atinge 100 pontos
    while (*acumulado < 100) {
        *dado = (rand() % 6) + 1; // Sorteio do dado (1 a 6)
        (*jogadas)++;

        // Avança as casas. O uso de módulo (%) faz com que retorne ao início se passar do final.
        *pos_atual = (*pos_atual + *dado) % 15;

        cout << "\nNúmero sorteado: " << *dado << "\n";

        // Checa a casa visitada. 0 significa casa já percorrida
        if (*(tabuleiro + *pos_atual) == 0) {
            cout << "Acumulado: " << *acumulado << "\n";
            exibirTabuleiro(tabuleiro, pos_atual);
            cout << "Esta casa já foi visitada, você não acumulou pontos\n";
        } else {
            // Acumula os pontos e zera a casa atual
            *acumulado += *(tabuleiro + *pos_atual);
            *(tabuleiro + *pos_atual) = 0; 
            
            cout << "Acumulado: " << *acumulado << "\n";
            exibirTabuleiro(tabuleiro, pos_atual);
        }

        // Verifica a condição de vitória
        if (*acumulado >= 100) {
            cout << "Parabéns você ganhou com " << *jogadas << " jogadas\n";
            break;
        }

        cout << "Pressione qualquer tecla para continuar...\n";
        getchar();
    }

    // Liberação de memória de todo o estado dinâmico
    delete[] tabuleiro;
    delete pos_atual;
    delete acumulado;
    delete jogadas;
    delete dado;
}

int main() {
    jogar();
    return 0;
}