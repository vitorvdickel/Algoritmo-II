/*3 - Elabore um programa que apresente um menu com as seguintes opções:
0 - Sair
1 – Potenciação (entrada dois valores inteiros e positivos)
2 – Raiz quadrada (entrada um valor inteiro e positivo)
3 - Arredondar o valor seguindo o critério da primeira casa decimal e mostrar na tela
(entrada um valor float)
4 – Verificar se um valor é primo ou não (entrada um valor inteiro positivo)
5 – Verificar se um valor é um número perfeito ou não (entrada um valor inteiro positivo).
Conforme a opção desejada será solicitado os dados de entrada necessários em cada uma das
opções.*/

#include <iostream>
#include <cmath> // Para pow(), sqrt() e round()

using namespace std;

int main() {
    int opcao;

    // Variáveis que serão usadas dentro do switch
    int base, expoente, valor_int;
    float valor_float;
    int divisores, soma_divisores;

    do {
        cout << "         MENU PRINCIPAL        " << endl;
        cout << "0 - Sair" << endl;
        cout << "1 - Potenciacao" << endl;
        cout << "2 - Raiz quadrada" << endl;
        cout << "3 - Arredondar valor" << endl;
        cout << "4 - Verificar numero primo" << endl;
        cout << "5 - Verificar numero perfeito" << endl;
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        switch (opcao) {
            case 0:
                cout << "Encerrando o programa..." << endl;
                break;

            case 1:
                cout << "\n--- Potenciacao ---" << endl;
                cout << "Digite a base (inteiro e positivo): ";
                cin >> base;
                while (base < 0) { cout << "Invalido! Digite um valor >= 0: "; cin >> base; }

                cout << "Digite o expoente (inteiro e positivo): ";
                cin >> expoente;
                while (expoente < 0) { cout << "Invalido! Digite um valor >= 0: "; cin >> expoente; }

                // pow() retorna um double, mas o cout exibe perfeitamente
                cout << "Resultado: " << pow(base, expoente) << endl;
                break;

            case 2:
                cout << "\n--- Raiz Quadrada ---" << endl;
                cout << "Digite um valor (inteiro e positivo): ";
                cin >> valor_int;
                while (valor_int < 0) { cout << "Invalido! Digite um valor >= 0: "; cin >> valor_int; }

                cout << "Raiz quadrada: " << sqrt(valor_int) << endl;
                break;

            case 3:
                cout << "\n--- Arredondamento ---" << endl;
                cout << "Digite um valor quebrado (float): ";
                cin >> valor_float;

                cout << "Valor arredondado: " << round(valor_float) << endl;
                break;

            case 4:
                cout << "\n--- Verificador de Numero Primo ---" << endl;
                cout << "Digite um valor (inteiro e positivo): ";
                cin >> valor_int;
                while (valor_int <= 0) { cout << "Invalido! Digite um valor > 0: "; cin >> valor_int; }

                divisores = 0;
                // Conta quantos divisores o número tem
                for (int i = 1; i <= valor_int; i++) {
                    if (valor_int % i == 0) {
                        divisores++;
                    }
                }

                if (divisores == 2) {
                    cout << valor_int << " e um numero PRIMO!" << endl;
                } else {
                    cout << valor_int << " NAO e um numero primo." << endl;
                }
                break;

            case 5:
                cout << "\n--- Verificador de Numero Perfeito ---" << endl;
                cout << "Digite um valor (inteiro e positivo): ";
                cin >> valor_int;
                while (valor_int <= 0) { cout << "Invalido! Digite um valor > 0: "; cin >> valor_int; }

                soma_divisores = 0;
                // Soma todos os divisores do número, exceto ele mesmo (por isso i < valor_int)
                for (int i = 1; i < valor_int; i++) {
                    if (valor_int % i == 0) {
                        soma_divisores = soma_divisores + i;
                    }
                }

                if (soma_divisores == valor_int) {
                    cout << valor_int << " e um numero PERFEITO!" << endl;
                } else {
                    cout << valor_int << " NAO e um numero perfeito." << endl;
                }
                break;

            default:
                cout << "Opcao invalida! Tente novamente." << endl;
                break;
        }

    } while (opcao != 0);

    return 0;
}