// Funções com retorno e sem retorno
// Função com retorno: ela retorna um valor, ou seja, ela tem um tipo de retorno, como int, float, string, etc. Exemplo: int soma(int n1, int n2) { return n1 + n2; }
// Função sem retorno: ela não retorna nenhum valor, ou seja, ela tem o tipo de retorno void. Exemplo: void soma(int n1, int n2) { cout << n1 + n2; }
#include <iostream>

using namespace std;

void soma(int n1, int n2);
int soma2(int n1, int n2);
void tr(string tra[4]);

int main(){
    string transp[4] = {"carro", "moto", "aviao", "navio"};

    soma(5, 10);

    int resultadoSoma;
    resultadoSoma = soma2(5, 10);

    cout << "A soma de 5 e 10 é: " << resultadoSoma << endl;
    tr(transp);

    return 0;
}

void soma(int n1, int n2){
    int soma;
    soma = n1 + n2;
    cout << "A soma2 de " << n1 << " e " << n2 << " é: " << soma << endl;
}

int soma2(int n1, int n2){
    return n1 + n2;
}

void tr(string tra[4]){
    for (int i = 0; i < 4; i++){
        cout << tra[i] << endl;
    }
}