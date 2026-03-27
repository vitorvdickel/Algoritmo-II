/*24 - Faça um programa para ler de um arquivo texto chamado “temperaturas.txt” o qual possui
uma lista de 12 números float, um em cada linha, após ler armazenar em um vetor a temperatura
média de todos os meses do ano. A Seguir implemente as seguintes funções que devem ser
acionadas por um menu:
a) Menor temperatura do ano e em que mês ocorreu
b) Maior temperatura do ano e em que mês ocorreu
c) Temperatura média anual
d) O número de meses do ano em que a temperatura foi inferior a média anual*/

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

// Função a) Menor temperatura do ano e em que mês ocorreu
void exibirMenorTemperatura(float temperaturas[], char meses[][15]) {
    float menor_temp = temperaturas[0];
    int indice_menor = 0;

    for (int i = 1; i < 12; i++) {
        if (temperaturas[i] < menor_temp) {
            menor_temp = temperaturas[i];
            indice_menor = i;
        }
    }
    cout << "\n-> A MENOR temperatura foi " << menor_temp 
         << " graus no mes de " << meses[indice_menor] << "." << endl;
}

// Função b) Maior temperatura do ano e em que mês ocorreu
void exibirMaiorTemperatura(float temperaturas[], char meses[][15]) {
    float maior_temp = temperaturas[0];
    int indice_maior = 0;

    for (int i = 1; i < 12; i++) {
        if (temperaturas[i] > maior_temp) {
            maior_temp = temperaturas[i];
            indice_maior = i;
        }
    }
    cout << "\n-> A MAIOR temperatura foi " << maior_temp 
         << " graus no mes de " << meses[indice_maior] << "." << endl;
}

// Função c) Temperatura média anual
float calcularMedia(float temperaturas[]) {
    float soma = 0.0;
    for (int i = 0; i < 12; i++) {
        soma = soma + temperaturas[i];
    }
    return soma / 12.0;
}

// Função d) O número de meses do ano em que a temperatura foi inferior a média anual
int contarMesesAbaixoMedia(float temperaturas[], float media) {
    int meses_abaixo = 0;
    for (int i = 0; i < 12; i++) {
        if (temperaturas[i] < media) {
            meses_abaixo++;
        }
    }
    return meses_abaixo;
}

int main() {
    float temperaturas[12];
    
    char meses[12][15] = {
        "Janeiro", "Fevereiro", "Marco", "Abril", "Maio", "Junho",
        "Julho", "Agosto", "Setembro", "Outubro", "Novembro", "Dezembro"
    };

    ifstream arquivo("temperaturas.txt");

    if (!arquivo.is_open()) {
        cout << "Erro ao abrir o arquivo temperaturas.txt!" << endl;
        return 1;
    }

    for (int i = 0; i < 12; i++) {
        arquivo >> temperaturas[i];
    }
    arquivo.close();

    int opcao;

    do {
        cout << "\n===================================" << endl;
        cout << "        MENU DE TEMPERATURAS       " << endl;
        cout << "===================================" << endl;
        cout << "1 - Menor temperatura do ano (e mes)" << endl;
        cout << "2 - Maior temperatura do ano (e mes)" << endl;
        cout << "3 - Temperatura media anual" << endl;
        cout << "4 - Meses com temperatura inferior a media" << endl;
        cout << "0 - Sair" << endl;
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        // O switch agora fica muito mais limpo, apenas chamando as funções!
        switch(opcao) {
            case 1:
                exibirMenorTemperatura(temperaturas, meses);
                break;

            case 2:
                exibirMaiorTemperatura(temperaturas, meses);
                break;

            case 3: {
                float media = calcularMedia(temperaturas);
                cout << fixed << setprecision(2);
                cout << "\n-> A temperatura media anual e: " << media << " graus." << endl;
                break;
            }

            case 4: {
                // Precisamos calcular a média primeiro para poder comparar
                float media = calcularMedia(temperaturas);
                int abaixo = contarMesesAbaixoMedia(temperaturas, media);
                cout << "\n-> Existem " << abaixo 
                     << " meses com temperatura abaixo da media anual (" << fixed << setprecision(2) << media << ")." << endl;
                break;
            }

            case 0:
                cout << "\nEncerrando o programa..." << endl;
                break;

            default:
                cout << "\nOpcao invalida! Tente novamente." << endl;
                break;
        }

    } while (opcao != 0);

    return 0;
}