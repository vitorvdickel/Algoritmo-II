/*58  -  Crie  um  programa  que  manipule  através  de  alocação  dinâmica  e  ponteiros  três  vetores 
VG[X], VE[X] e VN[X] de X posições de números inteiros (a dimensão do vetor é definido pelo 
usuário do sistema ao iniciar o programa, não sendo permitido vetor maior que 20 e menor que 
10 posições, validar a dimensão dos vetores), o programa deverá apresentar um menu com as 
seguintes opções: 
0 – Sair 
1  –  Gerar  valores  para  os  vetores  (gerar  valores  randomicamente  entre  1  e  N  (inclusive)  sem 
repetição (Ler o valor inteiro de N, validar para que N não seja superior a 50) (peso 0,2) 
2 – Localizar valor (usuário informa um determinado valor e o sistema procura se este valor pertence 
ao  vetor  VG  caso  pertencer exibe a mensagem: “Valor X, pertence ao vetor VG e está no endereço de 
memória xxxxxx”,  e deverá ser incluído no Vetor VE.  
Caso não existir no vetor VG o valor informado, deve ser exibido a mensagem: “Não pertence ao vetor” e 
este número deverá ser incluído no vetor VN . 
Caso  em  algum  momento  o  vetor  “VE  ou  VN”  estiverem  cheios  (todas  as  posições  ocupadas)  e  for 
necessário  fazer  mais  uma  inclusão  nestes  vetores,  deverá  ser  eliminado  todos  os  elementos  destes 
vetores para então possibilitar a inclusão do valor consultado. (peso 0,8) 
3 – Mostrar elementos dos três vetores VG, VE e VN - (peso 0,2) 
4  -  Deverá criar um arquivo texto chamado “chutes.txt” mantendo  somente  a  última  versão  no 
arquivo texto, o qual contém em cada linha do arquivo os dados na ordem conforme struct apresentada: 
(peso 0,8) 
 
struct chutes 
{ 
int num; 
string vetor; 
int pos; 
}; 
E gravadas no arquivo separado por um ponto e vírgula, conforme exemplo: 
12;VE;3 
25;VN;0 
20;VE;4 
  
OBS:  as  opções  2  e  3  só  poderão  ser  executada  se  a  opção  1  foi  acionada,  a  opção  4  só  poderão  ser 
executada se a opção 2 foi executada pelo menos uma vez. Ao escolher opção inválida no menu deverá 
exibir mensagem, com tal informação. 
Os vetores só podem ser percorridos usando aritmética de ponteiros*/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <cstring>
#include <cmath>
#include <iomanip>

using namespace std;

int *lerQuantidade();
int *lerN(int *qtdd);
void localizarValor(
    int *VG,
    int *VE,
    int *VN,
    int *qtdd,
    int *ocupadosVE,
    int *ocupadosVN
);

int main()
{
    int menu;

    int *qtdd = NULL;

    int *VG = NULL;
    int *VE = NULL;
    int *VN = NULL;

    int *locVE = new int;
    int *locVN = new int;

    *locVE = 0;
    *locVN = 0;

    do
    {
        cout << "\n***** MENU DE OPCOES *****" << endl;
        cout << "\n0 - Sair";
        cout << "\n1 - Gerar valores para os vetores";
        cout << "\n2 - Localizar valor";
        cout << "\n3 - Mostrar elementos dos tres vetores";
        cout << "\n4 - Criar arquivo chutes.txt";
        cout << "\n\nOpcao: ";

        cin >> menu;

        switch(menu)
        {
            case 0:
            {
                cout << "\nEncerrando programa...\n";
                break;
            }

            case 1:
            {
                cout << "\nGerando vetores...\n";

                qtdd = lerQuantidade(); // Lê a quantidade de posições para os vetores
                int *N = lerN(qtdd);

                VG = new int[*qtdd]; // Aloca dinamicamente o vetor VG com a quantidade de posições definida pelo usuário
                VE = new int[*qtdd]; // Aloca dinamicamente o vetor VE com a quantidade de posições definida pelo usuário
                VN = new int[*qtdd]; // Aloca dinamicamente o vetor VN com a quantidade de posições definida pelo usuário

                cout << "\nVetores alocados com sucesso!\n";

                break;
            }

            case 2:
            {
                if (VG == NULL){ // Verifica se os vetores foram gerados antes de tentar localizar um valor
                    cout << "Vetores não foram gerados, favor executar opção 1 primeiro" << endl;
                    break;
                }
                localizarValor(VG, VE, VN, qtdd, locVE, locVN); // Chama a função para localizar um valor e atualizar os vetores VE e VN
                break;
            }

            default:
            {
                cout << "\nOpcao invalida!\n";
            }
        }

    } while(menu != 0);

    if (VG != NULL)
        delete[] VG;

    if (VE != NULL)
        delete[] VE;

    if (VN != NULL)
        delete[] VN;

    return 0;
}

int *lerQuantidade()
{
    int *qtdd = new int;

    do
    {
        cout << "\nQuantidade de posicoes (10 a 20): ";
        cin >> *qtdd;

        if (*qtdd < 10 || *qtdd > 20)
        {
            cout << "Valor invalido!\n";
        }

    } while(*qtdd < 10 || *qtdd > 20);

    return qtdd;
}

int *lerN(int *qtdd){
    int *N = new int;
    do {
        cout << "Informe N (máximo 50)";
        cin >> *N;

        if (*N > 50 || *N < *qtdd){
            cout << "Valor inválido, tente novamente" << endl;
        } 
    } while (*N > 50 || *N < *qtdd);
    return N;
}

void localizarValor(
    int *VG,
    int *VE,
    int *VN,
    int *qtdd,
    int *ocupadosVE,
    int *ocupadosVN
)
{
    int *valor = new int;
    bool *encontrou = new bool;

    *encontrou = false;

    cout << "Informe um valor: ";
    cin >> *valor;

    for(int *i = new int(0); *i < *qtdd; (*i)++)
    {
        if(*(VG + *i) == *valor)
        {
            *encontrou = true;

            cout << "Valor " << *valor << " pertence ao vetor VG e esta no endereco " << (VG + *i) << endl;

            break;
        }
    }

    if(*encontrou)  
    {
        if(*ocupadosVE == *qtdd)
        {
            for(int *i = new int(0); *i < *qtdd; (*i)++)
            {
                *(VE + *i) = 0;
            }

            *ocupadosVE = 0;
        }

        *(VE + *ocupadosVE) = *valor;
        (*ocupadosVE)++;
    }
    else
    {
        cout << "Nao pertence ao vetor" << endl;

        if(*ocupadosVN == *qtdd)
        {
            for(int *i = new int(0); *i < *qtdd; (*i)++)
            {
                *(VN + *i) = 0;
            }

            *ocupadosVN = 0;
        }

        *(VN + *ocupadosVN) = *valor;
        (*ocupadosVN)++;
    }

    delete valor;
    delete encontrou;
}