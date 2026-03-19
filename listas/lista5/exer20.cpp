/*21- Faça um programa contendo:
- Uma função para ler um número inteiro não sendo aceito número menores que 1.
- Uma função que receba três números inteiros A, B e C. A função deverá somar todos os inteiros
entre B e C que sejam divisíveis por A (inclusive B e C) e retornar o resultado para ser exibido na
tela.
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <string>

using namespace std;

// Ler número inteiro maior que 1
int lerNumero(char texto[]) {
    int numero;
    do {
        cout << texto;
        cin >> numero;
        
        if (numero < 1) {
            cout << "Valor invalido! O numero deve ser maior ou igual a 1.\n";
        }
    } while (numero < 1);
    
    return numero;
}

// Soma inteiros divisiveis por a
int somarDivisiveis(int a, int b, int c) {
    int soma = 0;
    int inicio, fim;
    
    if (b < c) {
        inicio = b;
        fim = c;
    } else {
        inicio = c;
        fim = b;
    }
    
    for (int i = inicio; i <= fim; i++) {
        if (i % a == 0) {
            soma += i;
        }
    }
    
    return soma;
}

main() {
    int a, b, c, resultado;
    
    cout << "--- Soma de Divisiveis ---\n";
    
    a = lerNumero("Informe o valor de A (divisor): ");
    b = lerNumero("Informe o valor de B (limite 1): ");
    c = lerNumero("Informe o valor de C (limite 2): ");
    
    resultado = somarDivisiveis(a, b, c);
    
    cout << "A soma dos inteiros entre B e C divisiveis por A e: " << resultado << endl;
         
    return 0;
}