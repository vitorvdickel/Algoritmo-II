/*14 - Crie um novo tipo de dado chamado “Aluno” com as seguintes informações:
nome: string
email: string
data de nascimento: string no formato dia/mês/ano (dd/mm/aaaa)
vetor de 5 notas: float
O programa deverá manipular este novo tipo de dado, apresentando um menu com as seguintes
opções:
0 – Sair
1 – Cadastrar
2 – Mostrar
3 – Calcular e exibir a média aritmética*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>

using namespace std;

struct aluno{
    string nome;
    string email;
    string dataNascimento;
    float notas[5];
};

bool validarData(string data){
    if (data.size() != 10) return false;
    if (data[2] != '/'||data[5] != '/') return false;

    for (int j = 0; j < 10; j++){
        if (j == 2 || j == 5) continue;
        if (!isdigit(data[j]))return false;
    }
    return true;
}

int main(){
    system("chcp 1252 > nul");

    int i = 0, cadastro;
    aluno v;
    bool dataValida;
    float soma = 0, media = 0;

    do {
        cout << "==== CALCULAR MÉDIA ARITMÉTICA DE NOTAS ====" << endl;
        cout << "0 - Sair" << endl;
        cout << "1 - Cadastrar" << endl;
        cout << "2 - Mostrar" << endl;
        cout << "Calcular e exibir a media aritmetica" << endl;
        cin >> cadastro;

        switch (cadastro){
            //SAIR
            case 0:
                cout << "Encerrando programa... " << endl;
                break;
            //CADASTRO
            case 1:
                system("cls");
                cout << "ÁREA DE CADASTRO!" << endl;
                fflush (stdin);
                cout << "Insira seu nome: " << endl;
                getline (cin, v.nome);
                fflush (stdin);
                cout << "Insira seu e-mail: " << endl;
                getline (cin, v.email);
                fflush (stdin);
                do{
                    cout << "Infome sua data de nascimento: " << endl;
                    getline (cin, v.dataNascimento);
                    dataValida = validarData(v.dataNascimento);
                    if (!dataValida){
                        cout << "Insira uma data válida" << endl;
                    }
                } while (!dataValida); // Repete enquanto a data for falsa 
                fflush (stdin);
                cout << "Informe as 5 notas: " << endl;
                for (int n = 0; n < 5; n++){
                    cout << "Nota " << n + 1 << ": ";
                    cin >> v.notas[n];
                }
                i++;
                cout << "Aluno cadastrado!" << endl;
                break;
            //MOSTRAR
            case 2:
            system("cls");
            if (i == 0){
                cout << "Nenhuma conta foi cadastrada" << endl;
            } else {
                cout << "DADOS CADASTRADOS" << endl;
                cout << "Nome do aluno: " << v.nome;
                cout << "E-mail: " << v.email;
                cout << "Data de nascimento: " << v.dataNascimento;
                cout << "Notas do aluno: " << endl;
                for (int n = 0; n < 5; n++){
                    cout << "- Nota" << n + 1 << ": " << v.notas[n] << endl;
                }
            }
            break;
            //CALCULAR MEDIA
            case 3:
            system("cls");
            if (i == 0){
                cout << "Nenhuma conta foi cadastrada" << endl;
            } else {
                cout << "Calculando media..." << endl;
                for (int n = 0; n < 5; n++){
                    soma = soma + v.notas[n];
                } 
                media = soma / 5;
                cout << "Media do aluno/a " << v.nome << " foi: " << media;
            }
            break;
        }       
    } while (cadastro != 0);
}