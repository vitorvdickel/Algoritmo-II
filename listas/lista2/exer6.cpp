#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <cstring>
#include <cmath>
#include <iomanip>

using namespace std;
/*
Escreva um programa que receba um texto qualquer do teclado, em seguida
apresente:
- O texto com todos os caracteres em maiúsculo V
- O texto com todos os caracteres em minúsculo 
- O Total de caracteres do texto
- O Total de vogais
- O Total de consoantes
- O Total de números
- O Total de espaços em branco
*/
main(){
    system ("chcp 1252 > nul");

    char texto[100];

    //Inserir texto
    cout << "Digite um texto qualquer: " <<endl;
    gets(texto);

    //imprime o texto com todos os caracteres em maiúsculo
    for (int x = 0; x <= strlen(texto); x++){
        texto[x] = toupper(texto[x]);
    }
    cout << texto << endl;

    //imprime o texto com todas as caracteres em minúsculo
    for (int x = 0; x <= strlen(texto); x++){
        texto[x] = tolower(texto[x]);
    }
    cout << texto << endl;

    //imprime o número de caracteres no texto
    int total = strlen(texto);
    cout << "Total de caracteres no texto é: " << total << endl;

    //imprime o número de vogais no texto
    int vogais = 0;
    for (int x = 0; x <= total; x++){
        if (texto[x] == 'a' || texto[x] == 'e' || texto[x] == 'i'
        || texto [x] == 'o' || texto [x] == 'u'){
            vogais++;
        }
    } cout << "O número de vogais é: " << vogais << endl;

    //contabiliza a quantidade de espaços no texto
    int espaco = 0;
    for(int x = 0; x <= strlen(texto); x++){
        if(isspace(texto[x])){
            espaco++;
        }
    }

    //verifica a quantidade de consoantes
    int consoante;
    consoante = total - vogais - espaco;
    cout << "O número de consoantes é: " << consoante <<endl;

    //verifica se há dígitos no texto
    int digito = 0;
    for(int x = 0; x <= strlen(texto); x++){
        if(isdigit(texto[x])){
            digito++;
        }
    }
    cout << "O texto possui um total de " << digito << " dígitos" <<endl;

    //apresenta o total de espaços no texto
    cout << "O texto possui " << espaco << " espaços" << endl;

    return 0;
}