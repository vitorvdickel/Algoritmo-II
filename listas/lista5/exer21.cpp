/*22 - Escrever um programa, que através de funções realize as seguintes ações:
- Função para gerar um vetor V[20] com valores no intervalo de 0 a 100 sem números repetidos.
- Função para mostrar os valores gerados na tela separados por uma vírgula.
- Função que escreva os valores do vetor em um arquivo texto chamado “exer_22.txt”, separando
cada elemento por um espaço em branco.
- Função para ler posições do vetor (validar para aceitar 0 a 19).
Após o programa deverá ler duas posições do vetor e trocar os elementos destas posições e mostrar
o vetor após a troca e escrever o vetor atualizado no arquivo texto.*/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <string>

using namespace std;

// Função para gerar o vetor sem números repetidos
void gerarVetor(int V[], int tamanho) {
    int i = 0;
    while (i < tamanho) {
        int num = rand() % 101; // Gera números de 0 a 100
        bool repetido = false;
        
        // Verifica se o número já existe no vetor
        for (int j = 0; j < i; j++) {
            if (V[j] == num) {
                repetido = true;
                break;
            }
        }
        
        // Se não for repetido, adiciona na posição atual e avança
        if (!repetido) {
            V[i] = num;
            i++;
        }
    }
}

// Função para mostrar os valores na tela
void mostrarVetor(int V[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        cout << V[i];
        if (i < tamanho - 1) {
            cout << ", ";
        }
    }
    cout << endl;
}

// Função para escrever os valores em um arquivo de texto
void escreverArquivo(int V[], int tamanho, const char* nomeArquivo) {
    ofstream arquivo(nomeArquivo);
    
    if (arquivo.is_open()) {
        for (int i = 0; i < tamanho; i++) {
            arquivo << V[i];
            if (i < tamanho - 1) {
                arquivo << " ";
            }
        }
        arquivo.close();
        cout << "[Arquivo '" << nomeArquivo << "' atualizado com sucesso!]" << endl;
    } else {
        cout << "Erro ao tentar abrir o arquivo para escrita." << endl;
    }
}

// Função para ler e validar uma posição (0 a 19)
int lerPosicao() {
    int pos;
    do {
        cout << "Digite uma posicao (0 a 19): ";
        cin >> pos;
        if (pos < 0 || pos > 19) {
            cout << "Posicao invalida! Tente novamente." << endl;
        }
    } while (pos < 0 || pos > 19);
    return pos;
}

main() {
    int V[20];
    const char* nomeDoArquivo = "exer_22.txt";

    // 1. Gera e mostra o vetor original
    gerarVetor(V, 20);
    cout << "--- Vetor Original ---" << endl;
    mostrarVetor(V, 20);

    // 2. Escreve no arquivo texto
    escreverArquivo(V, 20, nomeDoArquivo);

    // 3. Lê duas posições válidas
    cout << "\n--- Troca de Elementos ---" << endl;
    cout << "Escolha a primeira posicao:" << endl;
    int pos1 = lerPosicao();
    
    cout << "Escolha a segunda posicao:" << endl;
    int pos2 = lerPosicao();

    // 4. Troca os elementos dessas posições
    int temp = V[pos1];
    V[pos1] = V[pos2];
    V[pos2] = temp;

    // 5. Mostra o vetor após a troca e atualiza o arquivo
    cout << "\n--- Vetor Apos a Troca ---" << endl;
    mostrarVetor(V, 20);
    escreverArquivo(V, 20, nomeDoArquivo);

    return 0;
}