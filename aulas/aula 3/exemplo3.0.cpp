#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>

using namespace std;

struct cadastro{
    int matricula;
    string nome;
    float salario;
    int idade;
};

main(){
    system("chcp 1252 > nul");

    cadastro v[5];

    int i;

    cout << "\n Informe o número da matrícula: " << endl;
    cin >> v[i].matricula;
    fflush(stdin); //limpa o buffer do teclado

    cout << "\n Informe o seu nome: " << endl;
    getline(cin, v[i].nome);
    fflush(stdin); //limpa o buffer do teclado
    
    cout << "\n Informe o seu salário: " << endl;
    cin >> v[i].salario;

    cout << "\n Informe sua idade: " << endl;
    cin >> v[i].idade;

    system("cls"); //limpa a tela
    for (i = 0; i < 5; i++){
        cout << "Matricula: " << v[i].matricula << endl;
        cout << "Nome: " << v[i].nome << endl;
        cout << "Salário com 10%: " << v[i].salario + ((10.0 / 100.0) * v[i].salario)<< endl;
        cout << "Idade: " << v[i].idade << endl;
    }

    if (v[i].idade < 18){
        cout << "\n menor de idade";
    } else {
        cout << "\n maior de idade";
    }
    cout << "\n =========================================" << endl << endl;
}