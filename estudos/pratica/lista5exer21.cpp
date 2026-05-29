/*21- Faça um programa contendo:
- Uma função para ler um número inteiro não sendo aceito número menores que 1.
- Uma função que receba três números inteiros A, B e C. A função deverá somar todos os inteiros
entre B e C que sejam divisíveis por A (inclusive B e C) e retornar o resultado para ser exibido na
tela.*/

#include <iostream>

using namespace std;

int lerNumero(int &num);
int somar(int a, int b, int c);


int main(){

    int num;
    cout << "Digite um numero inteiro: ";
    cin >> num;
    num = lerNumero(num);
    cout << "Digite o valor de A: ";
    cin >> num;
    int a = num;
    cout << "Digite o valor de B: ";
    cin >> num;
    int b = num;
    cout << "Digite o valor de C: ";
    cin >> num;
    int c = num;
    int resultado = somar(a, b, c);
    cout << "A soma dos numeros divisiveis por " << a << " entre " << b << " e " << c << " e: " << resultado << endl;
    return 0;
}

int lerNumero(int &num){
    while(num < 1){
        cout << "Numero invalido, digite um numero inteiro: ";
        cin >> num;
    }
    return num;
}

// Função para somar os números divisíveis por A entre B e C
int somar(int a, int b, int c){
    int soma = 0;
    // Garantir que B seja o menor e C seja o maior
    for(int i = b; i <= c; i++){
        //Essa é a linha que toma a decisão. Ela usa o operador de resto da divisão (%), comumente chamado de módulo. O operador % retorna o 
        //resto da divisão de i por a. Se i for divisível por a, o resultado será 0. Portanto, a condição if(i % a == 0) verifica se i é um múltiplo de a.
        // Se for, o valor de i é adicionado à variável soma.
        if(i % a == 0){
            soma = soma + i;
        }
    }
    return soma;
}