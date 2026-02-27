#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>

using namespace std;

struct valores{
    float add;
    float subs;
    float mult;
    float div;
};

main(){
    system("chcp 1252 > nul");

    valores n;
    float num1, num2;

    cout << "\n Insira o primeiro valor: " << endl;
    cin >> num1;
    fflush(stdin);

    cout << "\n Insira o segundo valor: " << endl;
    cin >> num2;
    fflush(stdin);

    n.add = num1 + num2;
    n.subs = num1 - num2;
    n.mult = num1 * num2;
    n.div = num1 / num2;

    system("cls"); //limpa a tela
    cout << "\n Soma = " << n.add << endl;
    cout << "\n Subtração = " << n.subs << endl;
    cout << "\n Multiplicação = " << n.mult << endl;
    cout << "\n Divisão = " << n.div << endl;

    return 0;
}