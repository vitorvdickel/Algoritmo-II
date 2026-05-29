//básico sobre funções em C++
#include <iostream>

using namespace std;

//não vai retornar nada, apenas imprimir algo na tela
void inscrever(){
    cout << "Inscreva-se no canal!" << endl;
}

//vai retornar um valor inteiro, que é a soma de x e y
int somar(int x, int y){
    int soma;
    soma = x + y;
    return soma;
}

int main(){

    inscrever();

    int a = 5, b = 10;
    int s;

    int resultadoSoma;
    resultadoSoma = somar(a, b);
    cout << "A soma de " << a << " e " << b << " é: " << resultadoSoma << endl;

    return 0;
}