#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <string>

using namespace std;

// Função 1: Formatar para 2 casas decimais
float formata(float n) {
    int temp = (int)(n * 100.0 + 0.5); 
    return (float)temp / 100.0;
}

// Função 2: Gerar vetor pseudoaleatório sem repetição no intervalo
void gera_vetor(int v[], int menor, int maior) {
    // Validação usando o tamanho fixo 10 diretamente
    if (maior - menor + 1 < 10) {
        cout << "[Erro] Intervalo muito pequeno para gerar 10 numeros sem repeticao." << endl;
        return;
    }

    int i = 0;
    while (i < 10) {
        int num = menor + rand() % (maior - menor + 1);
        bool repetido = false;
        
        for (int j = 0; j < i; j++) {
            if (v[j] == num) {
                repetido = true;
                break;
            }
        }
        
        if (!repetido) {
            v[i] = num;
            i++;
        }
    }
}

// Função 3: Ordenar vetor (Bubble Sort)
void ordena_vetor(int v[], char ordem) {
    for (int i = 0; i < 10 - 1; i++) {
        for (int j = 0; j < 10 - i - 1; j++) {
            if (ordem == 'c' || ordem == 'C') { 
                if (v[j] > v[j + 1]) {
                    int temp = v[j];
                    v[j] = v[j + 1];
                    v[j + 1] = temp;
                }
            } else if (ordem == 'd' || ordem == 'D') { 
                if (v[j] < v[j + 1]) {
                    int temp = v[j];
                    v[j] = v[j + 1];
                    v[j + 1] = temp;
                }
            }
        }
    }
}

// Função 4: Retorna true se for primo
bool primo(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; i++) { 
        if (n % i == 0) return false;
    }
    return true;
}

// Função 5: Retorna true se for número perfeito
bool perfeito(int n) {
    if (n <= 1) return false;
    int soma = 0;
    for (int i = 1; i < n; i++) {
        if (n % i == 0) {
            soma += i;
        }
    }
    return soma == n;
}

main() {
    int opcao;
    int vetor[10]; // Tamanho fixo 10 declarado diretamente
    bool vetor_gerado = false;

    do {
        cout << "=== MENU DE OPCOES ===" << endl;
        cout << "1. Formatar numero real (2 casas)" << endl;
        cout << "2. Gerar vetor sem repeticao" << endl;
        cout << "3. Ordenar vetor" << endl;
        cout << "4. Verificar numero primo" << endl;
        cout << "5. Verificar numero perfeito" << endl;
        cout << "0. Sair" << endl;
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        switch(opcao) {
            case 1: {
                float num;
                cout << "Digite um numero real (ex: 3.14159): ";
                cin >> num;
                cout << "-> Numero formatado: " << formata(num) << endl;
                break;
            }
            case 2: {
                int menor, maior;
                cout << "Digite o valor minimo do intervalo: ";
                cin >> menor;
                cout << "Digite o valor maximo do intervalo: ";
                cin >> maior;
                
                gera_vetor(vetor, menor, maior);
                vetor_gerado = true;
                
                cout << "-> Vetor gerado: ";
                for(int i = 0; i < 10; i++) cout << vetor[i] << " ";
                cout << endl;
                break;
            }
            case 3: {
                if (!vetor_gerado) {
                    cout << "-> [Aviso] Gere o vetor (opcao 2) primeiro!" << endl;
                    break;
                }
                char ordem;
                cout << "Digite a ordem (c - crescente, d - decrescente): ";
                cin >> ordem;
                
                ordena_vetor(vetor, ordem);
                
                cout << "-> Vetor ordenado: ";
                for(int i = 0; i < 10; i++) cout << vetor[i] << " ";
                cout << endl;
                break;
            }
            case 4: {
                int num;
                cout << "Digite um numero inteiro: ";
                cin >> num;
                if (primo(num)) cout << "-> " << num << " eh um numero primo." << endl;
                else cout << "-> " << num << " NAO eh um numero primo." << endl;
                break;
            }
            case 5: {
                int num;
                cout << "Digite um numero inteiro: ";
                cin >> num;
                if (perfeito(num)) cout << "-> " << num << " eh um numero perfeito." << endl;
                else cout << "-> " << num << " NAO eh um numero perfeito." << endl;
                break;
            }
            case 0:
                cout << "Encerrando o programa..." << endl;
                break;
            default:
                cout << "-> Opcao invalida! Tente novamente." << endl;
        }
    } while(opcao != 0);

    return 0;
}