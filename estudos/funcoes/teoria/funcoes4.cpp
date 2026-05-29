//sobrecarga de funções: mesma função, mesmo nome, parâmetros diferentes
#include <iostream>

using namespace std;

void soma();
void soma(int n1, int n2);

int main(){

    soma();
    soma(10, 20);

    return 0;
}

void soma(int n1, int n2){
    int resultado;
    resultado = n1 + n2;
    cout << "A soma de " << n1 << " e " << n2 << " é: " << resultado << endl;

}
void soma(){
    int n1, n2, resultado;
    n1 = 3;
    n2 = 4;
    resultado = n1 + n2;
    cout << "A soma de " << n1 << " e " << n2 << " é: " << resultado << endl;
}