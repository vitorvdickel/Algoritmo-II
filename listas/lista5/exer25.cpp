#include <iostream>
#include <fstream>
#include <cstring> // Para o strtok()
#include <cstdlib> // Para o atoi()
#include <iomanip> // Para o setw()

using namespace std;

// Função Auxiliar: Verifica se o valor já foi inserido na matriz
bool valorExiste(int matriz[5][5], int total_lidos, int valor) {
    for (int i = 0; i < total_lidos; i++) {
        // Converte o índice linear para linha e coluna da matriz 5x5
        int linha = i / 5;
        int coluna = i % 5;
        if (matriz[linha][coluna] == valor) {
            return true;
        }
    }
    return false;
}

// 1 - Ler valores para preencher a matriz do arquivo texto
void lerMatrizArquivo(int matriz[5][5], bool &preenchida) {
    ifstream arquivo("matriz.txt");

    if (!arquivo.is_open()) {
        cout << "\n[ERRO] Arquivo 'matriz.txt' nao encontrado!\n";
        return;
    }

    int total_lidos = 0;
    char linha_texto[1024]; // Buffer para ler a linha do arquivo

    // Lê as linhas do arquivo até encher as 25 posições ou acabar o arquivo
    while (arquivo.getline(linha_texto, 1024) && total_lidos < 25) {
        
        // strtok vai "fatiar" o texto toda vez que achar um ';'
        char *pedaco = strtok(linha_texto, ";");

        while (pedaco != NULL && total_lidos < 25) {
            int valor = atoi(pedaco); // Converte o texto fatiado em inteiro

            // Valida as restrições: tem que ser <= 50 e não pode ser repetido
            if (valor <= 50 && !valorExiste(matriz, total_lidos, valor)) {
                int l = total_lidos / 5;
                int c = total_lidos % 5;
                matriz[l][c] = valor;
                total_lidos++;
            }
            
            // Pede o próximo pedaço da mesma linha
            pedaco = strtok(NULL, ";");
        }
    }

    arquivo.close();

    // Valida se conseguiu ler 25 números de fato
    if (total_lidos == 25) {
        cout << "\n[SUCESSO] Matriz 5x5 preenchida corretamente a partir do arquivo!\n";
        preenchida = true;
    } else {
        cout << "\n[ERRO] O arquivo nao possui 25 valores validos.\n";
        cout << "Lembre-se: nao sao aceitos maiores que 50 nem valores repetidos.\n";
        cout << "Valores inseridos com sucesso: " << total_lidos << "/25\n";
        preenchida = false;
    }
}

// 2 - Mostrar a matriz gerada e sua respectiva matriz transposta
void mostrarMatrizETransposta(int matriz[5][5]) {
    cout << "\n--- MATRIZ GERADA ---" << endl;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << setw(3) << matriz[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\n--- MATRIZ TRANSPOSTA ---" << endl;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            // Imprime invertendo os índices de linha e coluna
            cout << setw(3) << matriz[j][i] << " "; 
        }
        cout << endl;
    }
}

// 3 – Diagonal Principal (elementos, acima e abaixo)
void mostrarDiagonalPrincipal(int matriz[5][5]) {
    cout << "\n--- ELEMENTOS DA DIAGONAL PRINCIPAL ---" << endl;
    for (int i = 0; i < 5; i++) {
        cout << matriz[i][i] << " ";
    }
    
    cout << "\n\n--- ACIMA DA DIAGONAL PRINCIPAL ---" << endl;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (j > i) cout << setw(3) << matriz[i][j] << " ";
            else cout << "    ";
        }
        cout << endl;
    }

    cout << "\n--- ABAIXO DA DIAGONAL PRINCIPAL ---" << endl;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (i > j) cout << setw(3) << matriz[i][j] << " ";
            else cout << "    ";
        }
        cout << endl;
    }
}

// 4 - Diagonal Secundária (elementos, acima e abaixo)
void mostrarDiagonalSecundaria(int matriz[5][5]) {
    cout << "\n--- ELEMENTOS DA DIAGONAL SECUNDARIA ---" << endl;
    for (int i = 0; i < 5; i++) {
        cout << matriz[i][4 - i] << " ";
    }

    cout << "\n\n--- ACIMA DA DIAGONAL SECUNDARIA ---" << endl;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (i + j < 4) cout << setw(3) << matriz[i][j] << " ";
            else cout << "    ";
        }
        cout << endl;
    }

    cout << "\n--- ABAIXO DA DIAGONAL SECUNDARIA ---" << endl;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (i + j > 4) cout << setw(3) << matriz[i][j] << " ";
            else cout << "    ";
        }
        cout << endl;
    }
}

int main() {
    int matriz[5][5];
    bool preenchida = false; // Controle de liberação das opções
    int opcao;

    do {
        cout << "\n======================================" << endl;
        cout << "           MENU DE MATRIZES           " << endl;
        cout << "======================================" << endl;
        cout << "1 - Preencher matriz via 'matriz.txt'" << endl;
        cout << "2 - Mostrar matriz e sua transposta" << endl;
        cout << "3 - Explorar Diagonal Principal" << endl;
        cout << "4 - Explorar Diagonal Secundaria" << endl;
        cout << "0 - Sair" << endl;
        cout << "Opcao desejada: ";
        cin >> opcao;

        switch(opcao) {
            case 1:
                lerMatrizArquivo(matriz, preenchida);
                break;
            case 2:
                if (preenchida) mostrarMatrizETransposta(matriz);
                else cout << "\n[AVISO] Execute a opcao 1 primeiro para preencher a matriz!\n";
                break;
            case 3:
                if (preenchida) mostrarDiagonalPrincipal(matriz);
                else cout << "\n[AVISO] Execute a opcao 1 primeiro para preencher a matriz!\n";
                break;
            case 4:
                if (preenchida) mostrarDiagonalSecundaria(matriz);
                else cout << "\n[AVISO] Execute a opcao 1 primeiro para preencher a matriz!\n";
                break;
            case 0:
                cout << "\nEncerrando o sistema...\n";
                break;
            default:
                cout << "\n[ERRO] Opcao invalida! Escolha um numero de 0 a 4.\n";
                break;
        }
    } while (opcao != 0);

    return 0;
}