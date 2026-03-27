/*20 – Escreva um programa que gere de forma aleatória uma matriz 7 x 7 de números inteiros,
após gerar a matriz o programa deverá escreve os seguintes dados em um arquivo texto
chamado “exer_20.txt”:
- Os dados da matriz (no formato linha coluna)
- Os elementos das diagonais (principal e secundária)
- Os elementos acima da DP
- Os elementos abaixo da DP
- Os elementos de cada um dos quadrantes*/

#include <iostream>
#include <fstream>
#include <cstdlib> // Para o rand()
#include <iomanip> // Para o setw() alinhar os números da matriz no arquivo

using namespace std;

int main() {
    int matriz[7][7];
    
    // Criando o manipulador do arquivo de saída
    ofstream arquivo_saida("exer_20.txt");

    // Boa prática: sempre verificar se o arquivo abriu/criou corretamente
    if (!arquivo_saida.is_open()) {
        cout << "Erro ao criar o arquivo exer_20.txt!" << endl;
        return 1;
    }

    // 1. Preenchendo a matriz com números aleatórios (de 0 a 99 para formatar bem)
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7; j++) {
            matriz[i][j] = rand() % 100; 
        }
    }

    // 2. Gravando os dados da matriz (formato linha coluna)
    arquivo_saida << "--- DADOS DA MATRIZ 7x7 ---\n";
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7; j++) {
            arquivo_saida << setw(3) << matriz[i][j] << " ";
        }
        arquivo_saida << "\n";
    }

    // 3. Gravando a Diagonal Principal (i == j)
    arquivo_saida << "\n--- DIAGONAL PRINCIPAL ---\n";
    for (int i = 0; i < 7; i++) {
        arquivo_saida << matriz[i][i] << " ";
    }
    arquivo_saida << "\n";

    // 4. Gravando a Diagonal Secundaria (i + j == N - 1)
    arquivo_saida << "\n--- DIAGONAL SECUNDARIA ---\n";
    for (int i = 0; i < 7; i++) {
        arquivo_saida << matriz[i][6 - i] << " ";
    }
    arquivo_saida << "\n";

    // 5. Gravando os elementos acima da DP (j > i)
    arquivo_saida << "\n--- ELEMENTOS ACIMA DA DIAGONAL PRINCIPAL ---\n";
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7; j++) {
            if (j > i) {
                arquivo_saida << matriz[i][j] << " ";
            }
        }
    }
    arquivo_saida << "\n";

    // 6. Gravando os elementos abaixo da DP (i > j)
    arquivo_saida << "\n--- ELEMENTOS ABAIXO DA DIAGONAL PRINCIPAL ---\n";
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7; j++) {
            if (i > j) {
                arquivo_saida << matriz[i][j] << " ";
            }
        }
    }
    arquivo_saida << "\n";

    // 7. Gravando os Quadrantes (ignorando a linha 3 e coluna 3 que formam o centro)
    arquivo_saida << "\n--- QUADRANTES ---\n";
    
    arquivo_saida << "Quadrante 1 (Superior Esquerdo):\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            arquivo_saida << setw(3) << matriz[i][j] << " ";
        }
        arquivo_saida << "\n";
    }

    arquivo_saida << "\nQuadrante 2 (Superior Direito):\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 4; j < 7; j++) {
            arquivo_saida << setw(3) << matriz[i][j] << " ";
        }
        arquivo_saida << "\n";
    }

    arquivo_saida << "\nQuadrante 3 (Inferior Esquerdo):\n";
    for (int i = 4; i < 7; i++) {
        for (int j = 0; j < 3; j++) {
            arquivo_saida << setw(3) << matriz[i][j] << " ";
        }
        arquivo_saida << "\n";
    }

    arquivo_saida << "\nQuadrante 4 (Inferior Direito):\n";
    for (int i = 4; i < 7; i++) {
        for (int j = 4; j < 7; j++) {
            arquivo_saida << setw(3) << matriz[i][j] << " ";
        }
        arquivo_saida << "\n";
    }

    // Fechando o arquivo
    arquivo_saida.close();

    // Mensagem final na tela para o usuário saber que rodou tudo certo
    cout << "Processamento concluido! Verifique o arquivo 'exer_20.txt' na pasta." << endl;

    return 0;
}