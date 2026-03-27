#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int main() {
    // Abrindo os arquivos
    ifstream arquivo_entrada("nomes.txt");
    ofstream arquivo_saida("resultados.txt");

    // Verifica se deu algum erro ao abrir (boa prática básica)
    if (!arquivo_entrada.is_open() || !arquivo_saida.is_open()) {
        cout << "Erro ao abrir os arquivos!" << endl;
        return 1;
    }

    char linha[250]; // Usando vetor de char já que <string> não é permitida

    // Lendo o arquivo linha por linha até o final
    while (arquivo_entrada.getline(linha, 250)) {
        int soma_letras = 0;
        int tamanho_nome = strlen(linha);

        // Passa por cada letra do nome
        for (int i = 0; i < tamanho_nome; i++) {
            char letra = linha[i];

            // Transformando minúscula em maiúscula "na mão" pela tabela ASCII
            if (letra >= 'a' && letra <= 'z') {
                letra = letra - 32;
            }

            // Verificando o valor da letra na Tabela Pitagórica
            if (letra == 'A' || letra == 'J' || letra == 'S') {
                soma_letras = soma_letras + 1;
            } else if (letra == 'B' || letra == 'K' || letra == 'T') {
                soma_letras = soma_letras + 2;
            } else if (letra == 'C' || letra == 'L' || letra == 'U') {
                soma_letras = soma_letras + 3;
            } else if (letra == 'D' || letra == 'M' || letra == 'V') {
                soma_letras = soma_letras + 4;
            } else if (letra == 'E' || letra == 'N' || letra == 'W') {
                soma_letras = soma_letras + 5;
            } else if (letra == 'F' || letra == 'O' || letra == 'X') {
                soma_letras = soma_letras + 6;
            } else if (letra == 'G' || letra == 'P' || letra == 'Y') {
                soma_letras = soma_letras + 7;
            } else if (letra == 'H' || letra == 'Q' || letra == 'Z') {
                soma_letras = soma_letras + 8;
            } else if (letra == 'I' || letra == 'R') {
                soma_letras = soma_letras + 9;
            }
            // Espaços em branco serão simplesmente ignorados por não entrarem em nenhum if
        }

        // Somando os algarismos do resultado (Ex: 61 -> 6 + 1 = 7)
        int soma_final = 0;
        int valor_temporario = soma_letras;
        
        while (valor_temporario > 0) {
            soma_final = soma_final + (valor_temporario % 10);
            valor_temporario = valor_temporario / 10;
        }

        // Gravando no arquivo de saída no formato exigido
        arquivo_saida << linha << " = " << soma_final << "\n";
    }

    // Fechando os arquivos
    arquivo_entrada.close();
    arquivo_saida.close();

    // Mensagens exatas exigidas pelo exercício
    cout << "Arquivo nomes lido corretamente." << endl;
    cout << "Arquivo resultados gerado corretamente." << endl;

    return 0;
}