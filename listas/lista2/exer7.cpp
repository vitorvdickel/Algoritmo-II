#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <cstring>
#include <cmath>
#include <iomanip>
/*
Escreva um programa que recebe uma string qualquer do usuário e verifique se a  string forma um palíndromo.
Palíndromo é uma palavra, frase ou número que  permanece igual quando lida de trás para frente, sem considerar
acentos, hífen, espaços  em branco e independente de maiúsculas e minúsculas. 
São exemplos de palíndromos: radar, Renner, Roma é amor, orava o avaro, socorram me subi no ônibus em Marrocos. 
*/
using namespace std;

main(){
    system ("chcp 1252 > nul");
    
    char frase[100];
    char fraseLimpa[100];
    int j = 0;

    cout << "VERIFIQUE SE A FRASE FORMA UM PALÍNDROMO" <<endl;
    gets(frase);

    //pega a frase e remove hífen e espaços em branco
    int total = strlen(frase);

    for (int i = 0; i <= strlen(frase); i++){
        if (frase[i] != ' ' && frase[i] != '-'){
            fraseLimpa[j] =  tolower(frase[i]);
            j++;
        }
    }
    fraseLimpa[j]='\0';
    cout << "frase de comparação: " << fraseLimpa << endl;

    //verifica se é um palíndromo
    bool palindromo = true; //vai acreditando que é
    int tamanho = strlen(fraseLimpa);

    for (int i = 0; i <= tamanho / 2; i++){
        if (fraseLimpa[i] != fraseLimpa[tamanho - 1 - i]){
            palindromo = false;
            break;
        }
    }

    //retorno ao user
    if (palindromo == false){
        cout << "A frase não forma um palíndromo";
    } else {
        cout << "A frase é um palíndromo";
    }
    return 0;
}