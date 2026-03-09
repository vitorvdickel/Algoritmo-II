/*17 - Escreva um programa que leia 10 valores de um arquivo texto (exer_17.txt), separados por
um espaço, a seguir ordene esses valores em ordem crescente e escreva novamente no arquivo
os valores ordenados e separados por um espaço e apresente os seguintes resultados:
- Maior e menor valor
- Média dos valores
- Quantidade de números pares e ímpares
OBS: O arquivo deve existir (validar a abertura) e deverá conter no mínimo os 10 valores*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <string>

using namespace std;

main(){
    system("chcp 1252 > nul");

    cout << fixed;
    cout.precision(2);

    ifstream valoresEntrada;
    valoresEntrada.open("exer_17.txt", ios::in);
    int conteudo;

    int vetor[10];
    int contador = 0;

    if (valoresEntrada.is_open()){
        cout << "Arquivo aberto com sucesso!!" << endl;

        while (valoresEntrada >> conteudo){
            cout << conteudo << endl;
            if (contador < 10){
                vetor[contador] = conteudo;
                contador ++;
            }
        }
        valoresEntrada.close();

        for (int i =0; i < 9; i++){
            for (int j = 0; j < 9; j++){
                if (vetor[j] > vetor[j + 1]){
                    int aux = vetor[j];
                    vetor[j] = vetor [j + 1];
                    vetor [j + 1] = aux;
                }
            }
        }

        ofstream valoresSaida;
        valoresSaida.open("exer_17.txt", ios::out);
        for (int i = 0; i < 10; i++){
            valoresSaida << vetor[i];
            if (i < 9){
                valoresSaida << " ";
            }
        }
        valoresSaida.close();

        int menor = vetor[0];
        int maior = vetor[9];
        int soma = 0;
        int pares = 0;
        int impares = 0;

        for (int i = 0; i < 10; i++){
            soma += vetor[i];
            
            if (vetor[i] % 2 == 0){
                pares++;
            } else {
                impares++;
            }
        }

        float media = (float)soma / 10.0;

        cout << "\n--- Resultados ---" << endl;
        cout << "Maior valor: " << maior << endl;
        cout << "Menor valor: " << menor << endl;
        cout << "Media dos valores: " << media << endl;
        cout << "Quantidade de pares: " << pares << endl;
        cout << "Quantidade de impares: " << impares << endl;
        
    } else {
        cout << "Impossivel abrir o arquivo..." << endl;
        return 1;
    }
}