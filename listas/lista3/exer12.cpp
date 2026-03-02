#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>

/*12 – Escreva um programa que permita o cadastro de um aluno, contendo: nome, disciplina,
nota 1, nota 2, nota 3. O Programa deverá ter um menu com as seguintes opções:
0 – Sair
1 – Cadastrar
2 – Mostrar
3 – Calcular média (sabendo que a nota 1 tem peso 2 a nota 2 tem peso 3 e a nota 3 tem peso 5)*/
using namespace std;

struct cadastro{
    string nome;
    string disciplina;
    float nota [3];
};

main(){
    system("chcp 1252 > nul");

    int menu;
    cadastro c;
    float media = 0;
    bool alunoCadastrado = false;

    do{
        cout << "0 - Sair" <<endl;
        cout << "1 - Cadastrar" <<endl;
        cout << "2 - Mostrar" <<endl;
        cout << "3 - Cálcular média" <<endl;
        cout << "ESCOLHA UMA OPÇÃO: ";
        cin >> menu;

        switch (menu){
            case 0: //sair
                cout << "Encerrando programa..." << endl;
                break;
            
            case 1: //cadastro
                system("cls"); //limpa a tela
                cout << "Tela de cadastro" << endl;
                fflush (stdin);
                cout << "Informe seu nome: " << endl;
                getline (cin, c.nome);
                fflush (stdin);
                cout << "Informe a disciplina: " << endl;
                getline (cin, c.disciplina);
                fflush (stdin);
                cout << "Informe suas notas" << endl;
                cin >> c.nota[0] >> c.nota[1] >> c.nota[2];
                fflush (stdin);
                alunoCadastrado = true;
                break;
            case 2: //mostrar
                if (alunoCadastrado == true){
                    system("cls"); //limpa a tela
                    cout << "Mostrar informações" << endl;
                    cout << "Nome: " << c.nome <<endl;
                    cout << "Disciplina: " << c.disciplina <<endl;
                    cout << "Notas: " << c.nota[0] << ", " << c.nota[1] << ", " << c.nota[2];
                    cout << "Media: " << media;
                } else {
                    cout << "Favor, cadastrar-se primeiro" << endl;
                }
            case 3: //media
                if (alunoCadastrado == true){
                    system("cls"); //limpa a tela
                    cout << "Calculando media" << endl;
                    media = ((c.nota[0] * 2) + (c.nota[1] * 3) + (c.nota[2] * 5)) / 10;
                    cout << "A sua media em " << c.disciplina << " foi: " << media <<endl;
                    break;
                } else {
                    cout << "Favor, cadastrar-se primeiro" << endl;
                }
        }
    }
    while (menu != 0);
}