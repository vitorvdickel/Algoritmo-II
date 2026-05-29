//soma de dois números, variáveis globais e locais, constantes e diretivas de pré-processamento
#include <iostream>

using namespace std;

//variável global, ou seja, ela pode ser acessada por todas as funções do programa
//int t;

#define pi 3.14
#define curtir cout << "Curtiu?" << endl;   

int somar (int x, int y){
    //int t;
    //t = 1;
    int soma;
    soma = x + y;
    return soma;
}

int main(){

    float somaPi;

    // esse t é diferente do t da função somar, pois ele tem um escopo diferente, 
    //ou seja, ele é uma variável local da função main, enquanto o t da função somar é
    // uma variável local da função somar

    //int t;
    //t = 0;

    somar(5, 10);
    cout << "O valor da soma é: " << somar(5, 10) << endl;
    //cout << "O valor de t é: " << t << endl;

    somaPi = pi + 1;
    cout << somaPi << endl;
    curtir;

    return 0;
}