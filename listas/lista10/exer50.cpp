#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

struct Contato
{
    char nome[50];
    char telefone[20];
};

int contarContatos(char arquivoNome[])
{
    ifstream arquivo(arquivoNome);

    if (!arquivo)
    {
        return 0;
    }

    int contador = 0;
    Contato c;

    while (arquivo >> c.nome >> c.telefone)
    {
        contador++;
    }

    arquivo.close();

    return contador;
}

void carregarContatos(char arquivoNome[], Contato *contatos, int quantidade)
{
    ifstream arquivo(arquivoNome);

    Contato *p = contatos;

    for (int i = 0; i < quantidade; i++)
    {
        arquivo >> p->nome >> p->telefone;
        p++;
    }

    arquivo.close();
}

void salvarContatos(char arquivoNome[], Contato *contatos, int quantidade)
{
    ofstream arquivo(arquivoNome);

    Contato *p = contatos;

    for (int i = 0; i < quantidade; i++)
    {
        arquivo << p->nome << " " << p->telefone;

        if (i < quantidade - 1)
        {
            arquivo << endl;
        }

        p++;
    }

    arquivo.close();
}

void mostrarContatos(Contato *contatos, int quantidade)
{
    if (quantidade == 0)
    {
        cout << "Agenda vazia!" << endl;
        return;
    }

    Contato *p = contatos;

    for (int i = 0; i < quantidade; i++)
    {
        cout << "Nome: " << p->nome << endl;
        cout << "Telefone: " << p->telefone << endl;
        cout << endl;

        p++;
    }
}

int telefoneExiste(Contato *contatos, int quantidade, char telefone[])
{
    Contato *p = contatos;

    for (int i = 0; i < quantidade; i++)
    {
        if (strcmp(p->telefone, telefone) == 0)
        {
            return 1;
        }

        p++;
    }

    return 0;
}

void consultarContato(Contato *contatos, int quantidade, char nome[])
{
    int encontrado = 0;

    Contato *p = contatos;

    for (int i = 0; i < quantidade; i++)
    {
        if (strcmp(p->nome, nome) == 0)
        {
            cout << "Nome: " << p->nome << endl;
            cout << "Telefone: " << p->telefone << endl;
            cout << endl;

            encontrado = 1;
        }

        p++;
    }

    if (!encontrado)
    {
        cout << "Contato nao encontrado!" << endl;
    }
}

void excluirContato(Contato *contatos, int &quantidade, char telefone[])
{
    int encontrado = 0;

    for (int i = 0; i < quantidade; i++)
    {
        if (strcmp((contatos + i)->telefone, telefone) == 0)
        {
            encontrado = 1;

            for (int j = i; j < quantidade - 1; j++)
            {
                *(contatos + j) = *(contatos + j + 1);
            }

            quantidade--;

            cout << "Contato removido!" << endl;

            break;
        }
    }

    if (!encontrado)
    {
        cout << "Contato inexistente!" << endl;
    }
}

int main()
{
    char arquivoNome[] = "agenda.txt";

    int quantidade = contarContatos(arquivoNome);

    Contato *contatos = new Contato[quantidade + 100];

    carregarContatos(arquivoNome, contatos, quantidade);

    int opcao;

    do
    {
        cout << "\n0 - Sair" << endl;
        cout << "1 - Cadastrar contato" << endl;
        cout << "2 - Mostrar contatos" << endl;
        cout << "3 - Consultar contato" << endl;
        cout << "4 - Excluir contato" << endl;

        cout << "\nOpcao: ";
        cin >> opcao;

        switch (opcao)
        {
            case 1:
            {
                char nome[50];
                char telefone[20];

                cout << "Digite o nome: ";
                cin >> nome;

                cout << "Digite o telefone: ";
                cin >> telefone;

                if (telefoneExiste(contatos, quantidade, telefone))
                {
                    cout << "Telefone ja cadastrado!" << endl;
                }
                else
                {
                    strcpy((contatos + quantidade)->nome, nome);
                    strcpy((contatos + quantidade)->telefone, telefone);

                    quantidade++;

                    salvarContatos(arquivoNome, contatos, quantidade);

                    cout << "Contato cadastrado!" << endl;
                }

                break;
            }

            case 2:
            {
                mostrarContatos(contatos, quantidade);
                break;
            }

            case 3:
            {
                char nome[50];

                cout << "Digite o nome: ";
                cin >> nome;

                consultarContato(contatos, quantidade, nome);

                break;
            }

            case 4:
            {
                char telefone[20];

                cout << "Digite o telefone: ";
                cin >> telefone;

                excluirContato(contatos, quantidade, telefone);

                salvarContatos(arquivoNome, contatos, quantidade);

                break;
            }

            case 0:
            {
                cout << "Programa encerrado!" << endl;
                break;
            }

            default:
            {
                cout << "Opcao invalida!" << endl;
            }
        }

    } while (opcao != 0);

    delete[] contatos;

    return 0;
}