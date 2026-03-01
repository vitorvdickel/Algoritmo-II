#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <cstring>
#include <cmath>
#include <iomanip>
/*
Uma palavra A é um anagrama de outra palavra B se podemos transformar a  palavra A na palavra B apenas trocando
de posição as letras da palavra A. Por exemplo,  "iracema" é um anagrama de "america", e "estudo" é um anagrama
de "duetos". Sabendo deste conceito escreva um programa que receba duas palavras diferentes  quaisquer e 
verifique se elas são um anagrama exibindo como resposta “SIM”, caso não  são um anagrama exibir “NÃO”.
*/
using namespace std;

main() {
    char palavraA[100];
    char palavraB[100];

    cin >> palavraA >> palavraB;

    //Se os tamanhos forem diferentes, não pode ser anagrama
    if (strlen(palavraA) != strlen(palavraB)) {
        cout << "NÃO" << endl;
        return 0;
    }

    //Contagem de frequência de caracteres
    int contagem[256] = {0};

    //Percorre as strings. 
    int tamanho = strlen(palavraA);
    for (int i = 0; i < tamanho; i++) {
        contagem[(unsigned char)palavraA[i]]++;
        contagem[(unsigned char)palavraB[i]]--;
    }

   //Verificação
    bool ehAnagrama = true;
    for (int i = 0; i < 256; i++) {
        if (contagem[i] != 0) {
            ehAnagrama = false;
            break;
        }
    }

    //Saída
    if (ehAnagrama) {
        cout << "SIM" << endl;
    } else {
        cout << "NÃO" << endl;
    }

    return 0;
}